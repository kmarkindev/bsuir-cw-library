#include "MainWindow.h"

MainWindow::MainWindow()
    : wxFormBuilder::MainWindow(nullptr)
{
    SetIcon(wxICON(IDI_ICON1));

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
        AddTab(new ErrorsPanel(notebook, exception), wxString::FromUTF8("Ошибка"), true);
    });
    _onTabAddEventId = appState.GetOpenPageEvent().Subscribe([this](auto* window, auto str, auto select)
    {
        AddTab(window, str, select);
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
    AddTab(new LoginPanel(notebook), wxString::FromUTF8("Вход"), true);
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
    appState.GetOpenPageEvent().Unsubscribe(_onTabAddEventId);
}

void MainWindow::OnHelpButtonClicked(wxCommandEvent& event)
{
    AddHelpPanel();
}

void MainWindow::AddHelpPanel()
{
    AddTab(new HelpPanel(notebook), wxString::FromUTF8("Помощь"), true);
}

void MainWindow::AddWelcomePanel()
{
    AddTab(new wxFormBuilder::WelcomePanel(notebook), wxString::FromUTF8("Приветствие"), true);
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

void MainWindow::OnAuthorsButtonClicked(wxCommandEvent& event)
{
    auto panel = new AuthorsListPanel(notebook);
    panel->LoadList();
    AddTab(panel, wxString::FromUTF8("Авторы"), true);
}

void MainWindow::AddTab(wxWindow* panel, const wxString& title, bool select)
{
    panel->Reparent(notebook);

    if(select)
        AddPageAndSelect(notebook, panel, title);
    else
        notebook->AddPage(panel, title);
}

void MainWindow::OnPublishersButtonClicked(wxCommandEvent& event)
{
    auto panel = new PublishersListPanel(notebook);
    panel->LoadList();
    AddTab(panel, wxString::FromUTF8("Издатели"), true);
}

void MainWindow::OnReadersButtonClicked(wxCommandEvent& event)
{
    auto panel = new ReadersListPanel(notebook);
    panel->LoadList();
    AddTab(panel, wxString::FromUTF8("Читатели"), true);
}

void MainWindow::OnBooksButtonClicked(wxCommandEvent& event)
{
    auto panel = new BooksListPanel(notebook);
    panel->LoadList();
    AddTab(panel, wxString::FromUTF8("Книги"), true);
}

void MainWindow::OnDebtorsButtonClicked(wxCommandEvent& event)
{
    auto panel = new DebtorsListPanel(notebook);
    AddTab(panel, wxString::FromUTF8("Задолженности"), true);
}
