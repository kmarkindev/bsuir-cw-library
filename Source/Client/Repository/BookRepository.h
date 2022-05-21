#pragma once

#include <Models/Book.h>
#include "Repository.h"
#include <Dto/File.h>

class BookRepository : public Repository<Book>
{
public:
    explicit BookRepository(AppConfig config);

    Book CreateWithFile(const Book& book, const std::string& fileContent, const std::string& fileExtension);
    Book UpdateWithFile(const Book& book, const std::string& fileContent, const std::string& fileExtension);
    File GetFile(std::uint64_t id);
    std::vector<BookInstance> GetInstances(std::uint64_t bookId);
    BookWithdraw WithdrawBook(std::uint64_t instanceId);
    void ReturnBook(std::uint64_t instanceId);

private:
    AppConfig _config;
};
