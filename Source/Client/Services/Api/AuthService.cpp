#include "AuthService.h"

AuthService::AuthService(AppConfig config)
    : _config(std::move(config))
{

}

std::string AuthService::LogIn(std::string_view password) const
{
    nlohmann::json requestBody;
    requestBody["password"] = password;

    HttpRequest request("POST", _config.apiUrl, "/api/v1/auth");
    request.SetBody(to_string(requestBody));

    auto response = HttpClient::Send(request);

    if(response.GetCode() != 200)
        throw ApiErrorException(response.GetBody());

    nlohmann::json responseJson = nlohmann::json::parse(response.GetBody());
    return to_string(responseJson["token"]);
}
