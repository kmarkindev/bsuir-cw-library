#pragma once

#include "IValidator.h"
#include <Models/Publishers.h>

class PublishersValidator : public IValidator<drogon_model::bsuir_library::Publishers>
{
public:
    Errors ValidateForCreation(const drogon_model::bsuir_library::Publishers& model) noexcept override;
    Errors ValidateForUpdate(const drogon_model::bsuir_library::Publishers& model) noexcept override;
};


