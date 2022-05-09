#pragma once

#include <drogon/HttpController.h>
#include <Models/Authors.h>
#include "CrudController.h"

using namespace drogon;

namespace api::v1
{
    class Authors : public drogon::HttpController<Authors>,
        public CrudController<drogon_model::bsuir_library::Authors>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Authors::GetOne, "/{id}", HttpMethod::Get);
            METHOD_ADD(Authors::GetAll, "", HttpMethod::Get);
            METHOD_ADD(Authors::Create, "", HttpMethod::Post);
            METHOD_ADD(Authors::Update, "/{id}", HttpMethod::Put);
            METHOD_ADD(Authors::Delete, "/{id}", HttpMethod::Delete);
        METHOD_LIST_END
    };
}
