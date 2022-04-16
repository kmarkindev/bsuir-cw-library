#include "ApiV1Authors.h"

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

    callback(drogon::HttpResponse::newHttpResponse());
}

void api::v1::Authors::UpdateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{

    callback(drogon::HttpResponse::newHttpResponse());
}