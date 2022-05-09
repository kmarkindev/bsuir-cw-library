#include "PublisherMySqlRepository.h"

PublisherMySqlRepository::PublisherMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void PublisherMySqlRepository::FindPublisherById(std::uint64_t id,
    std::function<void(RepoQueryResult, std::vector<Publishers>*)>&& callback)
{
    FindRecordById(_dbClient, "publishers", id, callback);
}

void PublisherMySqlRepository::GetPublishers(
    std::function<void(RepoQueryResult, std::vector<Publishers>*)>&& callback)
{
    GetRecords(_dbClient, "publishers", callback);
}

void PublisherMySqlRepository::InsertPublisher(const Publishers& publisher,
    std::function<void(RepoQueryResult, std::uint64_t)>&& callback)
{
    if(!publisher.getName())
        throw std::invalid_argument("Нельзя создать издателя без имени");

    InsertRecord(_dbClient, "publishers", callback, {"name"}, *publisher.getName());
}

void PublisherMySqlRepository::UpdatePublisher(const Publishers& publisher,
    std::function<void(RepoQueryResult)>&& callback)
{
    if(!publisher.getId())
        throw std::invalid_argument("Нельзя обновить издателя без Id");

    if(!publisher.getName())
        throw std::invalid_argument("Имя не может быть NULL");

    UpdateRecord(_dbClient, "publishers", *publisher.getId(), callback, {"name"}, *publisher.getName());
}

void PublisherMySqlRepository::DeletePublisher(std::uint64_t id,
    std::function<void(RepoQueryResult)>&& callback)
{
    DeleteRecord(_dbClient, "publishers", id, callback);
}
