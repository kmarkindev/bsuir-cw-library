#pragma once

#include <numbers>
#include <optional>
#include <vector>
#include "BookWithdraw.h"

class BookInstance
{
    std::optional<std::uint64_t> id;
    std::optional<std::uint64_t> bookId;
    std::optional<BookWithdraw> withdraw;
};