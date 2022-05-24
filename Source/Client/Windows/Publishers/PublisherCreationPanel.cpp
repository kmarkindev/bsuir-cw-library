#include "PublisherCreationPanel.h"

PublisherCreationPanel::PublisherCreationPanel(wxWindow* parent)
    : EntityCreationPanel(parent)
{
    AppState::GetAppState().GetLogoutEvent().Subscribe([this]()
    {
        auto parent = static_cast<wxAuiNotebook*>(GetParent());
        auto n = parent->FindPage(this);
        parent->RemovePage(n);
    });
}

void PublisherCreationPanel::CreateModel()
{
    Publisher publisher;
    publisher.name = _fields->publisherName
        ->GetValue()
        .utf8_string();

    try
    {
        publisher = _repo.Create(publisher);

        auto panel = new PublisherViewPanel(this, publisher.id.value());
        panel->Init();
        AppState::GetAppState().GetOpenPageEvent().Notify(panel, wxString::FromUTF8("Издатель"), true);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString PublisherCreationPanel::GetPanelName()
{
    return wxString::FromUTF8("Новый издатель");
}
