#include "ReadersValidator.h"

void ReadersValidator::ValidateForCreation(const drogon_model::bsuir_library::Readers& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> errors;

    CommonChecks(model, errors);

    callback(errors);
}

void ReadersValidator::ValidateForUpdate(const drogon_model::bsuir_library::Readers& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> errors;

    CommonChecks(model, errors);

    callback(errors);
}

void ReadersValidator::CommonChecks(const drogon_model::bsuir_library::Readers& model, std::vector<std::string>& errors)
{
    if(!model.getSex())
        errors.emplace_back("Пол читателя должен быть указан");
    else if(model.getValueOfSex() != 0 && model.getValueOfSex() != 1)
        errors.emplace_back("В поле Пол указано недопустимое значение");

    if(!model.getBirthday())
        errors.emplace_back("Дата рождения обязательна для заполнения");
    else if(model.getValueOfBirthday().secondsSinceEpoch() > trantor::Date::date().secondsSinceEpoch())
        errors.emplace_back("Дата рождения не может быть в будущем");

    if(model.getValueOfName().empty())
        errors.emplace_back("Имя читателя не может быть пустым");
    else if(model.getValueOfName().size() > 64)
        errors.emplace_back("Имя читателя не может быть длинее 64 символов");

    if(model.getValueOfAddress().empty())
        errors.emplace_back("Адрес читателя не может быть пустым");
    else if(model.getValueOfAddress().size() > 64)
        errors.emplace_back("Адрес читателя не может быть длинее 64 символов");

    if(model.getValueOfPhone().empty() && model.getValueOfEmail().empty())
    {
        errors.emplace_back("Телефон и/или Email читателя должны быть заполнены");
    }
    else
    {
        if(model.getValueOfPhone().size() > 32)
            errors.emplace_back("Телефон читателя не может быть длинее 32 символов");

        if(model.getValueOfEmail().size() > 32)
            errors.emplace_back("Email читателя не может быть длинее 32 символов");
    }
}
