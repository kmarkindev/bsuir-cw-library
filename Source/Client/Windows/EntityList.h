#pragma once

#include "WxBuilder/WxBuilder.h"
#include <Exceptions/ApiErrorException.h>
#include <AppState.h>

template<typename FilterPanelType, typename CreationPanelType>
class EntityList : public wxFormBuilder::EntityListPanel
{
public:

    EntityList(wxWindow* parent, const wxString& listNameStr, const std::vector<wxString>& columns)
        : wxFormBuilder::EntityListPanel(parent)
    {
        listName->SetLabel(listNameStr);

        _filter = new FilterPanelType(filterPanel);
        filterSizer->Add(_filter, 1, wxEXPAND);

        for(const auto& col : columns)
            dataList->AppendTextColumn(col);
    }

    void LoadList()
    {
        try
        {
            dataList->DeleteAllItems();

            auto rows = GetRows(_filter);
            for(auto& row : rows)
                dataList->AppendItem(row);
        }
        catch(ApiErrorException& ex)
        {
            AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        }
    }

    void RemoveSelected()
    {

    }

    void OpenCreationTab()
    {

    }

protected:

    virtual wxVector<wxVector<wxVariant>> GetRows(FilterPanelType* filter) = 0;

    void OnRefreshButtonClicked(wxCommandEvent& event) override
    {
        LoadList();
    }

    void OnCreateButtonClicked(wxCommandEvent& event) override
    {
        OpenCreationTab();
    }

    void OnDeleteButtonClicked(wxCommandEvent& event) override
    {
        RemoveSelected();
    }

    void OnFilterApplyClicked(wxCommandEvent& event) override
    {
        LoadList();
    }

    void OnFilterResetClicked(wxCommandEvent& event) override
    {
        _filter->Reset();
        LoadList();
    }

private:
    FilterPanelType* _filter;
};
