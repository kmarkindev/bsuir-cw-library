#include "ApiV1Authors.h"

api::v1::Authors::Authors()
    : _authorsRepository(app().getDbClient())
{

}

void api::v1::Authors::GetAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
    unsigned long long authorId)
{
    _authorsRepository.FindAuthorById(authorId, [callback](bool success, std::string error, std::vector<Author>* authors){

        if(!success)
        {
            callback(GetErrorResponse("Ошибка при получении автора", 500));
            return;
        }

        if(authors->empty())
            callback(GetErrorResponse("Автор не найден", 404));
        else
            callback(HttpResponse::newHttpJsonResponse((*authors)[0].ToJson()));
    });
}

void api::v1::Authors::GetAuthors(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json = req->getJsonObject();

    std::string name;
    std::string orderBy = "ASC";

    if(json)
    {
        name = json->get("name", "").asString();
        orderBy = json->get("order_by", "ASC").asString();
    }

    std::transform(orderBy.begin(), orderBy.end(), orderBy.begin(),
        [](auto c){ return std::tolower(c); });

    bool sortAsc = orderBy == "desc" ? false : true;

    _authorsRepository.FilterAuthorsByName(name, sortAsc, [callback](bool success, std::string error, std::vector<Author>* authors) {

        if(!success)
        {
            callback(GetErrorResponse("Не удалось получить список авторов", 500));
            return;
        }

        Json::Value result;
        result["authors"] = Json::arrayValue;

        for(const auto& author : *authors)
            result["authors"].append(author.ToJson());

        callback(HttpResponse::newHttpJsonResponse(result));
    });
}

void api::v1::Authors::CreateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    try
    {
        Author author(*json);

        _authorsRepository.InsertAuthor(author, [callback, author](bool success,
            std::string error, unsigned long long insertedId)
        {
            auto authorNew = author;
            if(success)
            {
                authorNew.SetId(insertedId);
                callback(HttpResponse::newHttpJsonResponse(authorNew.ToJson()));
            }
            else
            {
                callback(GetErrorResponse(std::move(error), 500));
            }
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 400));
    }
}

void api::v1::Authors::UpdateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
    unsigned long long authorId)
{
    auto json = req->getJsonObject();

    if(!json)
    {
        callback(GetNoJsonErrorResponse());
        return;
    }

    if(json->isMember("id"))
    {
        callback(GetErrorResponse("Изменение Id автора невозможно", 400));
        return;
    }

    try
    {
        _authorsRepository.FindAuthorById(authorId, [callback, json, this](bool success, std::string error,
            std::vector<Author>* authors)
        {
            if(!success)
            {
                callback(GetErrorResponse("Ошибка при поиске автора", 500));
                return;
            }

            if(authors->empty())
            {
                callback(GetErrorResponse("Автор не найден", 404));
                return;
            }

            auto author = (*authors)[0];
            author.FillFromJson(*json, false);
            _authorsRepository.UpdateAuthor(author, [callback, author](bool success, std::string error) {
                if(!success)
                    callback(GetErrorResponse(error, 500));
                else
                    callback(HttpResponse::newHttpJsonResponse(author.ToJson()));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 400));
    }
}