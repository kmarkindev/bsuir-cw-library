#include "ReaderCreationPanel.h"

ReaderCreationPanel::ReaderCreationPanel(wxWindow* parent)
    : EntityCreationPanel(parent)
{
    AppState::GetAppState().GetLogoutEvent().Subscribe([this]()
    {
        auto parent = static_cast<wxAuiNotebook*>(GetParent());
        auto n = parent->FindPage(this);
        parent->RemovePage(n);
    });
}

void ReaderCreationPanel::CreateModel()
{
    Reader reader;
    reader.name = _fields->readerName->GetValue().utf8_string();
    reader.address = _fields->readerAddress->GetValue().utf8_string();
    if(_fields->readerBirthday->GetValue().IsValid())
        reader.birthday = ParseTime(_fields->readerBirthday->GetValue().Format("%Y-%m-%d").utf8_string());
    reader.sex = _fields->readerMale->GetValue();
    reader.phone = _fields->readerPhone->GetValue().utf8_string();
    reader.email = _fields->readerEmail->GetValue().utf8_string();

    try
    {
        reader = _repo.Create(reader);

        auto panel = new ReaderViewPanel(this, reader.id.value());
        panel->Init();
        AppState::GetAppState().GetOpenPageEvent().Notify(panel, wxString::FromUTF8("Читатель"), true);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString ReaderCreationPanel::GetPanelName()
{
    return wxString::FromUTF8("Новый читатель");
}
