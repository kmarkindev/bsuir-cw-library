#pragma once

#include "IValidator.h"
#include <Models/Readers.h>

class ReadersValidator : public IValidator<drogon_model::bsuir_library::Readers>
{
public:
    void ValidateForCreation(const drogon_model::bsuir_library::Readers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Readers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    void CommonChecks(const drogon_model::bsuir_library::Readers& model, std::vector<std::string>& errors);
};


