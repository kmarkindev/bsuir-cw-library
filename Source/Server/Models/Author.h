#pragma once

#include <string>
#include <json/json.h>
#include <stdexcept>

class Author
{
public:
    explicit Author(std::string name);
    explicit Author(unsigned long long id, std::string name);
    explicit Author(const Json::Value& json);

    [[nodiscard]] Json::Value ToJson() const;
    void FillFromJson(const Json::Value& json);

    void SetId(unsigned long long id);
    [[nodiscard]] unsigned long long GetId() const;
    void SetName(std::string name);
    [[nodiscard]] const std::string& GetName() const;

private:
    unsigned long long _id;
    std::string _name;
};
