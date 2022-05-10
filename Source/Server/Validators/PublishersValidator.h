#pragma once

#include "IValidator.h"
#include <Models/Publishers.h>

class PublishersValidator : public IValidator<drogon_model::bsuir_library::Publishers>
{
public:
    void ValidateForCreation(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    void CommonChecks(const drogon_model::bsuir_library::Publishers& model, std::vector<std::string>& errors);
};


