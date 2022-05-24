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
        if(json.contains("id") && json["id"].is_number())
            id = json["id"];
        if(json.contains("book_instance_id") && json["book_instance_id"].is_number())
            bookInstanceId = json["book_instance_id"];
        if(json.contains("reader_id") && json["reader_id"].is_number())
            readerId = json["reader_id"];
        if(json.contains("withdrawn_at") && json["withdrawn_at"].is_string())
            withdrawnAt = ParseTime(json["withdrawn_at"]);
        if(json.contains("return_at") && json["return_at"].is_string())
            returnAt = ParseTime(json["return_at"]);
    }
};