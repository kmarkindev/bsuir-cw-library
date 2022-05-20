#pragma once

#include <Models/Publisher.h>
#include <Services/HttpClient/HttpClient.h>
#include <vector>

class PublishersRepository
{
public:
    Publisher GetPublisherById(std::uint64_t id);
    std::vector<Publisher> GetAllPublishers();
    Publisher CreatePublisher(const Publisher& publisher);
    Publisher UpdatePublisher(const Publisher& publisher);
    Publisher DeletePublisher(std::uint64_t id);
};
