#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api::v1
{
    class Ping : public drogon::HttpController<Ping>
    {
    public:
        METHOD_LIST_BEGIN
        METHOD_ADD(Ping::PingServer, "", Get);
        METHOD_LIST_END

        void PingServer(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
    };
}
