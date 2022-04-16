#pragma once

#include <drogon/drogon.h>
#include <json/json.h>

drogon::HttpResponsePtr GetErrorResponse(std::string error, int code);