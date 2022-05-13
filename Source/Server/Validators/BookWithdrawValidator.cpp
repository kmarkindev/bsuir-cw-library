#include "BookWithdrawValidator.h"

void BookWithdrawValidator::ValidateForCreation(const drogon_model::bsuir_library::BookWithdraws& model,
    const std::function<void(const std::vector<std::string>&)>& callback) noexcept
{
    std::vector<std::string> errors;

    if(!model.getBookInstanceId())
        errors.emplace_back("Не указана выдаваемая книга");
    if(!model.getReaderId())
        errors.emplace_back("Не указан читатель которому выдается книга");
    if(!model.getWithdrawnAt())
        errors.emplace_back("Дата выдачи обязательна для заполнения");
    else if(model.getValueOfWithdrawnAt().secondsSinceEpoch() > trantor::Date::date().secondsSinceEpoch())
        errors.emplace_back("Дата выдачи не может быть в будущем");
    if(!model.getReturnAt())
        errors.emplace_back("Дата возврата обязательна для заполнения");
    else if(model.getValueOfReturnAt().secondsSinceEpoch() < trantor::Date::date().secondsSinceEpoch())
        errors.emplace_back("Дата возврата не может быть в прошлом");

    if(!errors.empty())
    {
        callback(errors);
        return;
    }

    _instMapper.findBy(drogon::orm::Criteria("id", drogon::orm::CompareOperator::EQ, model.getValueOfBookInstanceId()),
    [callback, model, this](auto instances)
    {
        if(instances.empty())
        {
            callback({"Указанная книга не найдена"});
            return;
        }

        _readersMapper.findBy(drogon::orm::Criteria("id", drogon::orm::CompareOperator::EQ, model.getValueOfReaderId()),
        [callback, model, this](auto readers)
        {
            if(readers.empty())
            {
                callback({"Указанный читатель не найден"});
                return;
            }

            _withdrawMapper.findBy(drogon::orm::Criteria("book_instance_id", drogon::orm::CompareOperator::EQ, model.getValueOfBookInstanceId()),
                [callback](auto withdraws)
                {
                    if(!withdraws.empty())
                    {
                        callback({"Выбранная книга уже выдана"});
                        return;
                    }

                    callback({});
                }, [callback](auto& ex)
                {
                    callback({"Не удалось проверить выдана ли уже книга"});
                });
        }, [callback](auto& ex)
        {
            callback({"Не удалось проверить существование читателя"});
        });
    },
    [callback](auto& ex)
    {
        callback({"Не удалось проверить существование книги"});
    });
}

BookWithdrawValidator::BookWithdrawValidator()
    : _withdrawMapper(drogon::app().getDbClient()),
    _instMapper(drogon::app().getDbClient()),
    _readersMapper(drogon::app().getDbClient())
{

}
