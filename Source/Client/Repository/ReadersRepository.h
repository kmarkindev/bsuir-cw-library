#pragma once

#include <Models/Reader.h>
#include "Repository.h"

class ReadersRepository : public Repository<Reader>
{
public:
    explicit ReadersRepository(AppConfig config);
};
