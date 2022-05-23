#include "BooksListPanel.h"

wxVector<wxVector<wxVariant>> BooksListPanel::GetRows(BooksFilter* _filter)
{
    try
    {
        auto authors = _authorsRepo.GetAll();
        auto publishers = _publishersRepo.GetAll();
        auto books = _repo.GetAll();

        auto filterName = _filter->bookName->GetValue();
        auto checkDate = _filter->bookPublishedAt->GetValue().IsValid();
        auto filterDate = checkDate
            ? ParseTime(_filter->bookPublishedAt->GetValue().Format("%Y-%m-%d").utf8_string())
            : ParseTime("");
        auto filterAuthorId = ParseIdFromChoice(_filter->authorChoice);
        auto filterPublisherId = ParseIdFromChoice(_filter->publisherChoice);
        auto checkFile = _filter->bookFile->GetStringSelection() != wxString::FromUTF8("");
        auto hasFile = _filter->bookFile->GetStringSelection() == wxString::FromUTF8("Есть");

        wxVector<wxVector<wxVariant>> result;
        result.reserve(books.size());
        for(auto& book : books)
        {
            if(!wxString::FromUTF8(book.name.value()).Contains(filterName))
                continue;
            if(checkDate && filterDate != book.publishedAt)
                continue;
            if(checkFile)
            {
                if(hasFile && !book.fileStoragePath.has_value())
                    continue;
                if(!hasFile && book.fileStoragePath.has_value())
                    continue;
            }
            if(filterAuthorId > 0)
                if(filterAuthorId != book.authorId.value())
                    continue;
            if(filterPublisherId > 0)
                if(filterPublisherId != book.publisherId.value())
                    continue;

            auto bookAuthorName = std::string();
            for(auto& author : authors)
            {
                if(author.id.value() == book.authorId.value())
                {
                    bookAuthorName = author.name.value();
                }
            }
            auto bookPublisherName = std::string();
            for(auto& publisher : publishers)
            {
                if(publisher.id.value() == book.publisherId.value())
                {
                    bookPublisherName = publisher.name.value();
                }
            }

            wxVector<wxVariant> row;
            row.push_back(wxVariant(wxString::FromUTF8(std::to_string(book.id.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(book.name.value())));
            row.push_back(wxVariant(wxString::FromUTF8(bookAuthorName)));
            row.push_back(wxVariant(wxString::FromUTF8(bookPublisherName)));
            row.push_back(wxVariant(wxString::FromUTF8(RenderTimeString(book.publishedAt.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(book.fileStoragePath.has_value() ? "Есть" : "Нет")));

            result.push_back(row);
        }
        return result;
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }

    return {};
}

BooksListPanel::BooksListPanel(wxWindow* parent)
    : EntityList<BooksFilter, BookCreationPanel, BookViewPanel>(parent, wxString::FromUTF8("Список книг"),
        {wxString::FromUTF8("#"), wxString::FromUTF8("Название"), wxString::FromUTF8("Имя автора"), wxString::FromUTF8("Имя издателя"),
         wxString::FromUTF8("Дата издания"), wxString::FromUTF8("Электронная версия")})
{

}

void BooksListPanel::RemoveRow(std::uint64_t id)
{
    try
    {
        _repo.Delete(id);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}
