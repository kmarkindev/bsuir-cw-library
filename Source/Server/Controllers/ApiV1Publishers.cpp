#include "ApiV1Publishers.h"

api::v1::Publishers::Publishers()
    : _publishersRepository(app().getDbClient())
{

}

void api::v1::Publishers::GetPublisher(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
    unsigned long long publisherId)
{
    try
    {
        _publishersRepository.FindPublisherById(publisherId, [callback](RepoQueryResult res, std::vector<Publisher>* publishers){

            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(publishers->empty())
                callback(GetErrorResponse("Издатель не найден", 404));
            else
                callback(HttpResponse::newHttpJsonResponse((*publishers)[0].ToJson()));
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
        auto json = req->getJsonObject();

        //TODO: refactor this shit
        std::string name;
        std::string orderBy = "ASC";

        if(json)
        {
            name = json->get("name", "").asString();
            orderBy = json->get("order_by", "ASC").asString();
        }

        std::transform(orderBy.begin(), orderBy.end(), orderBy.begin(),
            [](auto c){ return std::tolower(c); });

        bool sortAsc = orderBy == "desc" ? false : true;

        _publishersRepository.FilterPublishersByName(name, sortAsc, [callback](RepoQueryResult res, std::vector<Publisher>* publishers) {

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
        Publisher publisher(*json);

        _publishersRepository.InsertPublisher(publisher, [callback, publisher](RepoQueryResult res,
            unsigned long long insertedId) mutable
        {
            if(res.isSuccess)
            {
                publisher.SetId(insertedId);
                callback(HttpResponse::newHttpJsonResponse(publisher.ToJson()));
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
    unsigned long long publisherId)
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
            std::vector<Publisher>* publishers)
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
            publisher.FillFromJson(*json, false);
            _publishersRepository.UpdatePublisher(publisher, [callback, publisher](RepoQueryResult res) {
                if(!res.isSuccess)
                    callback(GetErrorResponse(res.error, 500));
                else
                    callback(HttpResponse::newHttpJsonResponse(publisher.ToJson()));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Publishers::DeletePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    unsigned long long publisherId)
{
    try
    {
        _publishersRepository.FindPublisherById(publisherId, [callback, this](RepoQueryResult res,
            std::vector<Publisher>* publishers)
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
            _publishersRepository.DeletePublisher(publisher, [callback, publisher](RepoQueryResult res) {
                if(!res.isSuccess)
                    callback(GetErrorResponse(res.error, 500));
                else
                    callback(HttpResponse::newHttpJsonResponse(publisher.ToJson()));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}