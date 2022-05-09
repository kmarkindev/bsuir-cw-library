#pragma once

#include <string>
#include <jwt-cpp/jwt.h>
#include <jwt-cpp/base.h>

class JwtService
{
public:
    explicit JwtService(std::string_view secret);

    std::string GenerateToken();
    bool ValidateToken(const std::string& token);

private:
    std::string _secret;
    jwt::verifier<jwt::default_clock, jwt::traits::kazuho_picojson> _verifier;
};


