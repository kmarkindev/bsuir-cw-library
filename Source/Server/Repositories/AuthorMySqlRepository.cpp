#include "AuthorMySqlRepository.h"

#include <utility>

AuthorMySqlRepository::AuthorMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void AuthorMySqlRepository::FindAuthorById(unsigned long long id,
    std::function<void(bool, std::string, std::vector<Author>*)>&& callback)
{
    _dbClient->execSqlAsync("SELECT * FROM authors WHERE id = ? LIMIT 1", [callback](const drogon::orm::Result& res)
    {
        std::vector<Author> result;
        if(res.empty())
        {
            callback(true, "", &result);
        }
        else
        {
            auto row = res[0];
            result.emplace_back(row["id"].as<unsigned long long>(), row["name"].as<std::string>());
            callback(true, "", &result);
        }
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(false, ex.base().what(), nullptr);
    }, id);
}

void AuthorMySqlRepository::FilterAuthorsByName(std::string_view name, bool sortAsc,
    std::function<void(bool, std::string, std::vector<Author>*)>&& callback)
{
    //TODO:
    callback(false, "", nullptr);
}

void AuthorMySqlRepository::InsertAuthor(const Author& author, std::function<void(bool, std::string, unsigned long long)>&& callback)
{
    _dbClient->execSqlAsync("INSERT INTO authors(name) VALUES (?)", [callback](const drogon::orm::Result& res)
    {
        callback(true, "", res.insertId());
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback(false, ex.base().what(), 0);
    }, author.GetName());
}