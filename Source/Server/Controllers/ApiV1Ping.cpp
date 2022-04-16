#include "ApiV1Ping.h"

void api::v1::Ping::PingServer(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto response = HttpResponse::newHttpResponse();
    response->setStatusCode(k200OK);
    callback(response);
}