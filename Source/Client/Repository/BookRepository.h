#pragma once

#include <Models/Book.h>
#include <vector>

class BookRepository
{
public:
    Book GetBookById(std::uint64_t id);
    std::vector<Book> GetAllBooks();
    Book CreateBook(const Book& author);
    Book UpdateBook(const Book& author);
    Book DeleteBook(std::uint64_t id);
    std::vector<BookInstance> GetInstances(std::uint64_t bookId);
    BookWithdraw WithdrawBook(std::uint64_t instanceId);
    void ReturnBook(std::uint64_t instanceId);
};
