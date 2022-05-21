#pragma once

#include <numbers>
#include <optional>
#include <vector>
#include "BookWithdraw.h"

class BookInstance
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::uint64_t> bookId;
    std::optional<BookWithdraw> withdraw;

    BookInstance() = default;

    explicit BookInstance(const nlohmann::json& json)
    {
        if(json["id"].is_number())
            id = json["id"];
        if(json["book_id"].is_number())
            bookId = json["book_id"];
    }
};