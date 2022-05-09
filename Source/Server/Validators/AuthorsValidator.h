#pragma once

#include "IValidator.h"
#include <Models/Authors.h>

class AuthorsValidator : public IValidator<drogon_model::bsuir_library::Authors>
{
public:
    void ValidateForCreation(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(Errors)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(Errors)>& callback) noexcept override;
};