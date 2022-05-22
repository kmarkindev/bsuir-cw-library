#include "PublishersListPanel.h"

wxVector<wxVector<wxVariant>> PublishersListPanel::GetRows(PublishersFilter* _filter)
{
    try
    {
        auto publishers = _repo.GetAll();
        auto filterNameValue = _filter->publisherName->GetValue();

        wxVector<wxVector<wxVariant>> result;
        result.reserve(publishers.size());
        for(auto& publisher : publishers)
        {
            if(!wxString::FromUTF8(publisher.name.value()).Contains(filterNameValue))
                continue;

            wxVector<wxVariant> row;
            row.reserve(2);
            row.push_back(wxVariant(wxString::FromUTF8(std::to_string(publisher.id.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(publisher.name.value())));
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

PublishersListPanel::PublishersListPanel(wxWindow* parent)
    : EntityList<PublishersFilter, PublisherCreationPanel, PublisherViewPanel>(parent, wxString::FromUTF8("Список издателей"),
        {wxString::FromUTF8("#"), wxString::FromUTF8("Имя")})
{

}

void PublishersListPanel::RemoveRow(std::uint64_t id)
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
