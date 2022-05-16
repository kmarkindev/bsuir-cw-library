#pragma once

#include <drogon/drogon.h>

using namespace drogon;

class IndexController : public drogon::HttpController<IndexController>
{
public:
    METHOD_LIST_BEGIN
        ADD_METHOD_TO(IndexController::Index, "/", HttpMethod::Get);
        ADD_METHOD_TO(IndexController::Client, "/client", HttpMethod::Get);
    METHOD_LIST_END

    void Index(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);
    void Client(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);

private:

    std::string indexPageHtml = R"(
        qwe
    )";

};


