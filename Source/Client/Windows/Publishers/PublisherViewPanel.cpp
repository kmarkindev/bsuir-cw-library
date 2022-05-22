#include "PublisherViewPanel.h"

PublisherViewPanel::PublisherViewPanel(wxWindow* parent, std::uint64_t id)
    : EntityViewPanel<wxFormBuilder::PublisherViewPanel>(parent, id)
{
    try
    {
        auto publisher = _repo.GetById(id);
        publisherId->Disable();
        publisherName->SetValue(wxString::FromUTF8(publisher.name.value()));
        publisherId->SetValue(publisher.id.value());
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }
}

void PublisherViewPanel::ShowLoggedInState()
{
    savePublisher->Enable();
    publisherName->SetEditable(true);
}

void PublisherViewPanel::ShowLoggedOutState()
{
    savePublisher->Disable();
    publisherName->SetEditable(false);
}

void PublisherViewPanel::OnSaveButtonClicked(wxCommandEvent& event)
{
    Publisher publisher;
    publisher.id = publisherId->GetValue();
    publisher.name = publisherName->GetValue().utf8_string();

    try
    {
        _repo.Update(publisher);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString PublisherViewPanel::GetPanelName()
{
    return wxString::FromUTF8("Издатель");
}
