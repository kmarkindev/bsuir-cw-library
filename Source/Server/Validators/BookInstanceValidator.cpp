#include "BookInstanceValidator.h"

void BookInstanceValidator::ValidateForCreation(const drogon_model::bsuir_library::BookInstances& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    if(!model.getBookId())
    {
        callback({"Id книги обязательно для заполнения"});
        return;
    }

    _booksMapper.findBy(drogon::orm::Criteria("id", drogon::orm::CompareOperator::EQ, model.getValueOfBookId()), [callback](auto books)
    {
        if(books.empty())
        {
            callback({"Указанной книги не существует"});
            return;
        }

        callback({});
    }, [callback](auto& ex)
    {
        callback({"Не удалось проверить существование книги"});
    });
}

BookInstanceValidator::BookInstanceValidator()
    : _booksMapper(drogon::app().getDbClient())
{

}
