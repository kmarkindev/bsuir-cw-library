#pragma once

#include "WxBuilder/WxBuilder.h"
#include <Exceptions/ApiErrorException.h>
#include <wx/msgdlg.h>
#include <AppState.h>

template<typename FilterPanelType, typename CreationPanelType, typename ViewPanelType>
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

        auto& appState = AppState::GetAppState();
        if(appState.IsAuthorized())
            ShowLoggedInState();
        else
            ShowLoggedOutState();

        _loginEventId = appState.GetLoginEvent().Subscribe([this]()
        {
            ShowLoggedInState();
        });
        _logoutEventId = appState.GetLogoutEvent().Subscribe([this]()
        {
            ShowLoggedOutState();
        });
    }

    ~EntityList() override
    {
        auto& appState = AppState::GetAppState();
        appState.GetLoginEvent().Unsubscribe(_loginEventId);
        appState.GetLogoutEvent().Unsubscribe(_logoutEventId);
    }

    void ShowLoggedInState()
    {
        deleteButton->Enable();
        createButton->Enable();
    }

    void ShowLoggedOutState()
    {
        deleteButton->Disable();
        createButton->Disable();
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
        try
        {
            auto id = GetSelectedId();
            auto answer = wxMessageBox(wxString::FromUTF8("Удалить запись с id = ") + std::to_string(id) + "?",
                wxString::FromUTF8("Удаление"), wxYES_NO | wxICON_QUESTION);

            if(answer == wxYES)
            {
                RemoveRow(id);
                LoadList();
            }
        }
        catch(ApiErrorException& ex)
        {
            AppState::GetAppState().GetApiErrorEvent().Notify(ex);
        }
    }

    void OpenCreationTab()
    {
        AppState::GetAppState().GetOpenPageEvent().Notify(new CreationPanelType(this), CreationPanelType::GetPanelName(), true);
    }

protected:

    virtual wxVector<wxVector<wxVariant>> GetRows(FilterPanelType* filter) = 0;
    virtual void RemoveRow(std::uint64_t id) = 0;

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

    void OnOpenButtonClicked(wxCommandEvent& event) override
    {
        auto panel = new ViewPanelType(this, GetSelectedId());
        panel->Init();
        AppState::GetAppState().GetOpenPageEvent().Notify(panel, ViewPanelType::GetPanelName(), true);
    }

private:
    FilterPanelType* _filter;
    std::uint32_t _loginEventId;
    std::uint32_t _logoutEventId;

    std::uint64_t GetSelectedId()
    {
        auto selected = dataList->GetSelectedRow();
        wxVariant variant;
        dataList->GetValue(variant, selected, 0);
        std::uint64_t id;
        variant.GetString().ToULongLong(&id);

        return id;
    }
};
