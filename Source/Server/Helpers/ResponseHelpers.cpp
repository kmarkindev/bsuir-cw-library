#include "ResponseHelpers.h"

drogon::HttpResponsePtr GetErrorResponse(const std::string& error, int code)
{
    auto json = Json::Value();

#ifdef DEBUG_BUILD
    json["error_message"] = error;
#else
    if(code >= 500)
        json["error_message"] = "Упс, что то пошло не так";
    else
        json["error_message"] = error;
#endif

    auto response = drogon::HttpResponse::newHttpJsonResponse(json);
    response->setStatusCode(static_cast<drogon::HttpStatusCode>(code));

    return response;
}

drogon::HttpResponsePtr GetNoJsonErrorResponse()
{
    return GetErrorResponse("JSON не найден в запросе", 400);
}