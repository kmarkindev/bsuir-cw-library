#include "AuthorMySqlRepository.h"

#include <utility>

AuthorMySqlRepository::AuthorMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void AuthorMySqlRepository::findAuthorById(unsigned long long id,
    std::function<void(std::vector<Author>)>&& callback)
{
    callback({});
}

void AuthorMySqlRepository::filterAuthorsByName(std::string_view name, bool sortAsc,
    std::function<void(std::vector<Author>)>&& callback)
{
    callback({});
}

void AuthorMySqlRepository::InsertAuthor(const Author& author, std::function<void(bool, std::string, unsigned long long)>&& callback)
{
    _dbClient->execSqlAsync("INSERT INTO authors(name) VALUES (?)", [callback](const drogon::orm::Result& res) -> void
    {
        callback(true, "", res.insertId());
    }, [callback](const drogon::orm::DrogonDbException& ex) -> void
    {
        callback(false, ex.base().what(), 0);
    }, author.GetName());
}