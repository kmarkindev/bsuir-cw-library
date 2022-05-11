#include "BooksValidator.h"

void BooksValidator::ValidateForCreation(const drogon_model::bsuir_library::Books& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    CommonChecks(model, [callback](auto& errors)
    {
        callback(errors);
    });
}

void BooksValidator::ValidateForUpdate(const drogon_model::bsuir_library::Books& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    CommonChecks(model, [callback](auto& errors)
    {
        callback(errors);
    });
}

void BooksValidator::CommonChecks(const drogon_model::bsuir_library::Books& model,
    const std::function<void(const std::vector<std::string>&)>& callback)
{
    std::vector<std::string> errors;

    if(model.getValueOfName().empty())
        errors.emplace_back("Название книги не может быть пустым");
    else if(model.getValueOfName().size() > 64)
        errors.emplace_back("Название книги не может быть длинее 64 символов");

    if(model.getFileStoragePath() && model.getValueOfFileStoragePath().empty())
        errors.emplace_back("Нельзя хранить путь в виде пустой строки, используйте NULL");

    if(!model.getPublishedAt())
        errors.emplace_back("Дата публикации обязательня для заполнения");
    else if(model.getValueOfPublishedAt().secondsSinceEpoch() > trantor::Date::date().secondsSinceEpoch())
        errors.emplace_back("Дата публикации не может быть в будущем");

    if(!model.getAuthorId())
        errors.emplace_back("Автор обязателен для заполнения");
    if(!model.getPublisherId())
        errors.emplace_back("Издатель обязателен для заполнения");

    if(!errors.empty())
    {
        callback(errors);
        return;
    }

    _authorsMapper.findByPrimaryKey(model.getValueOfAuthorId(), [callback, model, this](auto authorModel)
    {
        _publishersMapper.findByPrimaryKey(model.getValueOfPublisherId(), [callback](auto publisherModel)
        {
            callback({});
        }, [callback](auto ex)
        {
            callback({"Указанный издатель не существует"});
        });
    }, [callback](auto ex)
    {
        callback({"Указанный автор не существует"});
    });
}

BooksValidator::BooksValidator()
    : _authorsMapper(drogon::app().getDbClient()),
      _publishersMapper(drogon::app().getDbClient())
{

}
