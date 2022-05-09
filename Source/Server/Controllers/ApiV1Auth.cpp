#include "ApiV1Auth.h"

void api::v1::Auth::Login(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    auto json = req->getJsonObject();
    auto test = app().getCustomConfig();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    if(!json->isMember("password"))
    {
        callback(GetErrorResponse("Поле password обязательно", 400));
        return;
    }

    auto receivedPassword = (*json)["password"].as<std::string>();

    if(receivedPassword == _password)
    {
        Json::Value resultJson;
        resultJson["token"] = _jwtService.GenerateToken();
        callback(GetJsonResponse(resultJson, 200));
    }
    else
    {
        callback(GetErrorResponse("Указан неверный пароль", 403));
    }
}

api::v1::Auth::Auth()
    : _jwtService(app().getCustomConfig()["jwt_secret"].as<std::string>()),
    _password(app().getCustomConfig()["admin_secret"].as<std::string>())
{

}
