#pragma once

#include <numbers>
#include <string>
#include <optional>

class Reader
{
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;
    std::optional<std::string> address;
    std::optional<std::string> birthday;
    std::optional<bool> sex;
    std::optional<std::string> phone;
    std::optional<std::string> email;
};