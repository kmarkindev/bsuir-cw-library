#pragma once

#include <Models/Author.h>
#include <vector>
#include <functional>
#include <drogon/orm/DbClient.h>
#include <Helpers/DbClientHelper.h>
#include <utility>
#include <Dto/RepoQueryResult.h>

class AuthorMySqlRepository
{
public:
    explicit AuthorMySqlRepository(drogon::orm::DbClientPtr dbClient);

    [[nodiscard]] void FindAuthorById(unsigned long long id,
        std::function<void(RepoQueryResult, std::vector<Author>*)>&& callback);
    [[nodiscard]] void FilterAuthorsByName(const std::string& name,
        bool sortAsc, std::function<void(RepoQueryResult, std::vector<Author>*)>&& callback);
    void InsertAuthor(const Author& author, std::function<void(RepoQueryResult, unsigned long long)>&& callback);
    void UpdateAuthor(const Author& author, std::function<void(RepoQueryResult)>&& callback);
    void DeleteAuthor(unsigned long long id, std::function<void(RepoQueryResult)>&& callback);
private:
    drogon::orm::DbClientPtr _dbClient;
};
