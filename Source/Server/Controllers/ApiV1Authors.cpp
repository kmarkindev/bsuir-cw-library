#include "ApiV1Authors.h"

api::v1::Authors::Authors()
    : _authorsRepository(app().getDbClient())
{

}

void api::v1::Authors::GetAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    unsigned long long authorId)
{
    try
    {
        _authorsRepository.FindAuthorById(authorId, [callback](RepoQueryResult res, std::vector<Author>* authors){

            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(authors->empty())
                callback(GetErrorResponse("Автор не найден", 404));
            else
                callback(GetJsonModelResponseFrom((*authors)[0]));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Authors::GetAuthors(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
{
    try
    {
        _authorsRepository.GetAuthors([callback](RepoQueryResult res, std::vector<Author>* authors)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            callback(GetJsonCollectionResponseFrom(*authors));
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Authors::CreateAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback)
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

        _authorsRepository.InsertAuthor(author, [callback, author](RepoQueryResult res,
            unsigned long long insertedId) mutable
        {
            if(res.isSuccess)
            {
                author.SetId(insertedId);
                callback(GetJsonModelResponseFrom(author));
            }
            else
            {
                callback(GetErrorResponse(res.error, 500));
            }
        });
    }
    catch(std::invalid_argument& ex)
    {
        callback(GetErrorResponse(ex.what(), 400));
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Authors::UpdateAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
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
        _authorsRepository.FindAuthorById(authorId, [callback, json, this](RepoQueryResult res,
            std::vector<Author>* authors)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(authors->empty())
            {
                callback(GetErrorResponse("Автор не найден", 404));
                return;
            }

            auto author = (*authors)[0];
            author.FillFromJson(*json, false);
            _authorsRepository.UpdateAuthor(author, [callback, author](RepoQueryResult res) {
                if(!res.isSuccess)
                    callback(GetErrorResponse(res.error, 500));
                else
                    callback(GetJsonModelResponseFrom(author));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}

void api::v1::Authors::DeleteAuthor(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
    unsigned long long authorId)
{
    try
    {
        _authorsRepository.FindAuthorById(authorId, [callback, this](RepoQueryResult res,
            std::vector<Author>* authors)
        {
            if(!res.isSuccess)
            {
                callback(GetErrorResponse(res.error, 500));
                return;
            }

            if(authors->empty())
            {
                callback(GetErrorResponse("Автор не найден", 404));
                return;
            }

            auto author = (*authors)[0];
            _authorsRepository.DeleteAuthor(author.GetId(), [callback, author](RepoQueryResult res) {
                if(!res.isSuccess)
                    callback(GetErrorResponse(res.error, 500));
                else
                    callback(GetJsonModelResponseFrom(author));
            });
        });
    }
    catch(std::exception& ex)
    {
        callback(GetErrorResponse(ex.what(), 500));
    }
}