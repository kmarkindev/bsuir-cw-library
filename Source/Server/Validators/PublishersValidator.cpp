#include "PublishersValidator.h"

void PublishersValidator::ValidateForCreation(const drogon_model::bsuir_library::Publishers& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> result;

    CommonChecks(model, result);

    callback(result);
}

void PublishersValidator::ValidateForUpdate(const drogon_model::bsuir_library::Publishers& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> result;

    CommonChecks(model, result);

    callback(result);
}

void PublishersValidator::CommonChecks(const drogon_model::bsuir_library::Publishers& model, std::vector<std::string>& errors)
{
    if(model.getValueOfName().empty())
        errors.emplace_back("Имя издателя не может быть пустым");
    else if(model.getName()->size() > 32)
        errors.emplace_back("Имя издателя не может быть длинее 32 символов");
}
