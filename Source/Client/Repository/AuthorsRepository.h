#pragma once

#include <Models/Author.h>
#include "Repository.h"

class AuthorsRepository : public Repository<Author>
{
public:
    explicit AuthorsRepository(AppConfig config);
};
