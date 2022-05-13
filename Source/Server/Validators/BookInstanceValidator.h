#pragma once

#include <Models/BookInstances.h>
#include <Models/Books.h>
#include <drogon/drogon.h>
#include "IValidator.h"

class BookInstanceValidator : public IValidator<drogon_model::bsuir_library::BookInstances>
{
public:

    BookInstanceValidator();

    void ValidateForCreation(const drogon_model::bsuir_library::BookInstances& model,
        const std::function<void(const std::vector<std::string>&)>& callback) noexcept;
private:
    drogon::orm::Mapper<drogon_model::bsuir_library::Books> _booksMapper;
};


