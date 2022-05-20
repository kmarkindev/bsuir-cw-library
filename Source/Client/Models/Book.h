#pragma once

#include <numbers>
#include <string>
#include <optional>
#include "BookInstance.h"
#include <vector>

class Book
{
    std::optional<std::uint64_t> id;
    std::optional<std::string> name;
    std::optional<std::uint64_t> authorId;
    std::optional<std::uint64_t> publisherId;
    std::optional<std::string> publishedAt;
    std::optional<std::string> fileStoragePath;
    std::optional<std::string> fileExtension;
};