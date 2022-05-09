#pragma once

#include <drogon/HttpController.h>
#include <Models/Publishers.h>
#include "CrudController.h"

using namespace drogon;

namespace api::v1
{
    class Publishers : public drogon::HttpController<Publishers>,
        public CrudController<drogon_model::bsuir_library::Publishers>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Publishers::GetOne, "/{id}", HttpMethod::Get);
            METHOD_ADD(Publishers::GetAll, "", HttpMethod::Get);
            METHOD_ADD(Publishers::Create, "", HttpMethod::Post, "AuthFilter");
            METHOD_ADD(Publishers::Update, "/{id}", HttpMethod::Put, "AuthFilter");
            METHOD_ADD(Publishers::Delete, "/{id}", HttpMethod::Delete, "AuthFilter");
        METHOD_LIST_END
    };
}
