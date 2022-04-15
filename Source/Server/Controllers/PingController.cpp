#include "PingController.h"

void ApiServer::PingController::Ping(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto response = HttpResponse::newHttpResponse();
    response->setStatusCode(k200OK);
    callback(response);
}