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
    request.GetHeaders().SetHeader({"Content-Type", "application/json"});
    auto body = to_string(requestBody);
    request.SetBody(body);

    auto response = HttpClient::Send(request);
    auto json = nlohmann::json::parse(response.GetBody());

    if(response.GetCode() != 200)
        throw ApiErrorException(json);

    return json["token"];
}
