#pragma once

#include "IModel.h"

class Publisher : public IModel
{
public:
    explicit Publisher(std::string name);
    explicit Publisher(unsigned long long id, std::string name);
    explicit Publisher(const Json::Value& json);
    explicit Publisher(const drogon::orm::Row& row);

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
