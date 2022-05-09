#pragma once

#include <drogon/drogon.h>
#include <json/json.h>
#include <vector>

inline drogon::HttpResponsePtr GetErrorResponse(const std::string& error, int code)
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

inline drogon::HttpResponsePtr GetNoJsonErrorResponse()
{
    return GetErrorResponse("JSON не найден в запросе", 400);
}

template<typename ModelType>
inline drogon::HttpResponsePtr GetJsonCollectionResponseFrom(const std::vector<ModelType>& collection)
{
    Json::Value result;
    result["data"] = Json::arrayValue;

    for(const auto& model : collection)
        result["data"].append(model.toJson());

    return drogon::HttpResponse::newHttpJsonResponse(result);
}

template<typename ModelType>
inline drogon::HttpResponsePtr GetJsonModelResponseFrom(const ModelType& model)
{
    Json::Value result;
    result["data"] = model.toJson();

    return drogon::HttpResponse::newHttpJsonResponse(result);
}

inline drogon::HttpResponsePtr GetErrorResponseFromException(const std::exception& ex)
{
    std::string message = ex.what();

    if(message == "0 rows found")
        return GetErrorResponse("Запись не найдена", 404);

    return GetErrorResponse(message, 500);
}

inline drogon::HttpResponsePtr GetErrorResponseFromException(const drogon::orm::DrogonDbException& ex)
{
    return GetErrorResponseFromException(ex.base());
}