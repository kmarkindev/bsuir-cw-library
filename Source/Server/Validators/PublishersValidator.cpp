#include "PublishersValidator.h"

IValidator<drogon_model::bsuir_library::Publishers>::Errors PublishersValidator::ValidateForCreation(
    const drogon_model::bsuir_library::Publishers& model) noexcept
{
    IValidator<drogon_model::bsuir_library::Publishers>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя издателя не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя издателя не может быть длинее 32 символов");

    return result;
}

IValidator<drogon_model::bsuir_library::Publishers>::Errors PublishersValidator::ValidateForUpdate(
    const drogon_model::bsuir_library::Publishers& model) noexcept
{
    IValidator<drogon_model::bsuir_library::Publishers>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя издателя не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя издателя не может быть длинее 32 символов");

    if(model.getId())
        result.push_back("Нельзя обновить id издателя");

    return result;
}
