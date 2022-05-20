#pragma once

#include <numbers>
#include <string>
#include <optional>

class BookWithdraw
{
    std::optional<std::uint64_t> id;
    std::optional<std::uint64_t> bookInstanceId;
    std::optional<std::uint64_t> readerId;
    std::optional<std::string> withdrawnAt;
    std::optional<std::string> returnAt;
};