#pragma once

#include <numbers>
#include <string>
#include <optional>
#include <chrono>

class BookWithdraw
{
public:
    std::optional<std::uint64_t> id;
    std::optional<std::uint64_t> bookInstanceId;
    std::optional<std::uint64_t> readerId;
    std::optional<std::chrono::time_point<std::chrono::system_clock>> withdrawnAt;
    std::optional<std::chrono::time_point<std::chrono::system_clock>> returnAt;
};