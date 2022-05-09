#pragma once

#include <vector>
#include <string>
#include <functional>

template<typename ModelType>
class IValidator
{
public:

    using Errors = std::vector<std::string>;

    virtual void ValidateForCreation(const ModelType& model, const std::function<void(Errors)>& callback) noexcept
    {
        callback({});
    }

    virtual void ValidateForUpdate(const ModelType& model, const std::function<void(Errors)>& callback) noexcept
    {
        callback({});
    }

    virtual void ValidateForDelete(const ModelType& model, const std::function<void(Errors)>& callback) noexcept
    {
        callback({});
    }

};