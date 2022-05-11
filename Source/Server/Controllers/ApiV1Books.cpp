#include "ApiV1Books.h"

void api::v1::Books::CreateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
try
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    // Do not allow setting path from request since we'll generate it ourselves
    if(json->isMember("file_storage_path"))
        json->removeMember("file_storage_path");

    drogon_model::bsuir_library::Books book(*json);

    _validator.ValidateForCreation(book, [callback, book, json = *json, this](auto errors) mutable
    {
        if(!errors.empty())
        {
            callback(GetValidatonErrorResponse(errors));
            return;
        }

        if(json.isMember("file"))
            book.setFileStoragePath(_fileStorageService.SaveFileToStorage(json["file"].as<std::string>()));

        _modelMapper.insert(book, [callback](auto model) mutable
        {
            callback(GetJsonModelResponseFrom(model));
        }, [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}

void api::v1::Books::UpdateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t id)
try
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    if(json->isMember("id"))
    {
        callback(GetErrorResponse("Нельзя обновить id записи", 400));
        return;
    }

    // Do not allow setting path from request since we'll generate it ourselves
    if(json->isMember("file_storage_path"))
        json->removeMember("file_storage_path");

    _modelMapper.findByPrimaryKey(id, [callback, json = *json, this](auto book) mutable
    {
        book.updateByJson(json);

        _validator.ValidateForUpdate(book, [callback, book, json, this](auto errors) mutable
        {
            if(!errors.empty())
            {
                callback(GetValidatonErrorResponse(errors));
                return;
            }

            if(json.isMember("file"))
            {
                if(json["file"].isNull())
                {
                    if(book.getFileStoragePath())
                    {
                        _fileStorageService.RemoveFileFromStorage(book.getValueOfFileStoragePath());
                        book.setFileStoragePathToNull();
                    }
                }
                else
                {
                    if(book.getFileStoragePath())
                        _fileStorageService.ReplaceFileInStorage(json["file"].as<std::string>(), book.getValueOfFileStoragePath());
                    else
                        book.setFileStoragePath(_fileStorageService.SaveFileToStorage(json["file"].as<std::string>()));
                }
            }

            _modelMapper.update(book, [callback, book](auto updatedCount) mutable
            {
                callback(GetJsonModelResponseFrom(book));
            }, [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });
        });

    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}

void api::v1::Books::GetBookFile(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
{
    _modelMapper.findByPrimaryKey(id, [callback, this](auto model)
    {
        if(!model.getFileStoragePath())
        {
            callback(GetErrorResponse("У указанной книги нет цифровой версии", 404));
            return;
        }

        callback(HttpResponse::newFileResponse(_fileStorageService.GetFilePathFromStorage(model.getValueOfFileStoragePath())));
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
         callback(GetErrorResponseFromException(ex));
    });
}

void api::v1::Books::Delete(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
try
{
    _modelMapper.findByPrimaryKey(id, [callback, this](auto model) mutable
    {
        _validator.ValidateForDelete(model, [callback, model, this](auto errors)
        {
            if(!errors.empty())
            {
                callback(GetValidatonErrorResponse(errors));
                return;
            }

            _modelMapper.deleteByPrimaryKey(*model.getId(), [callback, model, this](auto deletedCount) mutable
            {
                if(model.getFileStoragePath())
                    _fileStorageService.RemoveFileFromStorage(model.getValueOfFileStoragePath());

                callback(GetJsonModelResponseFrom(model));
            }, [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });
        });

    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}

api::v1::Books::Books()
    : _fileStorageService(app().getCustomConfig()["storage_path"].as<std::string>())
{

}
