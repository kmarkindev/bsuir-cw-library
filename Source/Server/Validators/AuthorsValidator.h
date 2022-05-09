#pragma once

#include "IValidator.h"
#include <Models/Authors.h>

class AuthorsValidator : public IValidator<drogon_model::bsuir_library::Authors>
{
public:
    Errors ValidateForCreation(const drogon_model::bsuir_library::Authors& model) noexcept override;
    Errors ValidateForUpdate(const drogon_model::bsuir_library::Authors& model) noexcept override;
};