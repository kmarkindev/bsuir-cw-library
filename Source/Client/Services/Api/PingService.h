#pragma once

#include <Services/HttpClient/HttpClient.h>
#include <Dto/AppConfig.h>

class PingService
{
public:
    PingService(AppConfig config);

    bool IsApiUp() const;

private:
    AppConfig _config;
};
