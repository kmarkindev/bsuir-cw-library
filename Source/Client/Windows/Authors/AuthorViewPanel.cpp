#include "AuthorViewPanel.h"

AuthorViewPanel::AuthorViewPanel(wxWindow* parent, std::uint64_t id)
    : EntityViewPanel<wxFormBuilder::AuthorViewPanel>(parent, id)
{
    try
    {
        auto author = _repo.GetById(id);
        authorId->Disable();
        authorName->SetValue(wxString::FromUTF8(author.name.value()));
        authorId->SetValue(author.id.value());
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }
}

void AuthorViewPanel::ShowLoggedInState()
{
    saveAuthor->Enable();
    authorName->SetEditable(true);
}

void AuthorViewPanel::ShowLoggedOutState()
{
    saveAuthor->Disable();
    authorName->SetEditable(false);
}

void AuthorViewPanel::OnSaveButtonClicked(wxCommandEvent& event)
{
    Author author;
    author.id = authorId->GetValue();
    author.name = authorName->GetValue().utf8_string();

    try
    {
        _repo.Update(author);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

wxString AuthorViewPanel::GetPanelName()
{
    return wxString::FromUTF8("Автор");
}
