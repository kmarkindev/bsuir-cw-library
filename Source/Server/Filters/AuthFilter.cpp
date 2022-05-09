#include "AuthFilter.h"

AuthFilter::AuthFilter()
    : _jwtService(app().getCustomConfig()["jwt_secret"].as<std::string>())
{

}

void AuthFilter::doFilter(const HttpRequestPtr& req, FilterCallback&& fcb, FilterChainCallback&& fccb)
{
    auto iter = req->headers().find("jwt-token");

    if(iter == req->headers().end())
    {
        fcb(GetErrorResponse("Отсутствует заголовок jwt-token", 400));
        return;
    }

    if(!_jwtService.ValidateToken(iter->second))
    {
        fcb(GetErrorResponse("Указан недействительный jwt токен", 403));
        return;
    }

    fccb();
}
