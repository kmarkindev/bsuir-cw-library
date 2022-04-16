/**
 *
 *  Books.cc
 *  DO NOT EDIT. This file is generated by drogon_ctl
 *
 */

#include "Books.h"
#include <drogon/utils/Utilities.h>
#include <string>

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::bsuir_library;

const std::string Books::Cols::_id = "id";
const std::string Books::Cols::_name = "name";
const std::string Books::Cols::_author_id = "author_id";
const std::string Books::Cols::_publisher_id = "publisher_id";
const std::string Books::Cols::_published_at = "published_at";
const std::string Books::Cols::_file_storage_path = "file_storage_path";
const std::string Books::primaryKeyName = "id";
const bool Books::hasPrimaryKey = true;
const std::string Books::tableName = "books";

const std::vector<typename Books::MetaData> Books::metaData_={
{"id","uint64_t","bigint unsigned",8,1,1,1},
{"name","std::string","varchar(64)",64,0,0,0},
{"author_id","uint64_t","bigint unsigned",8,0,0,0},
{"publisher_id","uint64_t","bigint unsigned",8,0,0,0},
{"published_at","::trantor::Date","date",0,0,0,0},
{"file_storage_path","std::string","varchar(255)",255,0,0,0}
};
const std::string &Books::getColumnName(size_t index) noexcept(false)
{
    assert(index < metaData_.size());
    return metaData_[index].colName_;
}
Books::Books(const Row &r, const ssize_t indexOffset) noexcept
{
    if(indexOffset < 0)
    {
        if(!r["id"].isNull())
        {
            id_=std::make_shared<uint64_t>(r["id"].as<uint64_t>());
        }
        if(!r["name"].isNull())
        {
            name_=std::make_shared<std::string>(r["name"].as<std::string>());
        }
        if(!r["author_id"].isNull())
        {
            authorId_=std::make_shared<uint64_t>(r["author_id"].as<uint64_t>());
        }
        if(!r["publisher_id"].isNull())
        {
            publisherId_=std::make_shared<uint64_t>(r["publisher_id"].as<uint64_t>());
        }
        if(!r["published_at"].isNull())
        {
            auto daysStr = r["published_at"].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            publishedAt_=std::make_shared<::trantor::Date>(t*1000000);
        }
        if(!r["file_storage_path"].isNull())
        {
            fileStoragePath_=std::make_shared<std::string>(r["file_storage_path"].as<std::string>());
        }
    }
    else
    {
        size_t offset = (size_t)indexOffset;
        if(offset + 6 > r.size())
        {
            LOG_FATAL << "Invalid SQL result for this model";
            return;
        }
        size_t index;
        index = offset + 0;
        if(!r[index].isNull())
        {
            id_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 1;
        if(!r[index].isNull())
        {
            name_=std::make_shared<std::string>(r[index].as<std::string>());
        }
        index = offset + 2;
        if(!r[index].isNull())
        {
            authorId_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 3;
        if(!r[index].isNull())
        {
            publisherId_=std::make_shared<uint64_t>(r[index].as<uint64_t>());
        }
        index = offset + 4;
        if(!r[index].isNull())
        {
            auto daysStr = r[index].as<std::string>();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            publishedAt_=std::make_shared<::trantor::Date>(t*1000000);
        }
        index = offset + 5;
        if(!r[index].isNull())
        {
            fileStoragePath_=std::make_shared<std::string>(r[index].as<std::string>());
        }
    }

}

Books::Books(const Json::Value &pJson, const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        dirtyFlag_[0] = true;
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            authorId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[2]].asUInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            publisherId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[3]].asUInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[4]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            publishedAt_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            fileStoragePath_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
}

Books::Books(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        dirtyFlag_[0]=true;
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1]=true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("author_id"))
    {
        dirtyFlag_[2]=true;
        if(!pJson["author_id"].isNull())
        {
            authorId_=std::make_shared<uint64_t>((uint64_t)pJson["author_id"].asUInt64());
        }
    }
    if(pJson.isMember("publisher_id"))
    {
        dirtyFlag_[3]=true;
        if(!pJson["publisher_id"].isNull())
        {
            publisherId_=std::make_shared<uint64_t>((uint64_t)pJson["publisher_id"].asUInt64());
        }
    }
    if(pJson.isMember("published_at"))
    {
        dirtyFlag_[4]=true;
        if(!pJson["published_at"].isNull())
        {
            auto daysStr = pJson["published_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            publishedAt_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("file_storage_path"))
    {
        dirtyFlag_[5]=true;
        if(!pJson["file_storage_path"].isNull())
        {
            fileStoragePath_=std::make_shared<std::string>(pJson["file_storage_path"].asString());
        }
    }
}

void Books::updateByMasqueradedJson(const Json::Value &pJson,
                                            const std::vector<std::string> &pMasqueradingVector) noexcept(false)
{
    if(pMasqueradingVector.size() != 6)
    {
        LOG_ERROR << "Bad masquerading vector";
        return;
    }
    if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
    {
        if(!pJson[pMasqueradingVector[0]].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[0]].asUInt64());
        }
    }
    if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
    {
        dirtyFlag_[1] = true;
        if(!pJson[pMasqueradingVector[1]].isNull())
        {
            name_=std::make_shared<std::string>(pJson[pMasqueradingVector[1]].asString());
        }
    }
    if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
    {
        dirtyFlag_[2] = true;
        if(!pJson[pMasqueradingVector[2]].isNull())
        {
            authorId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[2]].asUInt64());
        }
    }
    if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
    {
        dirtyFlag_[3] = true;
        if(!pJson[pMasqueradingVector[3]].isNull())
        {
            publisherId_=std::make_shared<uint64_t>((uint64_t)pJson[pMasqueradingVector[3]].asUInt64());
        }
    }
    if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
    {
        dirtyFlag_[4] = true;
        if(!pJson[pMasqueradingVector[4]].isNull())
        {
            auto daysStr = pJson[pMasqueradingVector[4]].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            publishedAt_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
    {
        dirtyFlag_[5] = true;
        if(!pJson[pMasqueradingVector[5]].isNull())
        {
            fileStoragePath_=std::make_shared<std::string>(pJson[pMasqueradingVector[5]].asString());
        }
    }
}

void Books::updateByJson(const Json::Value &pJson) noexcept(false)
{
    if(pJson.isMember("id"))
    {
        if(!pJson["id"].isNull())
        {
            id_=std::make_shared<uint64_t>((uint64_t)pJson["id"].asUInt64());
        }
    }
    if(pJson.isMember("name"))
    {
        dirtyFlag_[1] = true;
        if(!pJson["name"].isNull())
        {
            name_=std::make_shared<std::string>(pJson["name"].asString());
        }
    }
    if(pJson.isMember("author_id"))
    {
        dirtyFlag_[2] = true;
        if(!pJson["author_id"].isNull())
        {
            authorId_=std::make_shared<uint64_t>((uint64_t)pJson["author_id"].asUInt64());
        }
    }
    if(pJson.isMember("publisher_id"))
    {
        dirtyFlag_[3] = true;
        if(!pJson["publisher_id"].isNull())
        {
            publisherId_=std::make_shared<uint64_t>((uint64_t)pJson["publisher_id"].asUInt64());
        }
    }
    if(pJson.isMember("published_at"))
    {
        dirtyFlag_[4] = true;
        if(!pJson["published_at"].isNull())
        {
            auto daysStr = pJson["published_at"].asString();
            struct tm stm;
            memset(&stm,0,sizeof(stm));
            strptime(daysStr.c_str(),"%Y-%m-%d",&stm);
            time_t t = mktime(&stm);
            publishedAt_=std::make_shared<::trantor::Date>(t*1000000);
        }
    }
    if(pJson.isMember("file_storage_path"))
    {
        dirtyFlag_[5] = true;
        if(!pJson["file_storage_path"].isNull())
        {
            fileStoragePath_=std::make_shared<std::string>(pJson["file_storage_path"].asString());
        }
    }
}

const uint64_t &Books::getValueOfId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(id_)
        return *id_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Books::getId() const noexcept
{
    return id_;
}
void Books::setId(const uint64_t &pId) noexcept
{
    id_ = std::make_shared<uint64_t>(pId);
    dirtyFlag_[0] = true;
}
const typename Books::PrimaryKeyType & Books::getPrimaryKey() const
{
    assert(id_);
    return *id_;
}

const std::string &Books::getValueOfName() const noexcept
{
    const static std::string defaultValue = std::string();
    if(name_)
        return *name_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Books::getName() const noexcept
{
    return name_;
}
void Books::setName(const std::string &pName) noexcept
{
    name_ = std::make_shared<std::string>(pName);
    dirtyFlag_[1] = true;
}
void Books::setName(std::string &&pName) noexcept
{
    name_ = std::make_shared<std::string>(std::move(pName));
    dirtyFlag_[1] = true;
}
void Books::setNameToNull() noexcept
{
    name_.reset();
    dirtyFlag_[1] = true;
}

const uint64_t &Books::getValueOfAuthorId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(authorId_)
        return *authorId_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Books::getAuthorId() const noexcept
{
    return authorId_;
}
void Books::setAuthorId(const uint64_t &pAuthorId) noexcept
{
    authorId_ = std::make_shared<uint64_t>(pAuthorId);
    dirtyFlag_[2] = true;
}
void Books::setAuthorIdToNull() noexcept
{
    authorId_.reset();
    dirtyFlag_[2] = true;
}

const uint64_t &Books::getValueOfPublisherId() const noexcept
{
    const static uint64_t defaultValue = uint64_t();
    if(publisherId_)
        return *publisherId_;
    return defaultValue;
}
const std::shared_ptr<uint64_t> &Books::getPublisherId() const noexcept
{
    return publisherId_;
}
void Books::setPublisherId(const uint64_t &pPublisherId) noexcept
{
    publisherId_ = std::make_shared<uint64_t>(pPublisherId);
    dirtyFlag_[3] = true;
}
void Books::setPublisherIdToNull() noexcept
{
    publisherId_.reset();
    dirtyFlag_[3] = true;
}

const ::trantor::Date &Books::getValueOfPublishedAt() const noexcept
{
    const static ::trantor::Date defaultValue = ::trantor::Date();
    if(publishedAt_)
        return *publishedAt_;
    return defaultValue;
}
const std::shared_ptr<::trantor::Date> &Books::getPublishedAt() const noexcept
{
    return publishedAt_;
}
void Books::setPublishedAt(const ::trantor::Date &pPublishedAt) noexcept
{
    publishedAt_ = std::make_shared<::trantor::Date>(pPublishedAt.roundDay());
    dirtyFlag_[4] = true;
}
void Books::setPublishedAtToNull() noexcept
{
    publishedAt_.reset();
    dirtyFlag_[4] = true;
}

const std::string &Books::getValueOfFileStoragePath() const noexcept
{
    const static std::string defaultValue = std::string();
    if(fileStoragePath_)
        return *fileStoragePath_;
    return defaultValue;
}
const std::shared_ptr<std::string> &Books::getFileStoragePath() const noexcept
{
    return fileStoragePath_;
}
void Books::setFileStoragePath(const std::string &pFileStoragePath) noexcept
{
    fileStoragePath_ = std::make_shared<std::string>(pFileStoragePath);
    dirtyFlag_[5] = true;
}
void Books::setFileStoragePath(std::string &&pFileStoragePath) noexcept
{
    fileStoragePath_ = std::make_shared<std::string>(std::move(pFileStoragePath));
    dirtyFlag_[5] = true;
}
void Books::setFileStoragePathToNull() noexcept
{
    fileStoragePath_.reset();
    dirtyFlag_[5] = true;
}

void Books::updateId(const uint64_t id)
{
    id_ = std::make_shared<uint64_t>(id);
}

const std::vector<std::string> &Books::insertColumns() noexcept
{
    static const std::vector<std::string> inCols={
        "name",
        "author_id",
        "publisher_id",
        "published_at",
        "file_storage_path"
    };
    return inCols;
}

void Books::outputArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAuthorId())
        {
            binder << getValueOfAuthorId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getPublisherId())
        {
            binder << getValueOfPublisherId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPublishedAt())
        {
            binder << getValueOfPublishedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getFileStoragePath())
        {
            binder << getValueOfFileStoragePath();
        }
        else
        {
            binder << nullptr;
        }
    }
}

const std::vector<std::string> Books::updateColumns() const
{
    std::vector<std::string> ret;
    if(dirtyFlag_[1])
    {
        ret.push_back(getColumnName(1));
    }
    if(dirtyFlag_[2])
    {
        ret.push_back(getColumnName(2));
    }
    if(dirtyFlag_[3])
    {
        ret.push_back(getColumnName(3));
    }
    if(dirtyFlag_[4])
    {
        ret.push_back(getColumnName(4));
    }
    if(dirtyFlag_[5])
    {
        ret.push_back(getColumnName(5));
    }
    return ret;
}

void Books::updateArgs(drogon::orm::internal::SqlBinder &binder) const
{
    if(dirtyFlag_[1])
    {
        if(getName())
        {
            binder << getValueOfName();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[2])
    {
        if(getAuthorId())
        {
            binder << getValueOfAuthorId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[3])
    {
        if(getPublisherId())
        {
            binder << getValueOfPublisherId();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[4])
    {
        if(getPublishedAt())
        {
            binder << getValueOfPublishedAt();
        }
        else
        {
            binder << nullptr;
        }
    }
    if(dirtyFlag_[5])
    {
        if(getFileStoragePath())
        {
            binder << getValueOfFileStoragePath();
        }
        else
        {
            binder << nullptr;
        }
    }
}
Json::Value Books::toJson() const
{
    Json::Value ret;
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getAuthorId())
    {
        ret["author_id"]=(Json::UInt64)getValueOfAuthorId();
    }
    else
    {
        ret["author_id"]=Json::Value();
    }
    if(getPublisherId())
    {
        ret["publisher_id"]=(Json::UInt64)getValueOfPublisherId();
    }
    else
    {
        ret["publisher_id"]=Json::Value();
    }
    if(getPublishedAt())
    {
        ret["published_at"]=getPublishedAt()->toDbStringLocal();
    }
    else
    {
        ret["published_at"]=Json::Value();
    }
    if(getFileStoragePath())
    {
        ret["file_storage_path"]=getValueOfFileStoragePath();
    }
    else
    {
        ret["file_storage_path"]=Json::Value();
    }
    return ret;
}

Json::Value Books::toMasqueradedJson(
    const std::vector<std::string> &pMasqueradingVector) const
{
    Json::Value ret;
    if(pMasqueradingVector.size() == 6)
    {
        if(!pMasqueradingVector[0].empty())
        {
            if(getId())
            {
                ret[pMasqueradingVector[0]]=(Json::UInt64)getValueOfId();
            }
            else
            {
                ret[pMasqueradingVector[0]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[1].empty())
        {
            if(getName())
            {
                ret[pMasqueradingVector[1]]=getValueOfName();
            }
            else
            {
                ret[pMasqueradingVector[1]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[2].empty())
        {
            if(getAuthorId())
            {
                ret[pMasqueradingVector[2]]=(Json::UInt64)getValueOfAuthorId();
            }
            else
            {
                ret[pMasqueradingVector[2]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[3].empty())
        {
            if(getPublisherId())
            {
                ret[pMasqueradingVector[3]]=(Json::UInt64)getValueOfPublisherId();
            }
            else
            {
                ret[pMasqueradingVector[3]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[4].empty())
        {
            if(getPublishedAt())
            {
                ret[pMasqueradingVector[4]]=getPublishedAt()->toDbStringLocal();
            }
            else
            {
                ret[pMasqueradingVector[4]]=Json::Value();
            }
        }
        if(!pMasqueradingVector[5].empty())
        {
            if(getFileStoragePath())
            {
                ret[pMasqueradingVector[5]]=getValueOfFileStoragePath();
            }
            else
            {
                ret[pMasqueradingVector[5]]=Json::Value();
            }
        }
        return ret;
    }
    LOG_ERROR << "Masquerade failed";
    if(getId())
    {
        ret["id"]=(Json::UInt64)getValueOfId();
    }
    else
    {
        ret["id"]=Json::Value();
    }
    if(getName())
    {
        ret["name"]=getValueOfName();
    }
    else
    {
        ret["name"]=Json::Value();
    }
    if(getAuthorId())
    {
        ret["author_id"]=(Json::UInt64)getValueOfAuthorId();
    }
    else
    {
        ret["author_id"]=Json::Value();
    }
    if(getPublisherId())
    {
        ret["publisher_id"]=(Json::UInt64)getValueOfPublisherId();
    }
    else
    {
        ret["publisher_id"]=Json::Value();
    }
    if(getPublishedAt())
    {
        ret["published_at"]=getPublishedAt()->toDbStringLocal();
    }
    else
    {
        ret["published_at"]=Json::Value();
    }
    if(getFileStoragePath())
    {
        ret["file_storage_path"]=getValueOfFileStoragePath();
    }
    else
    {
        ret["file_storage_path"]=Json::Value();
    }
    return ret;
}

bool Books::validateJsonForCreation(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, true))
            return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, true))
            return false;
    }
    if(pJson.isMember("author_id"))
    {
        if(!validJsonOfField(2, "author_id", pJson["author_id"], err, true))
            return false;
    }
    if(pJson.isMember("publisher_id"))
    {
        if(!validJsonOfField(3, "publisher_id", pJson["publisher_id"], err, true))
            return false;
    }
    if(pJson.isMember("published_at"))
    {
        if(!validJsonOfField(4, "published_at", pJson["published_at"], err, true))
            return false;
    }
    if(pJson.isMember("file_storage_path"))
    {
        if(!validJsonOfField(5, "file_storage_path", pJson["file_storage_path"], err, true))
            return false;
    }
    return true;
}
bool Books::validateMasqueradedJsonForCreation(const Json::Value &pJson,
                                               const std::vector<std::string> &pMasqueradingVector,
                                               std::string &err)
{
    if(pMasqueradingVector.size() != 6)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty())
      {
          if(pJson.isMember(pMasqueradingVector[0]))
          {
              if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[1].empty())
      {
          if(pJson.isMember(pMasqueradingVector[1]))
          {
              if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[2].empty())
      {
          if(pJson.isMember(pMasqueradingVector[2]))
          {
              if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[3].empty())
      {
          if(pJson.isMember(pMasqueradingVector[3]))
          {
              if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[4].empty())
      {
          if(pJson.isMember(pMasqueradingVector[4]))
          {
              if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, true))
                  return false;
          }
      }
      if(!pMasqueradingVector[5].empty())
      {
          if(pJson.isMember(pMasqueradingVector[5]))
          {
              if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, true))
                  return false;
          }
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Books::validateJsonForUpdate(const Json::Value &pJson, std::string &err)
{
    if(pJson.isMember("id"))
    {
        if(!validJsonOfField(0, "id", pJson["id"], err, false))
            return false;
    }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
    if(pJson.isMember("name"))
    {
        if(!validJsonOfField(1, "name", pJson["name"], err, false))
            return false;
    }
    if(pJson.isMember("author_id"))
    {
        if(!validJsonOfField(2, "author_id", pJson["author_id"], err, false))
            return false;
    }
    if(pJson.isMember("publisher_id"))
    {
        if(!validJsonOfField(3, "publisher_id", pJson["publisher_id"], err, false))
            return false;
    }
    if(pJson.isMember("published_at"))
    {
        if(!validJsonOfField(4, "published_at", pJson["published_at"], err, false))
            return false;
    }
    if(pJson.isMember("file_storage_path"))
    {
        if(!validJsonOfField(5, "file_storage_path", pJson["file_storage_path"], err, false))
            return false;
    }
    return true;
}
bool Books::validateMasqueradedJsonForUpdate(const Json::Value &pJson,
                                             const std::vector<std::string> &pMasqueradingVector,
                                             std::string &err)
{
    if(pMasqueradingVector.size() != 6)
    {
        err = "Bad masquerading vector";
        return false;
    }
    try {
      if(!pMasqueradingVector[0].empty() && pJson.isMember(pMasqueradingVector[0]))
      {
          if(!validJsonOfField(0, pMasqueradingVector[0], pJson[pMasqueradingVector[0]], err, false))
              return false;
      }
    else
    {
        err = "The value of primary key must be set in the json object for update";
        return false;
    }
      if(!pMasqueradingVector[1].empty() && pJson.isMember(pMasqueradingVector[1]))
      {
          if(!validJsonOfField(1, pMasqueradingVector[1], pJson[pMasqueradingVector[1]], err, false))
              return false;
      }
      if(!pMasqueradingVector[2].empty() && pJson.isMember(pMasqueradingVector[2]))
      {
          if(!validJsonOfField(2, pMasqueradingVector[2], pJson[pMasqueradingVector[2]], err, false))
              return false;
      }
      if(!pMasqueradingVector[3].empty() && pJson.isMember(pMasqueradingVector[3]))
      {
          if(!validJsonOfField(3, pMasqueradingVector[3], pJson[pMasqueradingVector[3]], err, false))
              return false;
      }
      if(!pMasqueradingVector[4].empty() && pJson.isMember(pMasqueradingVector[4]))
      {
          if(!validJsonOfField(4, pMasqueradingVector[4], pJson[pMasqueradingVector[4]], err, false))
              return false;
      }
      if(!pMasqueradingVector[5].empty() && pJson.isMember(pMasqueradingVector[5]))
      {
          if(!validJsonOfField(5, pMasqueradingVector[5], pJson[pMasqueradingVector[5]], err, false))
              return false;
      }
    }
    catch(const Json::LogicError &e)
    {
      err = e.what();
      return false;
    }
    return true;
}
bool Books::validJsonOfField(size_t index,
                             const std::string &fieldName,
                             const Json::Value &pJson,
                             std::string &err,
                             bool isForCreation)
{
    switch(index)
    {
        case 0:
            if(pJson.isNull())
            {
                err="The " + fieldName + " column cannot be null";
                return false;
            }
            if(isForCreation)
            {
                err="The automatic primary key cannot be set";
                return false;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 1:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 64)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 64)";
                return false;
            }

            break;
        case 2:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 3:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isUInt64())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 4:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            break;
        case 5:
            if(pJson.isNull())
            {
                return true;
            }
            if(!pJson.isString())
            {
                err="Type error in the "+fieldName+" field";
                return false;
            }
            // asString().length() creates a string object, is there any better way to validate the length?
            if(pJson.isString() && pJson.asString().length() > 255)
            {
                err="String length exceeds limit for the " +
                    fieldName +
                    " field (the maximum value is 255)";
                return false;
            }

            break;
        default:
            err="Internal error in the server";
            return false;
            break;
    }
    return true;
}
