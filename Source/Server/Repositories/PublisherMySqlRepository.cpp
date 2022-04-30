#include "PublisherMySqlRepository.h"

PublisherMySqlRepository::PublisherMySqlRepository(drogon::orm::DbClientPtr dbClient)
    : _dbClient(std::move(dbClient))
{

}

void PublisherMySqlRepository::FindPublisherById(unsigned long long id,
    std::function<void(RepoQueryResult, std::vector<Publisher>*)>&& callback)
{
    _dbClient->execSqlAsync("SELECT * FROM publishers WHERE id = ? LIMIT 1", [callback](const drogon::orm::Result& res)
    {
        std::vector<Publisher> result;
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

void PublisherMySqlRepository::FilterPublishersByName(const std::string& name, bool sortAsc,
    std::function<void(RepoQueryResult, std::vector<Publisher>*)>&& callback)
{
    std::string orderBy = sortAsc ? "ASC" : "DESC";
    std::string wrappedName = '%' + name + '%';

    std::string query = "SELECT * FROM publishers WHERE name LIKE ? ORDER BY id ASC";
    if(!sortAsc)
        query = "SELECT * FROM publishers WHERE name LIKE ? ORDER BY id DESC";

    _dbClient->execSqlAsync(query, [callback](const drogon::orm::Result& res) {
        std::vector<Publisher> result;
        result.reserve(res.size());

        for(const auto& row : res)
            result.emplace_back(row["id"].as<unsigned long long>(), row["name"].as<std::string>());

        callback({true, ""}, &result);
    }, [callback](const drogon::orm::DrogonDbException& ex) {
        callback({false, ex.base().what()}, nullptr);
    }, wrappedName, orderBy);
}

void PublisherMySqlRepository::InsertPublisher(const Publisher& publisher, std::function<void(RepoQueryResult, unsigned long long)>&& callback)
{
    _dbClient->execSqlAsync("INSERT INTO publishers(name) VALUES (?)", [callback](const drogon::orm::Result& res)
    {
        callback({true, ""}, res.insertId());
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()}, 0);
    }, publisher.GetName());
}

void PublisherMySqlRepository::UpdatePublisher(const Publisher& publisher, std::function<void(RepoQueryResult)>&& callback)
{
    if(!publisher.HasId())
        throw std::invalid_argument("Нельзя обновить издателя без Id");

    _dbClient->execSqlAsync("UPDATE publishers SET name = ? WHERE id = ?", [callback](const drogon::orm::Result& res)
    {
        callback({true, ""});
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()});
    }, publisher.GetName(), publisher.GetId());
}

void PublisherMySqlRepository::DeletePublisher(const Publisher& publisher, std::function<void(RepoQueryResult)>&& callback)
{
    if(!publisher.HasId())
        throw std::invalid_argument("Нельзя удалить издателя без Id");

    _dbClient->execSqlAsync("DELETE FROM publishers WHERE id = ?", [callback](const drogon::orm::Result& res)
    {
        callback({true, ""});
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()});
    }, publisher.GetId());
}
