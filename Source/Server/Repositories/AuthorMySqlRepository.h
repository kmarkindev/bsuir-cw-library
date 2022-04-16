#pragma once

#include <Models/Author.h>
#include <vector>
#include <functional>
#include <drogon/orm/DbClient.h>

class AuthorMySqlRepository
{
public:
    explicit AuthorMySqlRepository(drogon::orm::DbClientPtr dbClient);

    [[nodiscard]] void FindAuthorById(unsigned long long id,
        std::function<void(bool, std::string, std::vector<Author>*)>&& callback);
    [[nodiscard]] void FilterAuthorsByName(std::string_view name,
        bool sortAsc, std::function<void(bool, std::string, std::vector<Author>*)>&& callback);
    void InsertAuthor(const Author& author, std::function<void(bool, std::string, unsigned long long)>&& callback);
private:
    drogon::orm::DbClientPtr _dbClient;
};
