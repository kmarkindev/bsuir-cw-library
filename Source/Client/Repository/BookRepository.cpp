#include "BookRepository.h"

std::vector<BookInstance> BookRepository::GetInstances(std::uint64_t bookId)
{
    auto response = FetchApi("GET", _config.apiUrl,
        Book::GetPath() + "/" + std::to_string(bookId) + "/instances");
    auto json = nlohmann::json::parse(response.GetBody());

    std::vector<BookInstance> instances;
    for(const auto& item : json["data"])
    {
        BookInstance instance(item["instance"]);
        if(!item["withdraw"].is_null())
            instance.withdraw = BookWithdraw(item["withdraw"]);
        instances.push_back(instance);
    }
    return instances;
}

BookWithdraw BookRepository::WithdrawBook(std::uint64_t instanceId, std::uint64_t readerId, std::chrono::time_point<std::chrono::system_clock> returnAt)
{
    auto body = nlohmann::json();
    body["reader_id"] = readerId;
    body["return_at"] = RenderTimeString(returnAt);

    auto response = FetchApi("POST", _config.apiUrl,
        Book::GetPath() + "/instances/" + std::to_string(instanceId) + "/withdraw", to_string(body));
    auto json = nlohmann::json::parse(response.GetBody());

    return BookWithdraw(json);
}

void BookRepository::ReturnBook(std::uint64_t instanceId)
{
    FetchApi("POST", _config.apiUrl, Book::GetPath() + "/instances/" + std::to_string(instanceId) + "/return");
}

Book BookRepository::UploadFile(std::uint64_t bookId, const File& file)
{
    auto response = FetchApi("POST", _config.apiUrl,
        Book::GetPath() + "/" + std::to_string(bookId) + "/file", file.content, file.extension);
    auto json = nlohmann::json::parse(response.GetBody());

    return Book(json);
}

void BookRepository::RemoveFile(std::uint64_t bookId)
{
    FetchApi("DELETE", _config.apiUrl, Book::GetPath() + "/" + std::to_string(bookId) + "/file");
}

std::vector<BookInstance> BookRepository::GetInstances()
{
    auto response = FetchApi("GET", _config.apiUrl, Book::GetPath() + "/instances");
    auto json = nlohmann::json::parse(response.GetBody());

    std::vector<BookInstance> instances;
    for(const auto& item : json["data"])
    {
        BookInstance instance(item["instance"]);
        if(!item["withdraw"].is_null())
            instance.withdraw = BookWithdraw(item["withdraw"]);
        instances.push_back(instance);
    }
    return instances;
}

void BookRepository::CreateInstance(std::uint64_t id)
{
    FetchApi("POST", _config.apiUrl, Book::GetPath() + "/" + std::to_string(id) + "/instances");
}

void BookRepository::RemoveInstance(std::uint64_t id)
{
    FetchApi("DELETE", _config.apiUrl, Book::GetPath() + "/instances/" + std::to_string(id));
}
