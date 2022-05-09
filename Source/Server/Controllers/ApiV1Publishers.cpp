#include "ApiV1Publishers.h"

api::v1::Publishers::Publishers()
    : _publishersRepository(app().getDbClient())
{

}

void api::v1::Publishers::GetPublisher(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
    std::uint64_t publisherId)
{
    try
    {
        _publishersRepository.FindPublisherById(publisherId, [callback](RepoQueryResult res,
            std::vector<drogon_model::bsuir_library::Publishers>* publishers)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(publishers->empty())
                callback(GetErrorResponse("Издатель не найден", 404));
            else
                callback(GetJsonModelResponseFrom((*publishers)[0]));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Publishers::GetPublishers(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    try
    {
        _publishersRepository.GetPublishers([callback](RepoQueryResult res,
            std::vector<drogon_model::bsuir_library::Publishers>* publishers)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            callback(GetJsonCollectionResponseFrom(*publishers));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Publishers::CreatePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    try
    {
        drogon_model::bsuir_library::Publishers publisher(*json);

        _publishersRepository.InsertPublisher(publisher, [callback, publisher](RepoQueryResult res,
            std::uint64_t insertedId) mutable
        {
            if(res.isSuccess)
            {
                publisher.setId(insertedId);
                callback(GetJsonModelResponseFrom(publisher));
            }
            else
            {
                callback(GetErrorResponse(res.error, 500));
            }
        });
    }
    catch(std::invalid_argument& ex)
    {
        callback(GetErrorResponse(ex.what(), 400));
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Publishers::UpdatePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t publisherId)
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    if(json->isMember("id"))
    {
        callback(GetErrorResponse("Изменение Id издателя невозможно", 400));
        return;
    }

    try
    {
        _publishersRepository.FindPublisherById(publisherId, [callback, json, this](RepoQueryResult res,
            std::vector<drogon_model::bsuir_library::Publishers>* publishers)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(publishers->empty())
            {
                callback(GetErrorResponse("Издатель не найден", 404));
                return;
            }

            auto publisher = (*publishers)[0];
            publisher.updateByJson(*json);
            _publishersRepository.UpdatePublisher(publisher, [callback, publisher](RepoQueryResult res) {
                if(!res.isSuccess)
                    callback(GetErrorResponse(res.error, 500));
                else
                    callback(GetJsonModelResponseFrom(publisher));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Publishers::DeletePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t publisherId)
{
    try
    {
        _publishersRepository.FindPublisherById(publisherId, [callback, this](RepoQueryResult res,
            std::vector<drogon_model::bsuir_library::Publishers>* publishers)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(publishers->empty())
            {
                callback(GetErrorResponse("Издатель не найден", 404));
                return;
            }

            auto publisher = (*publishers)[0];
            _publishersRepository.DeletePublisher(*publisher.getId(), [callback, publisher](RepoQueryResult res) {
                if(!res.isSuccess)
                    callback(GetErrorResponse(res.error, 500));
                else
                    callback(GetJsonModelResponseFrom(publisher));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}