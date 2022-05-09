#pragma once

#include <vector>
#include <string>

template<typename ModelType>
class IValidator
{
public:

    using Errors = std::vector<std::string>;

    virtual Errors ValidateForCreation(const ModelType& model) noexcept
    {
        return {};
    }

    virtual Errors ValidateForUpdate(const ModelType& model) noexcept
    {
        return {};
    }

    virtual Errors ValidateForDelete(const ModelType& model) noexcept
    {
        return {};
    }

};