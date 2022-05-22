#include "BookRepository.h"

std::vector<BookInstance> BookRepository::GetInstances(std::uint64_t bookId)
{
    auto response = FetchApi("POST", _config.apiUrl,
        Book::GetPath() + "/" + std::to_string(bookId) + "/instances");
    auto json = nlohmann::json::parse(response.GetBody());

    std::vector<BookInstance> instances;
    for(const auto& item : json["data"])
    {
        BookInstance instance(item["instance"]);
        instance.withdraw = BookWithdraw(item["withdraw"]);
    }
    return instances;
}

BookWithdraw BookRepository::WithdrawBook(std::uint64_t instanceId)
{
    auto response = FetchApi("POST", _config.apiUrl,
        Book::GetPath() + "/instances/" + std::to_string(instanceId) + "/withdraw");
    auto json = nlohmann::json::parse(response.GetBody());

    return BookWithdraw(json);
}

void BookRepository::ReturnBook(std::uint64_t instanceId)
{
    FetchApi("POST", _config.apiUrl, Book::GetPath() + "/instances/" + std::to_string(instanceId) + "/return");
}

Book BookRepository::CreateWithFile(const Book& book, const File& file)
{
    auto body = book.ToJson();
    body["file"]["content"] = file.content;
    body["file"]["extension"] = file.extension;

    auto response = FetchApi("POST", _config.apiUrl, Book::GetPath(), to_string(body));
    auto json = nlohmann::json::parse(response.GetBody());

    return Book(json);
}

Book BookRepository::UpdateFile(std::uint64_t bookId, const File& file)
{
    auto body = nlohmann::json();
    body["file"]["content"] = file.content;
    body["file"]["extension"] = file.extension;

    auto response = FetchApi("PUT", _config.apiUrl, Book::GetPath() + "/" + std::to_string(bookId), to_string(body));
    auto json = nlohmann::json::parse(response.GetBody());

    return Book(json);
}

File BookRepository::GetFile(std::uint64_t id)
{
    auto response = FetchApi("GET", _config.apiUrl, Book::GetPath() + "/" + std::to_string(id) + "/file");

    File file;
    file.content = response.GetBody();
    file.extension = response.GetHeaders().GetHeader("file-ext").GetValue();

    return file;
}
