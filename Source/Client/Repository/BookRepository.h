#pragma once

#include <Models/Book.h>
#include "Repository.h"
#include <Dto/File.h>

class BookRepository : public Repository<Book>
{
public:

    Book CreateWithFile(const Book& book, const File& file);
    Book UpdateFile(std::uint64_t bookId, const File& file);
    File GetFile(std::uint64_t id);
    std::vector<BookInstance> GetInstances(std::uint64_t bookId);
    BookWithdraw WithdrawBook(std::uint64_t instanceId);
    void ReturnBook(std::uint64_t instanceId);
};
