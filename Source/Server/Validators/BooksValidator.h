#pragma once

#include "IValidator.h"
#include <Models/Books.h>
#include <Models/Publishers.h>
#include <Models/Authors.h>
#include <drogon/drogon.h>

class BooksValidator : public IValidator<drogon_model::bsuir_library::Books>
{
public:
    BooksValidator();

    void ValidateForCreation(const drogon_model::bsuir_library::Books& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;
    void ValidateForUpdate(const drogon_model::bsuir_library::Books& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    void CommonChecks(const drogon_model::bsuir_library::Books& model,
        const std::function<void(const std::vector<std::string>&)>& callback);

    drogon::orm::Mapper<drogon_model::bsuir_library::Authors> _authorsMapper;
    drogon::orm::Mapper<drogon_model::bsuir_library::Publishers> _publishersMapper;
};


