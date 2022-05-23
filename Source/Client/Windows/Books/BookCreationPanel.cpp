#include "BookCreationPanel.h"

BookCreationPanel::BookCreationPanel(wxWindow* parent)
    : EntityCreationPanel(parent)
{
    try
    {
        auto authors = _authorsRepo.GetAll();
        auto publishers = _publishersRepo.GetAll();

        for(auto& author : authors)
            _fields->authorChoice
                ->Append(wxString::FromUTF8(std::to_string(author.id.value()) + " - " + author.name.value()));
        _fields->authorChoice->Select(0);

        for(auto& publisher : publishers)
            _fields->publisherChoice
                ->Append(wxString::FromUTF8(std::to_string(publisher.id.value()) + " - " + publisher.name.value()));
        _fields->publisherChoice->Select(0);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }
}

void BookCreationPanel::CreateModel()
{
    Book book;
    book.name = _fields->bookName->GetValue().utf8_string();
    book.authorId = ParseIdFromChoice(_fields->authorChoice);
    book.publisherId = ParseIdFromChoice(_fields->publisherChoice);
    if(_fields->bookPublishedAt->GetValue().IsValid())
        book.publishedAt = ParseTime(_fields->bookPublishedAt->GetValue().Format("%Y-%m-%d").utf8_string());

    try
    {
        book = _repo.Create(book);

        auto panel = new BookViewPanel(this, book.id.value());
        panel->Init();
        AppState::GetAppState().GetOpenPageEvent().Notify(panel, wxString::FromUTF8("Книга"), true);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString BookCreationPanel::GetPanelName()
{
    return wxString::FromUTF8("Новая книга");
}
