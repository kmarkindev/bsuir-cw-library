#include "ReadersListPanel.h"

wxVector<wxVector<wxVariant>> ReadersListPanel::GetRows(ReadersFilter* _filter)
{
    try
    {
        auto readers = _repo.GetAll();

        auto filterName = _filter->readerName->GetValue();
        auto filterAddress = _filter->readerAddress->GetValue();
        auto filterCheckSex = !_filter->readerAnySex->GetValue();
        auto filterIsMale = _filter->readerMale->GetValue();
        auto filterIsFemale = _filter->readerFemale->GetValue();
        auto filterCheckBirthday = _filter->readerBirthday->GetValue().IsValid();
        auto filterBirthday = filterCheckBirthday
            ? ParseTime(_filter->readerBirthday->GetValue().Format("%Y-%m-%d").utf8_string())
            : ParseTime("");
        auto filterPhone = _filter->readerPhone->GetValue();
        auto filterEmail = _filter->readerEmail->GetValue();

        wxVector<wxVector<wxVariant>> result;
        result.reserve(readers.size());
        for(auto& reader : readers)
        {
            auto readerName = wxString::FromUTF8(reader.name.value());
            auto readerAddress = wxString::FromUTF8(reader.address.value());
            auto readerPhone = wxString::FromUTF8(reader.phone.has_value() ? reader.phone.value() : "");
            auto readerEmail = wxString::FromUTF8(reader.email.has_value() ? reader.email.value() : "");

            if(!readerName.Contains(filterName))
                continue;
            if(!readerAddress.Contains(filterAddress))
                continue;
            if(filterCheckBirthday && reader.birthday.value() != filterBirthday)
                continue;
            if(filterCheckSex)
            {
                if(filterIsMale && !reader.sex.value())
                    continue;
                if(filterIsFemale && reader.sex.value())
                    continue;
            }
            if(!readerPhone.Contains(filterPhone))
                continue;
            if(!readerEmail.Contains(filterEmail))
                continue;

            wxVector<wxVariant> row;
            row.reserve(2);
            row.push_back(wxVariant(wxString::FromUTF8(std::to_string(reader.id.value()))));
            row.push_back(wxVariant(readerName));
            row.push_back(wxVariant(readerAddress));
            row.push_back(wxVariant(wxString::FromUTF8(RenderTimeString(reader.birthday.value()))));
            row.push_back(wxVariant(wxString::FromUTF8(reader.sex.value() ? "муж." : "жен.")));
            row.push_back(wxVariant(readerPhone));
            row.push_back(wxVariant(readerEmail));
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
