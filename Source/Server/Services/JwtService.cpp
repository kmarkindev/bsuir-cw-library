#include "JwtService.h"

JwtService::JwtService(std::string_view secret)
    : _secret(secret), _verifier(jwt::verify()
        .allow_algorithm(jwt::algorithm::hs256{_secret})
        .with_issuer("auth"))
{
}

std::string JwtService::GenerateToken()
{
    auto token = jwt::create<jwt::picojson_traits>()
        .set_issuer("auth")
        .set_type("JWS")
        .set_id(std::to_string(std::time(nullptr)))
        .sign(jwt::algorithm::hs256{_secret});

    return token;
}

bool JwtService::ValidateToken(const std::string& token)
{
    try
    {
        auto decoded = jwt::decode<jwt::picojson_traits>(token);
        _verifier.verify(decoded);
    }
    catch(const std::exception& ex)
    {
        return false;
    }

    return true;
}