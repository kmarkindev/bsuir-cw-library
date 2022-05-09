#pragma once

#include <drogon/HttpController.h>
#include <Services/JwtService.h>
#include <Helpers/ResponseHelpers.h>

using namespace drogon;

namespace api::v1
{
    class Auth : public drogon::HttpController<Auth>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Auth::Login, "", HttpMethod::Post);
        METHOD_LIST_END

        explicit Auth();

        void Login(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);

    private:
        JwtService _jwtService;
        std::string _password;
    };
}



