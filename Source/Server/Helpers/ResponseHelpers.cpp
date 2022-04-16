#include "ResponseHelpers.h"

drogon::HttpResponsePtr GetErrorResponse(std::string error, int code)
{
    auto json = Json::Value();
    json["error_message"] = error;

    auto response = drogon::HttpResponse::newHttpJsonResponse(json);
    response->setStatusCode(static_cast<drogon::HttpStatusCode>(code));

    return response;
}