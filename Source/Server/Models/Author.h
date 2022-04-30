#pragma once

#include "IModel.h"

class Author : public IModel
{
public:
    explicit Author(std::string name);
    explicit Author(unsigned long long id, std::string name);
    explicit Author(const Json::Value& json);
    explicit Author(const drogon::orm::Row& row);

    [[nodiscard]] Json::Value ToJson() const override;
    void FillFromJson(const Json::Value& json, bool checkFields) override;

    void FillFromRow(const drogon::orm::Row& row, bool checkFields) override;

    [[nodiscard]] bool HasId() const;
    void SetId(unsigned long long id);
    [[nodiscard]] unsigned long long GetId() const;
    void SetName(std::string name);
    [[nodiscard]] const std::string& GetName() const;

private:
    unsigned long long _id;
    std::string _name;

    void FillFields(std::string* name, unsigned long long* id, bool checkFields);
};
