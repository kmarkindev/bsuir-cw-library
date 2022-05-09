#pragma once

#include "IValidator.h"
#include <Models/Publishers.h>

class PublishersValidator : public IValidator<drogon_model::bsuir_library::Publishers>
{
public:
    void ValidateForCreation(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(Errors)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(Errors)>& callback) noexcept override;
};


