#pragma once

#include <Models/Publisher.h>
#include "Repository.h"

class PublishersRepository : public Repository<Publisher>
{
public:
    explicit PublishersRepository(AppConfig config);
};
