#pragma once

#include <drogon/drogon.h>
#include <Services/JwtService.h>
#include <Helpers/ResponseHelpers.h>

using namespace drogon;

class AuthFilter : public drogon::HttpFilter<AuthFilter>
{
public:

    explicit AuthFilter();
    virtual void doFilter(const HttpRequestPtr &req, FilterCallback &&fcb, FilterChainCallback &&fccb) override;

private:
    JwtService _jwtService;
};


