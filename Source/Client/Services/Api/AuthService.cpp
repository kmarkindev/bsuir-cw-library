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
    request.SetBody(requestBody);

    auto response = HttpClient::Send(request);

    if(response.GetCode() != 200)
        throw ApiErrorException(response.GetBody());

    nlohmann::json responseJson = response.GetBody();
    return responseJson["token"];
}
