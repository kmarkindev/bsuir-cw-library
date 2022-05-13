#pragma once

#include "IValidator.h"
#include <Models/Readers.h>
#include <drogon/drogon.h>
#include <Models/BookWithdraws.h>

class ReadersValidator : public IValidator<drogon_model::bsuir_library::Readers>
{
public:

    ReadersValidator();

    void ValidateForCreation(const drogon_model::bsuir_library::Readers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Readers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForDelete(const drogon_model::bsuir_library::Readers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    void CommonChecks(const drogon_model::bsuir_library::Readers& model, std::vector<std::string>& errors);

    drogon::orm::Mapper<drogon_model::bsuir_library::BookWithdraws> _withdrawsMapper;
};


