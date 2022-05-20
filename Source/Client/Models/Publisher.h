#pragma once

#include <numbers>
#include <string>
#include <optional>

class Publisher
{
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;
};