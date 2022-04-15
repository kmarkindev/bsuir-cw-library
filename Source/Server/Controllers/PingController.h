#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace ApiServer
{
    class PingController : public drogon::HttpController<PingController>
    {
    public:
        METHOD_LIST_BEGIN
        ADD_METHOD_TO(PingController::Ping, "/ping", Get);
        METHOD_LIST_END

        void Ping(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
    };
}
