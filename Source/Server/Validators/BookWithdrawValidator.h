#pragma once

#include "IValidator.h"
#include <Models/BookWithdraws.h>
#include <Models/BookInstances.h>
#include <Models/Readers.h>
#include <drogon/drogon.h>

class BookWithdrawValidator : public IValidator<drogon_model::bsuir_library::BookWithdraws>
{
public:
    BookWithdrawValidator();

    void ValidateForCreation(const drogon_model::bsuir_library::BookWithdraws& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept override;

private:
    drogon::orm::Mapper<drogon_model::bsuir_library::BookInstances> _instMapper;
    drogon::orm::Mapper<drogon_model::bsuir_library::BookWithdraws> _withdrawMapper;
    drogon::orm::Mapper<drogon_model::bsuir_library::Readers> _readersMapper;
};


