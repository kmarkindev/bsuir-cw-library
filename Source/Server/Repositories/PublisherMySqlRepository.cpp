#include "PublisherMySqlRepository.h"

PublisherMySqlRepository::PublisherMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void PublisherMySqlRepository::FindPublisherById(unsigned long long id,
    std::function<void(RepoQueryResult, std::vector<Publisher>*)>&& callback)
{
    FindRecordById(_dbClient, "publishers", id, callback);
}

void PublisherMySqlRepository::GetPublishers(
    std::function<void(RepoQueryResult, std::vector<Publisher>*)>&& callback)
{
    GetRecords(_dbClient, "publishers", callback);
}

void PublisherMySqlRepository::InsertPublisher(const Publisher& publisher,
    std::function<void(RepoQueryResult, unsigned long long)>&& callback)
{
    InsertRecord(_dbClient, "publishers", callback, {"name"}, publisher.GetName());
}

void PublisherMySqlRepository::UpdatePublisher(const Publisher& publisher,
    std::function<void(RepoQueryResult)>&& callback)
{
    if(!publisher.HasId())
        throw std::invalid_argument("Нельзя обновить издателя без Id");

    UpdateRecord(_dbClient, "publishers", publisher.GetId(), callback, {"name"}, publisher.GetName());
}

void PublisherMySqlRepository::DeletePublisher(unsigned long long id,
    std::function<void(RepoQueryResult)>&& callback)
{
    DeleteRecord(_dbClient, "publishers", id, callback);
}
