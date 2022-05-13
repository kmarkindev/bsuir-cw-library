#pragma once

#include <drogon/drogon.h>
#include "CrudController.h"
#include <Models/Readers.h>
#include <Validators/ReadersValidator.h>

using namespace drogon;

namespace api::v1
{
    class Readers : public drogon::HttpController<Readers>,
        public CrudController<drogon_model::bsuir_library::Readers, ReadersValidator>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Readers::GetOne, "/{id}", HttpMethod::Get, "AuthFilter");
            METHOD_ADD(Readers::GetAll, "", HttpMethod::Get, "AuthFilter");
            METHOD_ADD(Readers::Create, "", HttpMethod::Post, "AuthFilter");
            METHOD_ADD(Readers::Update, "/{id}", HttpMethod::Put, "AuthFilter");
            METHOD_ADD(Readers::Delete, "/{id}", HttpMethod::Delete, "AuthFilter");
        METHOD_LIST_END
    };
}



