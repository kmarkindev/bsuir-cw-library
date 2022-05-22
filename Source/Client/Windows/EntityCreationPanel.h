#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <AppState.h>

template<typename EntityCreationFields>
class EntityCreationPanel : public wxFormBuilder::EntityCreationPanel
{
public:
    explicit EntityCreationPanel(wxWindow* parent)
        : wxFormBuilder::EntityCreationPanel(parent)
    {
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

        _fields = new EntityCreationFields(fieldsPanel);
        fieldsSizer->Add(_fields, 1, wxEXPAND);
    }

    ~EntityCreationPanel() override
    {
        auto& appState = AppState::GetAppState();
        appState.GetLoginEvent().Unsubscribe(_loginEventId);
        appState.GetLogoutEvent().Unsubscribe(_logoutEventId);
    }

    void ShowLoggedInState()
    {
        saveButton->Enable();
    }

    void ShowLoggedOutState()
    {
        saveButton->Disable();
    }

protected:

    EntityCreationFields* _fields;

    virtual void CreateModel() = 0;

    void SaveButtonClicked(wxCommandEvent& event) override
    {
        CreateModel();
    }

private:
    std::uint32_t _loginEventId;
    std::uint32_t _logoutEventId;
};