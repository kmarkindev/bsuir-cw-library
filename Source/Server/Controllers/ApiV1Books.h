#pragma once

#include <drogon/HttpController.h>
#include <Models/Books.h>
#include "CrudController.h"
#include <Validators/BooksValidator.h>
#include <Services/FileStorageService.h>
#include <Models/BookInstances.h>
#include <Models/BookWithdraws.h>
#include <Validators/BookWithdrawValidator.h>
#include <Validators/BookInstanceValidator.h>
#include <Helpers/TrantorDateHelper.h>

namespace api::v1
{
    class Books : public drogon::HttpController<Books>,
        public CrudController<drogon_model::bsuir_library::Books, BooksValidator>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Books::GetOne, "/{id}", HttpMethod::Get);
            METHOD_ADD(Books::GetBookFile, "/{id}/file", HttpMethod::Get);
            METHOD_ADD(Books::UploadBookFile, "/{id}/file", HttpMethod::Post);
            METHOD_ADD(Books::RemoveBookFile, "/{id}/file", HttpMethod::Delete);
            METHOD_ADD(Books::GetAll, "", HttpMethod::Get);
            METHOD_ADD(Books::CreateBook, "", HttpMethod::Post, "AuthFilter");
            METHOD_ADD(Books::UpdateBook, "/{id}", HttpMethod::Put, "AuthFilter");
            METHOD_ADD(Books::DeleteBook, "/{id}", HttpMethod::Delete, "AuthFilter");
            METHOD_ADD(Books::GetInstances, "/{id}/instances", HttpMethod::Get);
            METHOD_ADD(Books::CreateInstance, "/{id}/instances", HttpMethod::Post, "AuthFilter");
            METHOD_ADD(Books::GetAllInstances, "/instances", HttpMethod::Get);
            METHOD_ADD(Books::DeleteInstance, "instances/{id}", HttpMethod::Delete, "AuthFilter");
            METHOD_ADD(Books::WithdrawInstance, "/instances/{id}/withdraw", HttpMethod::Post, "AuthFilter");
            METHOD_ADD(Books::ReturnInstance, "/instances/{id}/return", HttpMethod::Post, "AuthFilter");
        METHOD_LIST_END

        Books();

        void CreateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);
        void UpdateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void GetBookFile(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void UploadBookFile(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void RemoveBookFile(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void DeleteBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void GetInstances(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void GetAllInstances(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);
        void CreateInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void DeleteInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void WithdrawInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void ReturnInstance(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);

    private:
        FileStorageService _fileStorageService;
        orm::Mapper<drogon_model::bsuir_library::BookInstances> _instancesMapper;
        orm::Mapper<drogon_model::bsuir_library::BookWithdraws> _withdrawsMapper;
        BookWithdrawValidator _bookWithdrawValidator;
        BookInstanceValidator _bookInstanceValidator;
    };
}