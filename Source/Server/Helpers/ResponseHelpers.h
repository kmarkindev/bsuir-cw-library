#pragma once

#include <drogon/drogon.h>
#include <json/json.h>
#include <vector>

drogon::HttpResponsePtr GetErrorResponse(const std::string& error, int code);

drogon::HttpResponsePtr GetNoJsonErrorResponse();

template<typename ModelType>
drogon::HttpResponsePtr GetJsonCollectionResponseFrom(const std::vector<ModelType>& collection)
{
    Json::Value result;
    result["data"] = Json::arrayValue;

    for(const auto& model : collection)
        result["data"].append(model.ToJson());

    return drogon::HttpResponse::newHttpJsonResponse(result);
}