#include "AuthorsValidator.h"

void AuthorsValidator::ValidateForCreation(const drogon_model::bsuir_library::Authors& model,
    const std::function<void(Errors)>& callback) noexcept
{
    IValidator<drogon_model::bsuir_library::Authors>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя автора не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя автора не может быть длинее 32 символов");

    callback(result);
}

void AuthorsValidator::ValidateForUpdate(const drogon_model::bsuir_library::Authors& model,
    const std::function<void(Errors)>& callback) noexcept
{
    IValidator<drogon_model::bsuir_library::Authors>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя автора не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя автора не может быть длинее 32 символов");

    callback(result);
}
