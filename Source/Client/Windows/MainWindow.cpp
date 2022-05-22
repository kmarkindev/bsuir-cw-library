#include "MainWindow.h"

MainWindow::MainWindow()
    : wxFormBuilder::MainWindow(nullptr)
{
    ShowLoginPanel();
    notebook->AddPage(new wxFormBuilder::WelcomePanel(notebook), wxString::FromUTF8("Приветствие"));
    notebook->AddPage(new HelpPanel(notebook), wxString::FromUTF8("Помощь"));

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
    _apiErrorEventId = appState.GetApiErrorEvent().Subscribe([this](auto exception)
    {
        AddPageAndSelect(notebook, new ErrorsPanel(notebook, exception), wxString::FromUTF8("Ошибка"));
    });
}

void MainWindow::ShowLoginPanel()
{
    loginPanel->Show(true);
    logoutPanel->Show(false);
    Layout();
}

void MainWindow::ShowLogoutPanel()
{
    loginPanel->Show(false);
    logoutPanel->Show(true);
    Layout();
}

void MainWindow::OnLoginLinkClicked(wxHyperlinkEvent& event)
{
    AddPageAndSelect(notebook, new LoginPanel(notebook), wxString::FromUTF8("Вход"));
}

void MainWindow::OnLogoutLinkClicked(wxHyperlinkEvent& event)
{
    AppState::GetAppState().ResetAuthorization();
}

MainWindow::~MainWindow()
{
    auto& appState = AppState::GetAppState();
    appState.GetLoginEvent().Unsubscribe(_loginEventId);
    appState.GetLogoutEvent().Unsubscribe(_logoutEventId);
    appState.GetApiErrorEvent().Unsubscribe(_apiErrorEventId);
}
