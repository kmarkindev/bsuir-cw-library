#include "MainWindow.h"

MainWindow::MainWindow()
    : wxFormBuilder::MainWindow(nullptr)
{
    auto& appState = AppState::GetAppState();

    if(appState.IsAuthorized())
        ShowLoggedInState();
    else
        ShowLoggedOutState();

    AddHelpPanel();
    AddWelcomePanel();

    _loginEventId = appState.GetLoginEvent().Subscribe([this]()
    {
        ShowLoggedInState();
    });
    _logoutEventId = appState.GetLogoutEvent().Subscribe([this]()
    {
        ShowLoggedOutState();
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

void MainWindow::OnHelpButtonClicked(wxCommandEvent& event)
{
    AddHelpPanel();
}

void MainWindow::AddHelpPanel()
{
    AddPageAndSelect(notebook, new HelpPanel(notebook), wxString::FromUTF8("Помощь"));
}

void MainWindow::AddWelcomePanel()
{
    AddPageAndSelect(notebook,new wxFormBuilder::WelcomePanel(notebook), wxString::FromUTF8("Приветствие"));
}

void MainWindow::ShowLoggedInState()
{
    ShowLogoutPanel();
    debtorsButton->Enable();
    readersButton->Enable();
}

void MainWindow::ShowLoggedOutState()
{
    ShowLoginPanel();
    debtorsButton->Disable();
    readersButton->Disable();
}
