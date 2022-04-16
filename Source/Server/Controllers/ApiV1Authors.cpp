#include "ApiV1Authors.h"

api::v1::Authors::Authors()
    : _authorsRepository(app().getDbClient())
{

}

void api::v1::Authors::GetAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
    unsigned long long authorId)
{

    callback(drogon::HttpResponse::newHttpResponse());
}

void api::v1::Authors::GetAuthors(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{

    callback(drogon::HttpResponse::newHttpResponse());
}

void api::v1::Authors::CreateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json = req->getJsonObject();

    if(!json)
    {
        auto response = drogon::HttpResponse::newHttpResponse();
        response->setBody("No json found");
        callback(response);
        return;
    }

    try
    {
        Author author(*json);

        _authorsRepository.InsertAuthor(author, [callback, author](bool success,
            std::string error, unsigned long long insertedId)
        {
            auto authorNew = Author(author);
            if(success)
            {
                authorNew.SetId(insertedId);
                callback(HttpResponse::newHttpJsonResponse(authorNew.ToJson()));
            }
            else
            {
                callback(GetErrorResponse(std::move(error), 400));
            }
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 400));
    }
}

void api::v1::Authors::UpdateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{

    callback(drogon::HttpResponse::newHttpResponse());
}