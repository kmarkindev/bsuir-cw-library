#pragma once

#include "IValidator.h"
#include <Models/Publishers.h>
#include <Models/Books.h>
#include <drogon/drogon.h>

class PublishersValidator : public IValidator<drogon_model::bsuir_library::Publishers>
{
public:
    PublishersValidator();

    void ValidateForCreation(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForDelete(const drogon_model::bsuir_library::Publishers& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    drogon::orm::Mapper<drogon_model::bsuir_library::Books> _booksMapper;

    void CommonChecks(const drogon_model::bsuir_library::Publishers& model, std::vector<std::string>& errors);
};


