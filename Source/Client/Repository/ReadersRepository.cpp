#include "ReadersRepository.h"

ReadersRepository::ReadersRepository(AppConfig config)
    : Repository<Reader>(std::move(config))
{

}
