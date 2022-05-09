#pragma once

#include "drogon/drogon.h"
#include "drogon/orm/Mapper.h"
#include "Helpers/ResponseHelpers.h"
#include <Validators/IValidator.h>

using namespace drogon;

template<typename ModelType, typename ModelValidator = IValidator<ModelType>>
class CrudController
{
public:

    explicit CrudController()
        : _modelMapper(app().getDbClient()),
        _validator()
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
        auto json = req->getJsonObject();

        if(!json)
        {
            callback(GetNoJsonErrorResponse());
            return;
        }

        ModelType model(*json);

        auto errors = _validator.ValidateForCreation(model);
        if(!errors.empty())
        {
            callback(GetValidatonErrorResponse(errors));
            return;
        }

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
        auto json = req->getJsonObject();

        if(!json)
        {
            callback(GetNoJsonErrorResponse());
            return;
        }

        if(json->isMember("id"))
        {
            callback(GetErrorResponse("Нельзя обновить id записи", 400));
            return;
        }

        _modelMapper.findByPrimaryKey(id, [callback, json = *json, this](ModelType model) mutable
        {
            model.updateByJson(json);

            auto errors = _validator.ValidateForUpdate(model);
            if(!errors.empty())
            {
                callback(GetValidatonErrorResponse(errors));
                return;
            }

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
        _modelMapper.findByPrimaryKey(id, [callback, this](auto model) mutable
        {
            auto errors = _validator.ValidateForDelete(model);
            if(!errors.empty())
            {
                callback(GetValidatonErrorResponse(errors));
                return;
            }

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
    ModelValidator _validator;
};