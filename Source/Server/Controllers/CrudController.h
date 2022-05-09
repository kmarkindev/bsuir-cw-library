#pragma once

#include "drogon/drogon.h"
#include "drogon/orm/Mapper.h"
#include "Helpers/ResponseHelpers.h"

using namespace drogon;

template<typename ModelType>
class CrudController
{
public:

    explicit CrudController()
        : _modelMapper(app().getDbClient())
    {

    }

    void GetOne(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
        std::uint64_t id)
    {
        _modelMapper.findByPrimaryKey(id, [callback](ModelType model) mutable
        {
            callback(GetJsonModelResponseFrom(model));
        }, [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    }

    void GetAll(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
    {
        _modelMapper.findAll([callback](std::vector<ModelType> models) mutable
        {
            callback(GetJsonCollectionResponseFrom(models));
        }, [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    }

    void Create(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
    try
    {
        //TODO: validate json for creation

        auto json = req->getJsonObject();

        if(!json)
        {
            callback(GetNoJsonErrorResponse());
            return;
        }

        ModelType model(*json);

        _modelMapper.insert(model, [callback](ModelType model) mutable
        {
            callback(GetJsonModelResponseFrom(model));
        }, [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponseFromException(ex));
    }

    void Update(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
        std::uint64_t id)
    try
    {
        //TODO: validate json for update

        auto json = req->getJsonObject();

        if(!json)
        {
            callback(GetNoJsonErrorResponse());
            return;
        }

        _modelMapper.findByPrimaryKey(id, [callback, json = *json, this](ModelType model) mutable
        {
            model.updateByJson(json);
            _modelMapper.update(model, [callback, model](auto updatedCount) mutable
            {
                callback(GetJsonModelResponseFrom(model));
            }, [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });

        }, [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponseFromException(ex));
    }

    void Delete(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
        std::uint64_t id)
    try
    {
        //TODO: validate for delete

        _modelMapper.findByPrimaryKey(id, [callback, this](auto model) mutable
        {
            _modelMapper.deleteByPrimaryKey(*model.getId(), [callback, model](auto deletedCount) mutable
            {
                callback(GetJsonModelResponseFrom(model));
            }, [callback](const drogon::orm::DrogonDbException& ex)
            {
                callback(GetErrorResponseFromException(ex));
            });

        }, [callback](const drogon::orm::DrogonDbException& ex)
        {
            callback(GetErrorResponseFromException(ex));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponseFromException(ex));
    }

protected:
    drogon::orm::Mapper<ModelType> _modelMapper;
};