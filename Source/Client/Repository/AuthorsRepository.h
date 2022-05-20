#pragma once

#include <Models/Author.h>
#include <Services/HttpClient/HttpClient.h>
#include <vector>

class AuthorsRepository
{
    Author GetAuthorById(std::uint64_t id);
    std::vector<Author> GetAllAuthors();
    Author CreateAuthor(const Author& author);
    Author UpdateAuthor(const Author& author);
    Author DeleteAuthor(std::uint64_t id);
};
