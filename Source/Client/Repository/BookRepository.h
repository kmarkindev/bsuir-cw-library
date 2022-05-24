#pragma once

#include <Models/Book.h>
#include "Repository.h"
#include <wx/base64.h>
#include <Dto/File.h>
#include <Helpers/DateParser.h>

class BookRepository : public Repository<Book>
{
public:
    Book UploadFile(std::uint64_t bookId, const File& file);
    void CreateInstance(std::uint64_t id);
    void RemoveInstance(std::uint64_t id);
    std::vector<BookInstance> GetInstances();
    std::vector<BookInstance> GetInstances(std::uint64_t bookId);
    BookWithdraw WithdrawBook(std::uint64_t instanceId, std::uint64_t readerId, std::chrono::time_point<std::chrono::system_clock> returnAt);
    void ReturnBook(std::uint64_t instanceId);
    void RemoveFile(std::uint64_t id);

};
