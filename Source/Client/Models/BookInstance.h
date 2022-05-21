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
};