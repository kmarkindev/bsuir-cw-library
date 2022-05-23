#include "ReaderViewPanel.h"

ReaderViewPanel::ReaderViewPanel(wxWindow* parent, std::uint64_t id)
    : EntityViewPanel<wxFormBuilder::ReaderViewPanel>(parent, id)
{
    try
    {
        auto reader = _repo.GetById(id);
        //todo: fill
//        publisherId->Disable();
//        publisherName->SetValue(wxString::FromUTF8(reader.name.value()));
//        publisherId->SetValue(reader.id.value());
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
    //todo: fill
//    reader.id = publisherId->GetValue();
//    reader.name = publisherName->GetValue().utf8_string();

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
