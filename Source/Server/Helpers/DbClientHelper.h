#pragma once

#include <drogon/orm/DbClient.h>
#include <Dto/RepoQueryResult.h>
#include <string>
#include <sstream>

inline void DeleteRecord(drogon::orm::DbClientPtr dbClient, const std::string& table, std::uint64_t id,
    std::function<void(RepoQueryResult)> callback)
{
    dbClient->execSqlAsync("DELETE FROM " + table + " WHERE id = ?", [callback](const drogon::orm::Result& res)
    {
        callback({true, ""});
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()});
    }, id);
}

template<typename... Values>
inline void InsertRecord(drogon::orm::DbClientPtr dbClient, const std::string& table,
    std::function<void(RepoQueryResult, std::uint64_t)> callback,
    const std::vector<std::string>& columns, Values&&... values)
{
    if(columns.empty())
        throw std::invalid_argument("Нужно указать хотя бы один столбец");
    if(columns.size() != sizeof...(values))
        throw std::invalid_argument("Кол-во столбцов и значений не совпадает");

    // Concat columns
    std::stringstream ss;
    for(const auto& col : columns)
        ss << col << ',';
    std::string columnNames = ss.str();
    columnNames.pop_back();
    ss.str("");

    // Concat values places
    for(size_t i = 0; i < sizeof...(values); ++i)
        ss << "?,";
    std::string valuesPlaces = ss.str();
    valuesPlaces.pop_back();

    dbClient->execSqlAsync("INSERT INTO " + table + "(" + columnNames + ") VALUES (" + valuesPlaces + ")",
        [callback](const drogon::orm::Result& res)
    {
        callback({true, ""}, res.insertId());
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()}, 0);
    }, values...);
}

template<typename... Values>
inline void UpdateRecord(drogon::orm::DbClientPtr dbClient, const std::string& table, std::uint64_t id,
    std::function<void(RepoQueryResult)> callback,
    const std::vector<std::string>& columns, Values&&... values)
{
    if(columns.empty())
        throw std::invalid_argument("Нужно указать хотя бы один столбец");
    if(columns.size() != sizeof...(values))
        throw std::invalid_argument("Кол-во столбцов и значений не совпадает");

    // Concat columns and values places
    std::stringstream ss;
    for(const auto& col : columns)
        ss << col << "=?,";
    ss.seekp(-1, std::ios_base::end);
    std::string columnsWithValuePlaces = ss.str();
    columnsWithValuePlaces.pop_back();

    dbClient->execSqlAsync("UPDATE authors SET " + columnsWithValuePlaces + " WHERE id = ?",
        [callback](const drogon::orm::Result& res)
    {
        callback({true, ""});
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()});
    }, values..., id);
}

template<typename ModelType>
inline void FindRecordById(drogon::orm::DbClientPtr dbClient, const std::string& table, std::uint64_t id,
    std::function<void(RepoQueryResult, std::vector<ModelType>*)> callback)
{
    dbClient->execSqlAsync("SELECT * FROM " + table + " WHERE id = ? LIMIT 1",
        [callback](const drogon::orm::Result& res)
    {
        std::vector<ModelType> result;
        if(res.empty())
        {
            callback({true, ""}, &result);
        }
        else
        {
            result.emplace_back(res[0]);
            callback({true, ""}, &result);
        }
    }, [callback](const drogon::orm::DrogonDbException& ex)
    {
        callback({false, ex.base().what()}, nullptr);
    }, id);
}

template<typename ModelType>
inline void GetRecords(drogon::orm::DbClientPtr dbClient, const std::string& table,
    std::function<void(RepoQueryResult, std::vector<ModelType>*)> callback)
{
    dbClient->execSqlAsync("SELECT * FROM " + table, [callback](const drogon::orm::Result& res) {
        std::vector<ModelType> result;
        result.reserve(res.size());

        for(const auto& row : res)
            result.emplace_back(row);

        callback({true, ""}, &result);
    }, [callback](const drogon::orm::DrogonDbException& ex) {
        callback({false, ex.base().what()}, nullptr);
    });
}