#include "ApiV1Authors.h"

api::v1::Authors::Authors()
    : _authorsMapper(app().getDbClient())
{

}

void api::v1::Authors::GetAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t authorId)
{
    _authorsMapper.findByPrimaryKey(authorId, [callback](auto author)
    {
        callback(GetJsonModelResponseFrom(author));
    }, [callback](const orm::DrogonDbException& ex)
    {
       callback(GetErrorResponseFromException(ex));
    });
}

void api::v1::Authors::GetAuthors(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    _authorsMapper.findAll([callback](auto authors)
    {
        callback(GetJsonCollectionResponseFrom(authors));
    }, [callback](const orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}

void api::v1::Authors::CreateAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
try
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    drogon_model::bsuir_library::Authors author(*json);

    _authorsMapper.insert(author, [callback](auto author)
    {
        callback(GetJsonModelResponseFrom(author));
    }, [callback](const orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}

void api::v1::Authors::UpdateAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t authorId)
try
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    _authorsMapper.findByPrimaryKey(authorId, [callback, json = *json, this](auto author)
    {
        author.updateByJson(json);
        _authorsMapper.update(author, [callback, author](auto updatedCount)
        {
            callback(GetJsonModelResponseFrom(author));
        }, [callback](const orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });

    }, [callback](const orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}

void api::v1::Authors::DeleteAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    std::uint64_t authorId)
try
{
    _authorsMapper.findByPrimaryKey(authorId, [callback, this](auto author)
    {
        _authorsMapper.deleteByPrimaryKey(*author.getId(), [callback, author](auto deletedCount)
        {
            callback(GetJsonModelResponseFrom(author));
        }, [callback](const orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });

    }, [callback](const orm::DrogonDbException& ex)
    {
        callback(GetErrorResponseFromException(ex));
    });
}
catch(std::exception& ex)
{
    callback(GetErrorResponseFromException(ex));
}