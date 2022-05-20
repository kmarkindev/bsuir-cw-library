#include "ApiErrorException.h"

ApiErrorException::ApiErrorException(nlohmann::json body)
{
    if(!body.contains("error") || !body["error"].is_string())\
        throw std::invalid_argument("Нельзя создать исключение без текста ошибки");

    _json = std::move(body);
}

std::string ApiErrorException::GetErrorMessage()
{
    return _json["error"];
}

std::vector<std::string> ApiErrorException::GetDetails()
{
    std::vector<std::string> details;

    if(_json["details"].is_array())
        for(const auto& item : _json["details"])
            details.push_back(item);

    return details;
}
