#include "AuthorsValidator.h"

IValidator<drogon_model::bsuir_library::Authors>::Errors AuthorsValidator::ValidateForCreation(
    const drogon_model::bsuir_library::Authors& model) noexcept
{
    IValidator<drogon_model::bsuir_library::Authors>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя автора не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя автора не может быть длинее 32 символов");

    return result;
}

IValidator<drogon_model::bsuir_library::Authors>::Errors AuthorsValidator::ValidateForUpdate(
    const drogon_model::bsuir_library::Authors& model) noexcept
{
    IValidator<drogon_model::bsuir_library::Authors>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя автора не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя автора не может быть длинее 32 символов");

    return result;
}
