#pragma once

#include <vector>
#include <string>
#include <functional>

template<typename ModelType>
class IValidator
{
public:

    virtual void ValidateForCreation(const ModelType& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept
    {
        callback({});
    }

    virtual void ValidateForUpdate(const ModelType& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept
    {
        callback({});
    }

    virtual void ValidateForDelete(const ModelType& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept
    {
        callback({});
    }

};