#include "AuthorsRepository.h"


AuthorsRepository::AuthorsRepository(AppConfig config)
    : Repository<Author>(std::move(config))
{

}
