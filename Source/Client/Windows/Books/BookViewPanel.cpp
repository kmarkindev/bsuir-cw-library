#include "BookViewPanel.h"

BookViewPanel::BookViewPanel(wxWindow* parent, std::uint64_t id)
    : EntityViewPanel<wxFormBuilder::BookViewPanel>(parent, id)
{
    try
    {
        _bookId = id;
        auto book = _repo.GetById(id);
        bookId->SetValue(book.id.value());
        bookName->SetValue(wxString::FromUTF8(book.name.value()));
        bookPublishedAt->SetValue(wxDateTime(std::chrono::system_clock::to_time_t(book.publishedAt.value())));

        auto authors = _authorsRepo.GetAll();
        auto publishers = _publishersRepo.GetAll();

        auto authorIndex = 0;
        for(auto& author : authors)
        {
            authorChoice
                ->Append(wxString::FromUTF8(std::to_string(author.id.value()) + " - " + author.name.value()));

            if(author.id.value() == book.authorId.value())
                authorIndex = authorChoice->GetCount() - 1;
        }
        authorChoice->Select(authorIndex);

        auto publisherIndex = 0;
        for(auto& publisher : publishers)
        {
            publisherChoice
                ->Append(wxString::FromUTF8(std::to_string(publisher.id.value()) + " - " + publisher.name.value()));

            if(publisher.id.value() == book.publisherId.value())
                publisherIndex = publisherChoice->GetCount() - 1;
        }
        publisherChoice->Select(publisherIndex);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }
}

void BookViewPanel::ShowLoggedInState()
{
    saveBook->Enable();
    bookName->Enable(true);
    authorChoice->Enable(true);
    publisherChoice->Enable(true);
    publisherChoice->Enable(true);
    bookPublishedAt->Enable(true);
    uploadFile->Enable(true);
    addInstance->Enable(true);
    withdrawInstance->Enable(true);
    returnInstance->Enable(true);
    removeInstance->Enable(true);
}

void BookViewPanel::ShowLoggedOutState()
{
    saveBook->Disable();
    bookName->Enable(false);
    authorChoice->Enable(false);
    publisherChoice->Enable(false);
    publisherChoice->Enable(false);
    bookPublishedAt->Enable(false);
    uploadFile->Enable(false);
    addInstance->Enable(false);
    withdrawInstance->Enable(false);
    returnInstance->Enable(false);
    removeInstance->Enable(false);
}

void BookViewPanel::OnSaveButtonClicked(wxCommandEvent& event)
{
    Book book;
    book.id = bookId->GetValue();
    book.name = bookName->GetValue().utf8_string();
    book.authorId = ParseIdFromChoice(authorChoice);
    book.publisherId = ParseIdFromChoice(publisherChoice);
    if(bookPublishedAt->GetValue().IsValid())
        book.publishedAt = ParseTime(bookPublishedAt->GetValue().Format("%Y-%m-%d").utf8_string());

    try
    {
        _repo.Update(book);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString BookViewPanel::GetPanelName()
{
    return wxString::FromUTF8("Книга");
}

void BookViewPanel::OnFileDownloadClicked(wxCommandEvent& event)
{
    std::string url = AppState::GetAppState().GetConfig().apiUrl;
    url += "/api/v1/books/";
    url += std::to_string(_bookId);
    url += "/file";

    wxLaunchDefaultBrowser(url, wxBROWSER_NEW_WINDOW);
}

void BookViewPanel::OnUploadClicked(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, wxString::FromUTF8("Выберите файл для загрузки"),
        "", "", "*.pdf|*.txt|*.doc|*.docx", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if(openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    std::ifstream is(openFileDialog.GetPath().utf8_string(), std::ios::beg);
    std::string content(std::istreambuf_iterator<char>(is), {});

    wxFileName filename(openFileDialog.GetPath());

    try
    {
        File file;
        file.content = content;
        file.extension = filename.GetExt().utf8_string();

        _repo.UpdateFile(_bookId, file);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}
