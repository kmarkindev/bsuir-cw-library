#include "AuthorCreationPanel.h"

AuthorCreationPanel::AuthorCreationPanel(wxWindow* parent)
    : EntityCreationPanel(parent)
{

}

void AuthorCreationPanel::CreateModel()
{
    Author author;
    author.name = _fields->authorName
        ->GetValue()
        .utf8_string();

    try
    {
        author = _repo.Create(author);

        auto panel = new AuthorViewPanel(this, author.id.value());
        panel->Init();
        AppState::GetAppState().GetOpenPageEvent().Notify(panel, wxString::FromUTF8("Автор"), true);
    }
    catch (ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString AuthorCreationPanel::GetPanelName()
{
    return wxString::FromUTF8("Новый автор");
}
