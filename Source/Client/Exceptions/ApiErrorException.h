#pragma once

#include <stdexcept>
#include <nlohmann/json.hpp>
#include <string>

class ApiErrorException : public std::exception
{
public:
    ApiErrorException(nlohmann::json body);
    std::string GetErrorMessage();
    std::vector<std::string> GetDetails();
private:
    nlohmann::json _json;
};
