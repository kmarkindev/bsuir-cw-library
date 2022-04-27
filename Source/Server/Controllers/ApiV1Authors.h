#pragma once

#include <drogon/HttpController.h>
#include <Models/Author.h>
#include <Repositories/AuthorMySqlRepository.h>
#include <Helpers/ResponseHelpers.h>
#include <Dto/RepoQueryResult.h>

using namespace drogon;

namespace api::v1
{
    class Authors : public drogon::HttpController<Authors>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Authors::GetAuthor, "/{authorId}", Get);
            METHOD_ADD(Authors::GetAuthors, "", Get);
            METHOD_ADD(Authors::CreateAuthor, "", Post);
            METHOD_ADD(Authors::UpdateAuthor, "/{authorId}", Put);
            METHOD_ADD(Authors::DeleteAuthor, "/{authorId}", Delete);
        METHOD_LIST_END

        explicit Authors();

        void GetAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
            unsigned long long authorId);
        void GetAuthors(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
        void CreateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback);
        void UpdateAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
            unsigned long long authorId);
        void DeleteAuthor(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&callback,
            unsigned long long authorId);
    private:
        AuthorMySqlRepository _authorsRepository;
    };
}
