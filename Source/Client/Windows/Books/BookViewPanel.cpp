#include "BookViewPanel.h"

BookViewPanel::BookViewPanel(wxWindow* parent, std::uint64_t id)
    : EntityViewPanel<wxFormBuilder::BookViewPanel>(parent, id)
{
    instancesList->AppendTextColumn(wxString::FromUTF8("# экземпляра"), wxDATAVIEW_CELL_INERT, FromDIP(200));
    instancesList->AppendTextColumn(wxString::FromUTF8("# читателя, если выдана"), wxDATAVIEW_CELL_INERT, FromDIP(200));

    try
    {
        _bookId = id;
        auto book = _repo.GetById(id);
        bookId->SetValue(book.id.value());
        bookName->SetValue(wxString::FromUTF8(book.name.value()));
        bookPublishedAt->SetValue(wxDateTime(std::chrono::system_clock::to_time_t(book.publishedAt.value())));

        _hasFile = book.fileStoragePath.has_value();
        downloadFile->Enable(_hasFile);
        deleteFile->Enable(_hasFile);

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

    ReloadInstances();
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
    deleteFile->Enable(_hasFile);
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
    deleteFile->Enable(false);
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

    wxLaunchDefaultBrowser(wxString::FromUTF8(url));
}

void BookViewPanel::OnUploadClicked(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, wxString::FromUTF8("Выберите файл для загрузки"),
        "", "", "*.pdf;*.txt;*.doc;*.docx", wxFD_OPEN | wxFD_FILE_MUST_EXIST);

    if(openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    std::ifstream is(openFileDialog.GetPath().utf8_string());
    std::string content(std::istreambuf_iterator<char>(is), {});

    wxFileName filename(openFileDialog.GetPath());

    try
    {
        File file;
        file.content = content;
        file.extension = filename.GetExt().utf8_string();

        _repo.UpdateFile(_bookId, file);

        _hasFile = true;
        downloadFile->Enable(_hasFile);
        deleteFile->Enable(_hasFile);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

void BookViewPanel::OnAddInstanceClicked(wxCommandEvent& event)
try
{
    _repo.CreateInstance(_bookId);

    ReloadInstances();
}
catch(ApiErrorException& ex)
{
    AppState::GetAppState().GetApiErrorEvent().Notify(ex);
}

void BookViewPanel::OnWithdrawInstanceClicked(wxCommandEvent& event)
{
    if(instancesList->GetSelectedItemsCount() <= 0)
        return;

    AppState::GetAppState().GetOpenPageEvent().Notify(
        new InstanceWithdrawPanel(this, GetSelectedInstanceId()), wxString::FromUTF8("Выдача книги"), true);
}

void BookViewPanel::OnReturnInstanceClicked(wxCommandEvent& event)
try
{
    if(instancesList->GetSelectedItemsCount() <= 0)
        return;

    auto id = GetSelectedInstanceId();

    auto answer = wxMessageBox(wxString::FromUTF8("Вернуть экземпляр под номером ") + std::to_string(id) + "?",
        wxString::FromUTF8("Возврат"), wxYES_NO | wxICON_QUESTION);

    if(answer != wxYES)
        return;

    _repo.ReturnBook(id);

    ReloadInstances();
}
catch(ApiErrorException& ex)
{
    AppState::GetAppState().GetApiErrorEvent().Notify(ex);
}

void BookViewPanel::OnRemoveInstanceClicked(wxCommandEvent& event)
try
{
    if(instancesList->GetSelectedItemsCount() <= 0)
        return;

    auto id = GetSelectedInstanceId();

    auto answer = wxMessageBox(wxString::FromUTF8("Удалить экземпляр под номером ") + std::to_string(id) + "?",
        wxString::FromUTF8("Удаление"), wxYES_NO | wxICON_QUESTION);

    if(answer != wxYES)
        return;

    _repo.RemoveInstance(id);

    ReloadInstances();
}
catch(ApiErrorException& ex)
{
    AppState::GetAppState().GetApiErrorEvent().Notify(ex);
}

void BookViewPanel::ReloadInstances()
try
{
    auto instances = _repo.GetInstances(_bookId);

    instancesList->DeleteAllItems();

    for(auto& inst : instances)
    {
        wxVector<wxVariant> row;
        row.push_back(std::to_string(inst.id.value()));
        if(inst.withdraw.has_value())
            row.push_back(std::to_string(inst.withdraw->readerId.value()));
        else
            row.push_back("");

        instancesList->AppendItem(row);
    }
}
catch(ApiErrorException& ex)
{
    AppState::GetAppState().GetApiErrorEvent().Notify(ex);
}

std::uint64_t BookViewPanel::GetSelectedInstanceId()
{
    auto selected = instancesList->GetSelectedRow();
    wxVariant variant;
    instancesList->GetValue(variant, selected, 0);
    std::uint64_t id;
    variant.GetString().ToULongLong(&id);

    return id;
}

void BookViewPanel::OnInstancesUpdateClicked(wxCommandEvent& event)
{
    ReloadInstances();
}

void BookViewPanel::OnFileDeleteClicked(wxCommandEvent& event)
{
    try
    {
        _repo.RemoveFile(_bookId);

        _hasFile = false;
        downloadFile->Enable(_hasFile);
        deleteFile->Enable(_hasFile);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}
