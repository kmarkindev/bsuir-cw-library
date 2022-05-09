#pragma once

#include <Models/Publishers.h>
#include <vector>
#include <functional>
#include <drogon/orm/DbClient.h>
#include <utility>
#include <Helpers/DbClientHelper.h>
#include <Dto/RepoQueryResult.h>

using namespace drogon_model::bsuir_library;

class PublisherMySqlRepository
{
public:
    explicit PublisherMySqlRepository(drogon::orm::DbClientPtr dbClient);

    void FindPublisherById(std::uint64_t id,
        std::function<void(RepoQueryResult, std::vector<Publishers>*)>&& callback);
    void GetPublishers(std::function<void(RepoQueryResult, std::vector<Publishers>*)>&& callback);
    void InsertPublisher(const Publishers& publisher, std::function<void(RepoQueryResult, std::uint64_t)>&& callback);
    void UpdatePublisher(const Publishers& publisher, std::function<void(RepoQueryResult)>&& callback);
    void DeletePublisher(std::uint64_t id, std::function<void(RepoQueryResult)>&& callback);
private:
    drogon::orm::DbClientPtr _dbClient;
};
