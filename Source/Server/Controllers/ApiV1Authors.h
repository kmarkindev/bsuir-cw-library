#pragma once

#include <drogon/HttpController.h>
#include <Models/Authors.h>
#include <Helpers/ResponseHelpers.h>
#include <Dto/RepoQueryResult.h>
#include "CrudController.h"

using namespace drogon;

namespace api::v1
{
    class Authors : public drogon::HttpController<Authors>,
        public CrudController<drogon_model::bsuir_library::Authors>
    {
    public:
        METHOD_LIST_BEGIN
            METHOD_ADD(Authors::GetOne, "/{id}", Get);
            METHOD_ADD(Authors::GetAll, "", Get);
            METHOD_ADD(Authors::Create, "", Post);
            METHOD_ADD(Authors::Update, "/{id}", Put);
//            METHOD_ADD(Authors::Delete, "/{id}", Delete);
        METHOD_LIST_END
    };
}
