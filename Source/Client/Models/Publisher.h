#pragma once

#include <numbers>
#include <string>
#include <optional>
#include <nlohmann/json.hpp>

class Publisher
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;

    Publisher() = default;

    explicit Publisher(const nlohmann::json& json)
    {
        if(json.contains("id") && json["id"].is_number())
            id = json["id"];
        if(json.contains("name") && json["name"].is_string())
            name = json["name"];
    }

    nlohmann::json ToJson() const
    {
        nlohmann::json json;
        if(id.has_value())
            json["id"] = id.value();
        if(name.has_value())
            json["name"] = name.value();
        return json;
    }

    static std::string GetPath()
    {
        return "/api/v1/publishers";
    }
};