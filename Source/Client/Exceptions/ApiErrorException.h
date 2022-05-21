#pragma once

#include <stdexcept>
#include <nlohmann/json.hpp>
#include <string>

class ApiErrorException : public std::exception
{
public:
    ApiErrorException(nlohmann::json body);
    std::string GetErrorMessage() const;
    std::vector<std::string> GetDetails() const;
private:
    nlohmann::json _json;
};
