#include "IndexController.h"

void IndexController::Index(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    callback(HttpResponse::newHttpViewResponse("index"));
}

void IndexController::Client(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    callback(HttpResponse::newFileResponse(app().getCustomConfig()["client_path"].as<std::string>()));
}