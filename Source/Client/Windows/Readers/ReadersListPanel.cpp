#include "ReadersListPanel.h"

wxVector<wxVector<wxVariant>> ReadersListPanel::GetRows(ReadersFilter* _filter)
{
    try
    {
        auto readers = _repo.GetAll();

        wxVector<wxVector<wxVariant>> result;
        result.reserve(readers.size());
        for(auto& reader : readers)
        {
            //todo: filter

            wxVector<wxVariant> row;
            row.reserve(2);
            row.push_back(wxVariant(wxString::FromUTF8(std::to_string(reader.id.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(reader.name.value())));
            row.push_back(wxVariant(wxString::FromUTF8(reader.address.value())));
            row.push_back(wxVariant(wxString::FromUTF8(RenderTimeString(reader.birthday.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(reader.sex.value() ? "муж." : "жен.")));
            row.push_back(wxVariant(wxString::FromUTF8(reader.phone.has_value() ? reader.phone.value() : "")));
            row.push_back(wxVariant(wxString::FromUTF8(reader.email.has_value() ? reader.email.value() : "")));
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

ReadersListPanel::ReadersListPanel(wxWindow* parent)
    : EntityList<ReadersFilter, ReaderCreationPanel, ReaderViewPanel>(parent, wxString::FromUTF8("Список читателей"),
        {wxString::FromUTF8("#"), wxString::FromUTF8("Имя"), wxString::FromUTF8("Адрес"), wxString::FromUTF8("Дата рождения"),
         wxString::FromUTF8("Пол"), wxString::FromUTF8("Телефон"), wxString::FromUTF8("Почта (Email)")})
{

}

void ReadersListPanel::RemoveRow(std::uint64_t id)
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
