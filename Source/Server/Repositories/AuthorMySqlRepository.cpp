#include "AuthorMySqlRepository.h"

AuthorMySqlRepository::AuthorMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void AuthorMySqlRepository::FindAuthorById(unsigned long long id,
    std::function<void(RepoQueryResult, std::vector<Author>*)>&& callback)
{
    FindRecordById(_dbClient, "authors", id, callback);
}

void AuthorMySqlRepository::GetAuthors(std::function<void(RepoQueryResult, std::vector<Author>*)>&& callback)
{
    GetRecords(_dbClient, "authors", callback);
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
