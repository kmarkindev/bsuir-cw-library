#include "AuthorMySqlRepository.h"

AuthorMySqlRepository::AuthorMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void AuthorMySqlRepository::FindAuthorById(unsigned long long id,
    std::function<void(RepoQueryResult, std::vector<Author>*)>&& callback)
{
    _dbClient->execSqlAsync("SELECT * FROM authors WHERE id = ? LIMIT 1", [callback](const drogon::orm::Result& res)
    {
        std::vector<Author> result;
        if(res.empty())
        {
            callback({true, ""}, &result);
        }
        else
        {
            auto row = res[0];
            result.emplace_back(row["id"].as<unsigned long long>(), row["name"].as<std::string>());
            callback({true, ""}, &result);
        }
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()}, nullptr);
    }, id);
}

void AuthorMySqlRepository::FilterAuthorsByName(const std::string& name, bool sortAsc,
    std::function<void(RepoQueryResult, std::vector<Author>*)>&& callback)
{
    std::string orderBy = sortAsc ? "ASC" : "DESC";
    std::string wrappedName = '%' + name + '%';

    std::string query = "SELECT * FROM authors WHERE name LIKE ? ORDER BY id ASC";
    if(!sortAsc)
        query = "SELECT * FROM authors WHERE name LIKE ? ORDER BY id DESC";

    _dbClient->execSqlAsync(query, [callback](const drogon::orm::Result& res) {
        std::vector<Author> result;
        result.reserve(res.size());

        for(const auto& row : res)
            result.emplace_back(row["id"].as<unsigned long long>(), row["name"].as<std::string>());

        callback({true, ""}, &result);
    }, [callback](const drogon::orm::DrogonDbException& ex) {
        callback({false, ex.base().what()}, nullptr);
    }, wrappedName, orderBy);
}

void AuthorMySqlRepository::InsertAuthor(const Author& author,
    std::function<void(RepoQueryResult, unsigned long long)>&& callback)
{
    InsertRecord<const std::string&>(_dbClient, "authors", callback, {"name"}, author.GetName());
}

void AuthorMySqlRepository::UpdateAuthor(const Author& author, std::function<void(RepoQueryResult)>&& callback)
{
    if(!author.HasId())
        throw std::invalid_argument("Нельзя обновить автора без Id");

    UpdateRecord<const std::string&>(_dbClient, "authors", author.GetId(), callback, {"name"}, author.GetName());
}

void AuthorMySqlRepository::DeleteAuthor(unsigned long long id, std::function<void(RepoQueryResult)>&& callback)
{
    DeleteRecord(_dbClient, "authors", id, callback);
}
