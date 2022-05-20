#pragma once

#include <Models/Reader.h>
#include <Services/HttpClient/HttpClient.h>
#include <vector>

class ReadersRepository
{
    Reader GetPublisherById(std::uint64_t id);
    std::vector<Reader> GetAllPublishers();
    Reader CreatePublisher(const Reader& reader);
    Reader UpdatePublisher(const Reader& reader);
    Reader DeletePublisher(std::uint64_t id);
};
