#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <AppState.h>

template<typename EntityPanelType>
class EntityViewPanel : public EntityPanelType
{
public:
    EntityViewPanel(wxWindow* parent, std::uint64_t id)
        : EntityPanelType(parent), _id(id)
    {
        auto& appState = AppState::GetAppState();

        _loginEventId = appState.GetLoginEvent().Subscribe([this]()
        {
            ShowLoggedInState();
        });
        _logoutEventId = appState.GetLogoutEvent().Subscribe([this]()
        {
            ShowLoggedOutState();
        });
    }

    void Init()
    {
        auto& appState = AppState::GetAppState();
        if(appState.IsAuthorized())
            ShowLoggedInState();
        else
            ShowLoggedOutState();
    }

    ~EntityViewPanel()
    {
        auto& appState = AppState::GetAppState();
        appState.GetLoginEvent().Unsubscribe(_loginEventId);
        appState.GetLogoutEvent().Unsubscribe(_logoutEventId);
    }

protected:
    std::uint64_t _id;

    virtual void ShowLoggedInState() = 0;
    virtual void ShowLoggedOutState() = 0;

private:
    std::uint32_t _loginEventId;
    std::uint32_t _logoutEventId;
};