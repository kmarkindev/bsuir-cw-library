#include "MainWindow.h"

MainWindow::MainWindow()
    : wxFormBuilder::MainWindow(nullptr)
{
    ShowLoginPanel();
    notebook->AddPage(new wxFormBuilder::WelcomePanel(notebook), wxString::FromUTF8("Приветствие"));
    notebook->AddPage(new HelpPanel(notebook), wxString::FromUTF8("Помощь"));
}

void MainWindow::ShowLoginPanel()
{
    loginPanel->Show(true);
    logoutPanel->Show(false);
}

void MainWindow::ShowLogoutPanel()
{
    loginPanel->Show(false);
    logoutPanel->Show(true);
}
