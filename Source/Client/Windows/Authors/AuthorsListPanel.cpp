#include "AuthorsListPanel.h"

wxVector<wxVector<wxVariant>> AuthorsListPanel::GetRows(AuthorsFilter* _filter)
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

AuthorsListPanel::AuthorsListPanel(wxWindow* parent)
    : EntityList<AuthorsFilter, void>(parent, wxString::FromUTF8("Список авторов"),
        {wxString::FromUTF8("#"), wxString::FromUTF8("Имя")}),
        _repo(AppState::GetAppState().GetConfig())
{

}
