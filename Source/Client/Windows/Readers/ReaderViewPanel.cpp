#include "ReaderViewPanel.h"

ReaderViewPanel::ReaderViewPanel(wxWindow* parent, std::uint64_t id)
    : EntityViewPanel<wxFormBuilder::ReaderViewPanel>(parent, id)
{
    try
    {
        auto reader = _repo.GetById(id);
        readerId->SetValue(reader.id.value());
        readerName->SetValue(wxString::FromUTF8(reader.name.value()));
        readerAddress->SetValue(wxString::FromUTF8(reader.address.value()));
        if(reader.sex.value())
            readerMale->SetValue(true);
        else
            readerFemale->SetValue(true);
        readerBirthday->SetValue(wxDateTime(std::chrono::system_clock::to_time_t(reader.birthday.value())));
        readerPhone->SetValue(wxString::FromUTF8(reader.phone.value()));
        readerEmail->SetValue(wxString::FromUTF8(reader.email.value()));

        AppState::GetAppState().GetLogoutEvent().Subscribe([this]()
        {
            auto parent = static_cast<wxAuiNotebook*>(GetParent());
            auto n = parent->FindPage(this);
            parent->RemovePage(n);
        });
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }
}

void ReaderViewPanel::ShowLoggedInState()
{
    saveReader->Enable();
    readerName->SetEditable(true);
    readerAddress->SetEditable(true);
    readerBirthday->Enable(true);
    readerFemale->Enable(true);
    readerMale->Enable(true);
    readerPhone->Enable(true);
    readerEmail->Enable(true);
}

void ReaderViewPanel::ShowLoggedOutState()
{
    saveReader->Disable();
    readerName->SetEditable(false);
    readerAddress->SetEditable(false);
    readerBirthday->Enable(false);
    readerFemale->Enable(false);
    readerMale->Enable(false);
    readerPhone->Enable(false);
    readerEmail->Enable(false);
}

void ReaderViewPanel::OnSaveButtonClicked(wxCommandEvent& event)
{
    Reader reader;
    reader.id = readerId->GetValue();
    reader.name = readerName->GetValue().utf8_string();
    reader.address = readerAddress->GetValue().utf8_string();
    if(readerBirthday->GetValue().IsValid())
        reader.birthday = ParseTime(readerBirthday->GetValue().Format("%Y-%m-%d").utf8_string());
    reader.sex = readerMale->GetValue();
    reader.phone = readerPhone->GetValue().utf8_string();
    reader.email = readerEmail->GetValue().utf8_string();

    try
    {
        _repo.Update(reader);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString ReaderViewPanel::GetPanelName()
{
    return wxString::FromUTF8("Читатель");
}
