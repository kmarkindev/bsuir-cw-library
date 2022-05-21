#pragma once

#include <numbers>
#include <optional>
#include <vector>
#include <nlohmann/json.hpp>

class Author
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;

    explicit Author(const nlohmann::json& json)
    {
        if(json["id"].is_number())
            id = json["id"];
        if(json["name"].is_string())
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

    static constexpr std::string GetPath()
    {
        return "/api/v1/authors";
    }
};