#pragma once

#include <numbers>
#include <string>
#include <optional>
#include <chrono>
#include <nlohmann/json.hpp>
#include <Helpers/DateParser.h>

class BookWithdraw
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::uint64_t> bookInstanceId;
    std::optional<std::uint64_t> readerId;
    std::optional<std::chrono::time_point<std::chrono::system_clock>> withdrawnAt;
    std::optional<std::chrono::time_point<std::chrono::system_clock>> returnAt;

    BookWithdraw() = default;

    explicit BookWithdraw(const nlohmann::json& json)
    {
        if(json["id"].is_number())
            id = json["id"];
        if(json["book_instance_id"].is_number())
            bookInstanceId = json["name"];
        if(json["reader_id"].is_number())
            readerId = json["reader_id"];
        if(json["withdrawn_at"].is_string())
            withdrawnAt = ParseTime(to_string(json["withdrawn_at"]));
        if(json["return_at"].is_string())
            returnAt = ParseTime(to_string(json["return_at"]));
    }
};