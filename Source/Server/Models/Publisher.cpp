#include "Publisher.h"

Publisher::Publisher(std::string name)
{
    SetId(0);
    SetName(std::move(name));
}

Publisher::Publisher(unsigned long long int id, std::string name)
{
    SetId(id);
    SetName(std::move(name));
}

Publisher::Publisher(const Json::Value& json)
{
    SetId(0);

    FillFromJson(json, true);
}

Json::Value Publisher::ToJson() const
{
    Json::Value json;

    if(_id > 0)
        json["id"] = _id;

    json["name"] = _name;

    return json;
}

void Publisher::FillFromJson(const Json::Value& json, bool checkFields)
{
    if(checkFields)
        if(!json.isMember("name"))
            throw std::invalid_argument("Имя обязательно для заполнения");

    if(json.isMember("name"))
        SetName(json["name"].asString());

    if(json.isMember("id"))
        SetId(json["id"].asUInt64());
}

void Publisher::SetId(unsigned long long int id)
{
    _id = id;
}

unsigned long long Publisher::GetId() const
{
    return _id;
}

void Publisher::SetName(std::string name)
{
    if(name.empty())
        throw std::invalid_argument("Имя не может быть пустым");

    if(name.size() > 32)
        throw std::invalid_argument("Имя не может быть длинее 32 символов");

    _name = std::move(name);
}

const std::string& Publisher::GetName() const
{
    return _name;
}

bool Publisher::HasId() const
{
    return _id > 0;
}
