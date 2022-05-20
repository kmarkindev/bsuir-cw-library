#pragma once

#include <Dto/AppConfig.h>
#include <string>
#include <Services/HttpClient/HttpClient.h>
#include <nlohmann/json.hpp>
#include <Exceptions/ApiErrorException.h>

class AuthService
{
public:
    AuthService(AppConfig config);

    std::string LogIn(std::string_view password) const;
private:
    AppConfig _config;
};
