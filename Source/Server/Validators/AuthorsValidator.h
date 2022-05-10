#pragma once

#include "IValidator.h"
#include <Models/Authors.h>

class AuthorsValidator : public IValidator<drogon_model::bsuir_library::Authors>
{
public:
    void ValidateForCreation(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    void CommonChecks(const drogon_model::bsuir_library::Authors& model, std::vector<std::string>& errors);
};