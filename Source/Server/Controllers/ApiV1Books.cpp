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

    // Do not allow setting path and extension from request since we'll generate it ourselves
    if(json->isMember("file_storage_path"))
        json->removeMember("file_storage_path");
    if(json->isMember("file_extension"))
        json->removeMember("file_extension");

    drogon_model::bsuir_library::Books book(*json);

    _validator.ValidateForCreation(book, [callback, book, json = *json, this](auto errors) mutable
    {
        if(!errors.empty())
        {
            callback(GetValidatonErrorResponse(errors));
            return;
        }

        if(json.isMember("file"))
        {
            book.setFileStoragePath(_fileStorageService.SaveFileToStorage(json["file"]["content"].as<std::string>()));
            book.setFileExtension(json["file"]["extension"].as<std::string>());
        }

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
                        book.setFileExtensionToNull();
                    }
                }
                else
                {
                    if(book.getFileStoragePath())
                        _fileStorageService.ReplaceFileInStorage(json["file"]["content"].as<std::string>(), book.getValueOfFileStoragePath());
                    else
                        book.setFileStoragePath(_fileStorageService.SaveFileToStorage(json["file"]["content"].as<std::string>()));

                    book.setFileExtension(json["file"]["extension"].as<std::string>());
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

        auto fileName = model.getValueOfName() + "." + model.getValueOfFileExtension();

        std::string filePath = _fileStorageService.GetFilePathFromStorage(model.getValueOfFileStoragePath());
        auto response = HttpResponse::newFileResponse(filePath, fileName);
        response->addHeader("file-ext", model.getValueOfFileExtension());
        callback(response);
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
         callback(GetErrorResponseFromException(ex));
    });
}

void api::v1::Books::DeleteBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
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

void api::v1::Books::GetInstances(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t id)
{
    _modelMapper.findByPrimaryKey(id, [callback, this](auto model) mutable
    {
        _instancesMapper.findBy(orm::Criteria("book_id", orm::CompareOperator::EQ, model.getValueOfId()),
        [callback, this](auto instances)
        {
            Json::Value result;
            result["data"] = Json::arrayValue;

            if(instances.size() == 0)
            {
                callback(GetJsonResponse(result, 200));
                return;
            }

            std::vector<std::uint64_t> instanceIds;
            instanceIds.reserve(instances.size());
            for(const auto& inst : instances)
                instanceIds.push_back(inst.getValueOfId());

            _withdrawsMapper.findBy(orm::Criteria("book_instance_id", orm::CompareOperator::In, instanceIds),
            [callback, instances](std::vector<drogon_model::bsuir_library::BookWithdraws> withdraws)
            {
                Json::Value result;
                result["data"] = Json::arrayValue;

                for(const auto& inst : instances)
                {
                    const drogon_model::bsuir_library::BookWithdraws* matchWithdraw = nullptr;
                    for(const auto& withdraw : withdraws)
                    {
                        if(withdraw.getValueOfBookInstanceId() == inst.getValueOfId())
                        {
                            matchWithdraw = &withdraw;
                            break;
                        }
                    }

                    Json::Value obj;
                    obj["instance"] = inst.toJson();
                    obj["withdraw"] = matchWithdraw != nullptr ? matchWithdraw->toJson() : Json::nullValue;

                    result["data"].append(obj);
                }

                callback(GetJsonResponse(result, 200));
            },
            [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });
        },
        [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}

void api::v1::Books::CreateInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
try
{
    drogon_model::bsuir_library::BookInstances instance;
    instance.setBookId(id);

    _bookInstanceValidator.ValidateForCreation(instance, [callback, instance, this](auto errors)
    {
        if(!errors.empty())
        {
            callback(GetValidatonErrorResponse(errors));
            return;
        }

        _instancesMapper.insert(instance, [callback](auto model)
        {
            callback(GetJsonModelResponseFrom(model));
        },
        [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}

void api::v1::Books::DeleteInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
{
    _instancesMapper.findByPrimaryKey(id, [callback, this](auto inst)
    {
        _bookInstanceValidator.ValidateForDelete(inst, [callback, inst, this](auto errors)
        {
            if(!errors.empty())
            {
                callback(GetValidatonErrorResponse(errors));
                return;
            }

            _instancesMapper.deleteByPrimaryKey(inst.getValueOfId(), [callback, inst](auto count)
            {
                callback(GetJsonModelResponseFrom(inst));
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

void api::v1::Books::WithdrawInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
try
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    drogon_model::bsuir_library::BookWithdraws withdraw;
    if(json->isMember("reader_id"))
        withdraw.setReaderId((*json)["reader_id"].as<std::uint64_t>());
    if(json->isMember("return_at"))
        withdraw.setReturnAt(TrantorDateFromString((*json)["return_at"].as<std::string>()));
    withdraw.setBookInstanceId(id);
    withdraw.setWithdrawnAt(trantor::Date::date());

    _bookWithdrawValidator.ValidateForCreation(withdraw, [callback, withdraw, this](auto errors)
    {
        if(!errors.empty())
        {
            callback(GetValidatonErrorResponse(errors));
            return;
        }

        _withdrawsMapper.insert(withdraw, [callback](auto withdraw)
        {
            callback(GetJsonModelResponseFrom(withdraw));
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

void api::v1::Books::ReturnInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id)
{
    _withdrawsMapper.findOne(orm::Criteria("book_instance_id", orm::CompareOperator::EQ, id),
    [callback, this](auto withdraw)
    {
        _bookWithdrawValidator.ValidateForDelete(withdraw, [callback, withdraw, this](auto errors)
        {
            if(!errors.empty())
            {
                callback(GetValidatonErrorResponse(errors));
                return;
            }

            _withdrawsMapper.deleteByPrimaryKey(withdraw.getValueOfId(), [callback, withdraw](auto count)
            {
                callback(GetJsonModelResponseFrom(withdraw));
            }, [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });
        });
    },
    [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}

api::v1::Books::Books()
    : _fileStorageService(app().getCustomConfig()["storage_path"].as<std::string>()),
      _instancesMapper(app().getDbClient()),
      _withdrawsMapper(app().getDbClient())
{

}

void api::v1::Books::GetAllInstances(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    _instancesMapper.findAll([callback, this](auto instances)
    {
        Json::Value result;
        result["data"] = Json::arrayValue;

        if(instances.size() == 0)
        {
            callback(GetJsonResponse(result, 200));
            return;
        }

        std::vector<std::uint64_t> instanceIds;
        instanceIds.reserve(instances.size());
        for(const auto& inst : instances)
            instanceIds.push_back(inst.getValueOfId());

        _withdrawsMapper.findBy(orm::Criteria("book_instance_id", orm::CompareOperator::In, instanceIds),
            [callback, instances](std::vector<drogon_model::bsuir_library::BookWithdraws> withdraws)
            {
                Json::Value result;
                result["data"] = Json::arrayValue;

                for(const auto& inst : instances)
                {
                    const drogon_model::bsuir_library::BookWithdraws* matchWithdraw = nullptr;
                    for(const auto& withdraw : withdraws)
                    {
                        if(withdraw.getValueOfBookInstanceId() == inst.getValueOfId())
                        {
                            matchWithdraw = &withdraw;
                            break;
                        }
                    }

                    Json::Value obj;
                    obj["instance"] = inst.toJson();
                    obj["withdraw"] = matchWithdraw != nullptr ? matchWithdraw->toJson() : Json::nullValue;

                    result["data"].append(obj);
                }

                callback(GetJsonResponse(result, 200));
            },
            [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}