#include "BookRepository.h"

BookRepository::BookRepository(AppConfig config)
    : Repository<Book>(std::move(config))
{

}

std::vector<BookInstance> BookRepository::GetInstances(std::uint64_t bookId)
{
    return std::vector<BookInstance>();
}

BookWithdraw BookRepository::WithdrawBook(std::uint64_t instanceId)
{
    return BookWithdraw();
}

void BookRepository::ReturnBook(std::uint64_t instanceId)
{

}

Book BookRepository::CreateWithFile(const Book& book, const std::string& fileContent, const std::string& fileExtension)
{
    return Book(nlohmann::basic_json());
}

Book BookRepository::UpdateWithFile(const Book& book, const std::string& fileContent, const std::string& fileExtension)
{
    return Book(nlohmann::basic_json());
}

File BookRepository::GetFile(std::uint64_t id)
{
    return {};
}
