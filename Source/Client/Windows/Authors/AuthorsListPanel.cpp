#include "AuthorsListPanel.h"

wxVector<wxVector<wxVariant>> AuthorsListPanel::GetRows(AuthorsFilter* _filter)
{
    try
    {
        auto authors = _repo.GetAll();
        auto filterNameValue = _filter->authorName->GetValue();

        wxVector<wxVector<wxVariant>> result;
        result.reserve(authors.size());
        for(auto& author : authors)
        {
            if(!wxString::FromUTF8(author.name.value()).Contains(filterNameValue))
                continue;

            wxVector<wxVariant> row;
            row.reserve(2);
            row.push_back(wxVariant(wxString::FromUTF8(std::to_string(author.id.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(author.name.value())));
            result.push_back(row);
        }
        return result;
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        Close();
    }

    return {};
}

AuthorsListPanel::AuthorsListPanel(wxWindow* parent)
    : EntityList<AuthorsFilter, AuthorCreationPanel, AuthorViewPanel>(parent, wxString::FromUTF8("Список авторов"),
        {wxString::FromUTF8("#"), wxString::FromUTF8("Имя")})
{

}

void AuthorsListPanel::RemoveRow(std::uint64_t id)
{
    try
    {
        _repo.Delete(id);
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}
