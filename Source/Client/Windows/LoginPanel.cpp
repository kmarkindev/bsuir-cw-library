#include "LoginPanel.h"

LoginPanel::LoginPanel(wxWindow* parent)
    : wxFormBuilder::LoginPanel(parent), _authService(AppState::GetAppState().GetConfig())
{
    auto& appState = AppState::GetAppState();

    if(!AppState::GetAppState().IsAuthorized())
        ShowLoginPanel();
    else
        ShowLogoutPanel();

    _loginEventId = appState.GetLoginEvent().Subscribe([this]()
    {
        ShowLogoutPanel();
    });
    _logoutEventId = appState.GetLogoutEvent().Subscribe([this]()
    {
        ShowLoginPanel();
    });
}

void LoginPanel::ShowLoginPanel()
{
    loginPanel->Show(true);
    logoutPanel->Show(false);
    Layout();
}

void LoginPanel::ShowLogoutPanel()
{
    loginPanel->Show(false);
    logoutPanel->Show(true);
    Layout();
}

LoginPanel::~LoginPanel()
{
    auto& appState = AppState::GetAppState();
    appState.GetLoginEvent().Unsubscribe(_loginEventId);
    appState.GetLogoutEvent().Unsubscribe(_logoutEventId);
}

void LoginPanel::OnLoginClicked(wxCommandEvent& event)
{
    auto& appState = AppState::GetAppState();

    try
    {
        std::string password = passwordCtrl->GetValue().utf8_string();
        passwordCtrl->Clear();
        auto token = _authService.LogIn(password);
        appState.SetAuthorization(token);
    }
    catch (const ApiErrorException& ex)
    {
        appState.GetApiErrorEvent().Notify(ex);
    }
}

void LoginPanel::OnLogoutClicked(wxHyperlinkEvent& event)
{
    AppState::GetAppState().ResetAuthorization();
}
