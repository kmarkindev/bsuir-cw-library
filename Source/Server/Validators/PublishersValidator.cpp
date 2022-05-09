#include "PublishersValidator.h"

void PublishersValidator::ValidateForCreation(const drogon_model::bsuir_library::Publishers& model,
    const std::function<void(Errors)>& callback) noexcept
{
    IValidator<drogon_model::bsuir_library::Publishers>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя издателя не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя издателя не может быть длинее 32 символов");

    callback(result);
}

void PublishersValidator::ValidateForUpdate(const drogon_model::bsuir_library::Publishers& model,
    const std::function<void(Errors)>& callback) noexcept
{
    IValidator<drogon_model::bsuir_library::Publishers>::Errors result;

    if(!model.getName() || model.getName()->empty())
        result.push_back("Имя издателя не может быть пустым");
    else if(model.getName()->size() > 32)
        result.push_back("Имя издателя не может быть длинее 32 символов");

    if(model.getId())
        result.push_back("Нельзя обновить id издателя");

    callback(result);
}
