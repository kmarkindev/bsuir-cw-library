#pragma once

#include <drogon/drogon.h>
#include "IValidator.h"
#include <Models/Authors.h>
#include <Models/Books.h>

class AuthorsValidator : public IValidator<drogon_model::bsuir_library::Authors>
{
public:
    AuthorsValidator();

    void ValidateForCreation(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForDelete(const drogon_model::bsuir_library::Authors& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    drogon::orm::Mapper<drogon_model::bsuir_library::Books> _booksMapper;

    void CommonChecks(const drogon_model::bsuir_library::Authors& model, std::vector<std::string>& errors);
};