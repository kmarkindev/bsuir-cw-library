#include "ReaderCreationPanel.h"

ReaderCreationPanel::ReaderCreationPanel(wxWindow* parent)
    : EntityCreationPanel(parent)
{

}

void ReaderCreationPanel::CreateModel()
{
    Reader reader;
    //todo: fill
//    reader.name = _fields->publisherName
//        ->GetValue()
//        .utf8_string();

    try
    {
        reader = _repo.Create(reader);

        auto panel = new PublisherViewPanel(this, reader.id.value());
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
