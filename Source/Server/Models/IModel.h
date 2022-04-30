#pragma once

#include <string>
#include <json/json.h>
#include <drogon/orm/DbClient.h>
#include <stdexcept>

class IModel
{
public:
    [[nodiscard]] virtual Json::Value ToJson() const = 0;
    virtual void FillFromJson(const Json::Value& json, bool checkFields) = 0;
    virtual void FillFromRow(const drogon::orm::Row& row, bool checkFields) = 0;
};