#include "PingService.h"

PingService::PingService(AppConfig config)
    : _config(std::move(config))
{

}

bool PingService::IsApiUp() const
{
    HttpRequest request("GET", _config.apiUrl, "/api/v1/ping");
    auto response = HttpClient::Send(request);

    return response.GetCode() == 200;
}
