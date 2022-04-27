#pragma once

#include <string>
#include <json/json.h>
#include <stdexcept>

class Publisher
{
public:
    explicit Publisher(std::string name);
    explicit Publisher(unsigned long long id, std::string name);
    explicit Publisher(const Json::Value& json);

    [[nodiscard]] Json::Value ToJson() const;
    void FillFromJson(const Json::Value& json, bool checkFields);

    [[nodiscard]] bool HasId() const;
    void SetId(unsigned long long id);
    [[nodiscard]] unsigned long long GetId() const;
    void SetName(std::string name);
    [[nodiscard]] const std::string& GetName() const;

private:
    unsigned long long _id;
    std::string _name;
};
