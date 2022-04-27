#include "ResponseHelpers.h"

drogon::HttpResponsePtr GetErrorResponse(std::string error, int code)
{
    auto json = Json::Value();
    json["error_message"] = error;

    auto response = drogon::HttpResponse::newHttpJsonResponse(json);
    response->setStatusCode(static_cast<drogon::HttpStatusCode>(code));

    return response;
}

drogon::HttpResponsePtr GetNoJsonErrorResponse()
{
    return GetErrorResponse("JSON не найдет в запросе", 400);
}

template<typename Model>
drogon::HttpResponsePtr GetJsonCollectionResponseFrom(const std::vector<Model>& collection)
{
    Json::Value result;
    result["data"] = Json::arrayValue;

    for(const auto& model : *collection)
        result["data"].append(model.ToJson());

    return drogon::HttpResponse::newHttpJsonResponse(result);
}