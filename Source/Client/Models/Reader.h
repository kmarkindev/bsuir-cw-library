#pragma once

#include <numbers>
#include <string>
#include <optional>
#include <chrono>
#include <nlohmann/json.hpp>
#include <Helpers/DateParser.h>

class Reader
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;
    std::optional<std::string> address;
    std::optional<std::chrono::time_point<std::chrono::system_clock>> birthday;
    std::optional<bool> sex;
    std::optional<std::string> phone;
    std::optional<std::string> email;

    Reader() = default;

    explicit Reader(const nlohmann::json& json)
    {
        if(json["id"].is_number())
            id = json["id"];
        if(json["name"].is_string())
            name = json["name"];
        if(json["address"].is_string())
            address = json["address"];
        if(json["birthday"].is_string())
            birthday = ParseTime(to_string(json["birthday"]));
        if(json["sex"].is_number() || json["sex"].is_boolean())
            sex = json["sex"];
        if(json["phone"].is_string())
            phone = json["phone"];
        if(json["email"].is_string())
            email = json["email"];
    }

    nlohmann::json ToJson() const
    {
        nlohmann::json json;
        if(id.has_value())
            json["id"] = id.value();
        if(name.has_value())
            json["name"] = name.value();
        if(address.has_value())
            json["address"] = address.value();
        if(birthday.has_value())
            json["birthday"] = RenderTimeString(birthday.value());
        if(sex.has_value())
            json["sex"] = sex.value();
        if(phone.has_value())
            json["phone"] = phone.value();
        if(email.has_value())
            json["email"] = email.has_value();
        return json;
    }

    static std::string GetPath()
    {
        return "/api/v1/readers";
    }
};