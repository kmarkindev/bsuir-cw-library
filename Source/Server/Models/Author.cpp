#include "Author.h"

Author::Author(std::string name)
{
    SetId(0);
    SetName(std::move(name));
}

Author::Author(unsigned long long int id, std::string name)
{
    SetId(id);
    SetName(std::move(name));
}

Author::Author(const Json::Value& json)
{
    SetId(0);

    Author::FillFromJson(json, true);
}

Author::Author(const drogon::orm::Row& row)
{
    SetId(0);

    Author::FillFromRow(row, true);
}

Json::Value Author::ToJson() const
{
    Json::Value json;

    if(_id > 0)
        json["id"] = _id;

    json["name"] = _name;

    return json;
}

void Author::FillFromJson(const Json::Value& json, bool checkFields)
{
    std::string name;
    unsigned long long id;

    bool hasName = json.isMember("name");
    bool hasId = json.isMember("id");

    if(hasName)
        name = json["name"].asString();
    if(hasId)
        id = json["id"].asUInt64();

    FillFields(
        hasName ? &name : nullptr,
        hasId ? &id : nullptr,
        checkFields
    );
}

void Author::FillFromRow(const drogon::orm::Row& row, bool checkFields)
{
    std::string name;
    unsigned long long id;

    bool hasName = !row["name"].isNull();
    bool hasId = !row["id"].isNull();

    if(hasName)
        name = row["name"].as<std::string>();
    if(hasId)
        id = row["id"].as<unsigned long long>();

    FillFields(
        hasName ? &name : nullptr,
        hasId ? &id : nullptr,
        checkFields
    );
}

void Author::FillFields(std::string* name, unsigned long long int* id, bool checkFields)
{
    if(checkFields)
        if(!name)
            throw std::invalid_argument("Имя обязательно для заполнения");

    if(name)
        SetName(*name);
    if(id)
        SetId(*id);
}

void Author::SetId(unsigned long long int id)
{
    _id = id;
}

unsigned long long Author::GetId() const
{
    return _id;
}

void Author::SetName(std::string name)
{
    if(name.empty())
        throw std::invalid_argument("Имя не может быть пустым");

    if(name.size() > 32)
        throw std::invalid_argument("Имя не может быть длинее 32 символов");

    _name = std::move(name);
}

const std::string& Author::GetName() const
{
    return _name;
}

bool Author::HasId() const
{
    return _id > 0;
}

