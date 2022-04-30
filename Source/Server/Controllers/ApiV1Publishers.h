#pragma once

#include <drogon/HttpController.h>
#include <Repositories/PublisherMySqlRepository.h>
#include <Helpers/ResponseHelpers.h>
#include <Dto/RepoQueryResult.h>
#include <Models/Publisher.h>

using namespace drogon;

namespace api::v1
{
    class Publishers : public drogon::HttpController<Publishers>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Publishers::GetPublisher, "/{publisherId}", Get);
            METHOD_ADD(Publishers::GetPublishers, "", Get);
            METHOD_ADD(Publishers::CreatePublisher, "", Post);
            METHOD_ADD(Publishers::UpdatePublisher, "/{publisherId}", Put);
            METHOD_ADD(Publishers::DeletePublisher, "/{publisherId}", Delete);
        METHOD_LIST_END

        explicit Publishers();

        void GetPublisher(const HttpRequestPtr &req, std::function<void (const HttpResponsePtr &)> &&publishers,
            unsigned long long publisherId);
        void GetPublishers(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);
        void CreatePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);
        void UpdatePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&publishers,
            unsigned long long publisherId);
        void DeletePublisher(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback,
            unsigned long long publisherId);
    private:
        PublisherMySqlRepository _publishersRepository;
    };
}
