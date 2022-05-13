#pragma once

#include <drogon/HttpController.h>
#include <Models/Books.h>
#include "CrudController.h"
#include <Validators/BooksValidator.h>
#include <Services/FileStorageService.h>
#include <Models/BookInstances.h>
#include <Models/BookWithdraws.h>

namespace api::v1
{
    class Books : public drogon::HttpController<Books>,
        public CrudController<drogon_model::bsuir_library::Books, BooksValidator>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Books::GetOne, "/{id}", HttpMethod::Get);
            METHOD_ADD(Books::GetBookFile, "/{id}/file", HttpMethod::Get);
            METHOD_ADD(Books::GetAll, "", HttpMethod::Get);
            METHOD_ADD(Books::CreateBook, "", HttpMethod::Post, "AuthFilter");
            METHOD_ADD(Books::UpdateBook, "/{id}", HttpMethod::Put, "AuthFilter");
            METHOD_ADD(Books::DeleteBook, "/{id}", HttpMethod::Delete, "AuthFilter");
            METHOD_ADD(Books::GetInstances, "/{id}/instances", HttpMethod::Get);
        METHOD_LIST_END

        Books();

        void CreateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback);
        void UpdateBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void GetBookFile(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void DeleteBook(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);
        void GetInstances(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr&)> &&callback, std::uint64_t id);

    private:
        FileStorageService _fileStorageService;
        orm::Mapper<drogon_model::bsuir_library::BookInstances> _instancesMapper;
        orm::Mapper<drogon_model::bsuir_library::BookWithdraws> _withdrawsMapper;
    };
}