#include "PublishersRepository.h"

PublishersRepository::PublishersRepository(AppConfig config)
    : Repository<Publisher>(std::move(config))
{

}
