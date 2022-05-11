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

void PublishersValidator::ValidateForDelete(const drogon_model::bsuir_library::Publishers& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    _booksMapper.findBy(drogon::orm::Criteria("publisher_id", drogon::orm::CompareOperator::EQ, model.getValueOfId()),
        [callback](auto books)
        {
            if(!books.empty())
            {
                callback({"Нельзя удалить издателя пока существуют приписанные к нему книги"});
                return;
            }

            callback({});
        },
        [callback](auto& ex)
        {
            callback({"Не удалось проверить наличие книг у издателя"});
        });
}

void PublishersValidator::CommonChecks(const drogon_model::bsuir_library::Publishers& model, std::vector<std::string>& errors)
{
    if(model.getValueOfName().empty())
        errors.emplace_back("Имя издателя не может быть пустым");
    else if(model.getName()->size() > 32)
        errors.emplace_back("Имя издателя не может быть длинее 32 символов");
}

PublishersValidator::PublishersValidator()
    : _booksMapper(drogon::app().getDbClient())
{

}
