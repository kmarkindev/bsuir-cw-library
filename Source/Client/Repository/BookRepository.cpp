#include "BookRepository.h"

Book BookRepository::GetBookById(std::uint64_t id)
{
    return Book();
}

std::vector<Book> BookRepository::GetAllBooks()
{
    return std::vector<Book>();
}

Book BookRepository::CreateBook(const Book& author)
{
    return Book();
}

Book BookRepository::UpdateBook(const Book& author)
{
    return Book();
}

Book BookRepository::DeleteBook(std::uint64_t id)
{
    return Book();
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
