#pragma once

#include <Models/Publisher.h>
#include <vector>
#include <functional>
#include <drogon/orm/DbClient.h>
#include <utility>
#include <Helpers/DbClientHelper.h>
#include <Dto/RepoQueryResult.h>

class PublisherMySqlRepository
{
public:
    explicit PublisherMySqlRepository(drogon::orm::DbClientPtr dbClient);

    [[nodiscard]] void FindPublisherById(unsigned long long id,
        std::function<void(RepoQueryResult, std::vector<Publisher>*)>&& callback);
    [[nodiscard]] void FilterPublishersByName(const std::string& name,
        bool sortAsc, std::function<void(RepoQueryResult, std::vector<Publisher>*)>&& callback);
    void InsertPublisher(const Publisher& publisher, std::function<void(RepoQueryResult, unsigned long long)>&& callback);
    void UpdatePublisher(const Publisher& publisher, std::function<void(RepoQueryResult)>&& callback);
    void DeletePublisher(unsigned long long id, std::function<void(RepoQueryResult)>&& callback);
private:
    drogon::orm::DbClientPtr _dbClient;
};
