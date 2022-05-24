#include "DebtorsListPanel.h"

void DebtorsListPanel::RefreshButtonClicked(wxCommandEvent& event)
{
    LoadList();
}

void DebtorsListPanel::ReturnButtonClicked(wxCommandEvent& event)
{
    if(list->GetSelectedItemsCount() <= 0)
        return;

    try
    {
        auto id = GetSelectedId();
        auto answer = wxMessageBox(wxString::FromUTF8("Удалить запись с id = ") + std::to_string(id) + "?",
            wxString::FromUTF8("Удаление"), wxYES_NO | wxICON_QUESTION);

        if(answer == wxYES)
        {
            _bookRepo.ReturnBook(id);
            LoadList();
        }
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}

DebtorsListPanel::DebtorsListPanel(wxWindow* parent)
    : wxFormBuilder::DebtorsListPanel(parent)
{
    list->AppendTextColumn(wxString::FromUTF8("# экземпляра"));
    list->AppendTextColumn(wxString::FromUTF8("# читателя"));
    list->AppendTextColumn(wxString::FromUTF8("Имя читателя"));
    list->AppendTextColumn(wxString::FromUTF8("Телефон читателя"));
    list->AppendTextColumn(wxString::FromUTF8("Почта (email) читателя"));

    LoadList();
}

std::uint64_t DebtorsListPanel::GetSelectedId()
{
    auto selected = list->GetSelectedRow();
    wxVariant variant;
    list->GetValue(variant, selected, 0);
    std::uint64_t id;
    variant.GetString().ToULongLong(&id);

    return id;
}

void DebtorsListPanel::LoadList()
try
{
    auto readers = _readersRepo.GetAll();
    auto instances = _bookRepo.GetInstances();

    for(auto& inst : instances)
    {
        if(!inst.withdraw.has_value())
            continue;

        Reader* foundReader;
        for(auto& reader : readers)
        {
            if(reader.id.value() == inst.withdraw->readerId.value())
            {
                foundReader = &reader;
                break;
            }
        }

        wxVector<wxVariant> row;
        row.push_back(std::to_string(inst.id.value()));
        row.push_back(std::to_string(foundReader->id.value()));
        row.push_back(wxString::FromUTF8(foundReader->name.value()));
        row.push_back(wxString::FromUTF8(foundReader->phone.has_value() ? foundReader->phone.value() : ""));
        row.push_back(wxString::FromUTF8(foundReader->email.has_value() ? foundReader->email.value() : ""));

        list->AppendItem(row);
    }
}
catch(ApiErrorException& ex)
{
    AppState::GetAppState().GetApiErrorEvent().Notify(ex);
}
