#pragma once

#include <numbers>
#include <string>
#include <optional>
#include "BookInstance.h"
#include <vector>
#include <chrono>
#include <nlohmann/json.hpp>
#include <Helpers/DateParser.h>

class Book
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;
    std::optional<std::uint64_t> authorId;
    std::optional<std::uint64_t> publisherId;
    std::optional<std::chrono::time_point<std::chrono::system_clock>> publishedAt;
    std::optional<std::string> fileStoragePath;
    std::optional<std::string> fileExtension;

    Book() = default;

    explicit Book(const nlohmann::json& json)
    {
        if(json.contains("id") && json["id"].is_number())
            id = json["id"];
        if(json.contains("name") && json["name"].is_string())
            name = json["name"];
        if(json.contains("author_id") && json["author_id"].is_number())
            authorId = json["author_id"];
        if(json.contains("publisher_id") && json["publisher_id"].is_number())
            publisherId = json["publisher_id"];
        if(json.contains("published_at") && json["published_at"].is_string())
        {
            std::string str = json["published_at"];
            publishedAt = ParseTime(str);
        }
        if(json.contains("file_storage_path") && json["file_storage_path"].is_string())
            fileStoragePath = json["file_storage_path"];
        if(json.contains("file_extension") && json["file_extension"].is_string())
            fileExtension = json["file_extension"];
    }

    nlohmann::json ToJson() const
    {
        nlohmann::json json;
        if(id.has_value())
            json["id"] = id.value();
        if(name.has_value())
            json["name"] = name.value();
        if(authorId.has_value())
            json["author_id"] = authorId.value();
        if(publisherId.has_value())
            json["publisher_id"] = publisherId.value();
        if(publishedAt.has_value())
            json["published_at"] = RenderTimeString(publishedAt.value());
        if(fileStoragePath.has_value())
            json["file_storage_path"] = fileStoragePath.value();
        if(fileExtension.has_value())
            json["file_extension"] = fileExtension.value();
        return json;
    }

    static std::string GetPath()
    {
        return "/api/v1/books";
    }
};