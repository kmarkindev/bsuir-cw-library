#include "AuthorsValidator.h"

void AuthorsValidator::ValidateForCreation(const drogon_model::bsuir_library::Authors& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> result;

    CommonChecks(model, result);

    callback(result);
}

void AuthorsValidator::ValidateForUpdate(const drogon_model::bsuir_library::Authors& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> result;

    CommonChecks(model, result);

    callback(result);
}

void AuthorsValidator::CommonChecks(const drogon_model::bsuir_library::Authors& model, std::vector<std::string>& errors)
{
    if(model.getValueOfName().empty())
        errors.emplace_back("Имя автора не может быть пустым");
    else if(model.getName()->size() > 32)
        errors.emplace_back("Имя автора не может быть длинее 32 символов");
}
