#pragma once

#include "WxBuilder/WxBuilder.h"
#include <Windows/ErrorsPanel.h>
#include <Windows/HelpPanel.h>
#include <Windows/LoginPanel.h>
#include <Helpers/NotebookHelper.h>
#include "Windows/Authors/AuthorsListPanel.h"
#include "Windows/Publishers/PublishersListPanel.h"

class MainWindow : public wxFormBuilder::MainWindow
{
public:
    explicit MainWindow();
    ~MainWindow() override;

    void ShowLoggedInState();
    void ShowLoggedOutState();

    void ShowLoginPanel();
    void ShowLogoutPanel();

    void AddWelcomePanel();
    void AddHelpPanel();

    void AddTab(wxWindow* panel, const wxString& title, bool select);

protected:
    void OnLogoutLinkClicked(wxHyperlinkEvent& event) override;
    void OnLoginLinkClicked(wxHyperlinkEvent& event) override;
    void OnHelpButtonClicked(wxCommandEvent& event) override;
    void OnAuthorsButtonClicked(wxCommandEvent& event) override;
    void OnPublishersButtonClicked(wxCommandEvent& event) override;

private:
    std::uint32_t _loginEventId;
    std::uint32_t _logoutEventId;
    std::uint32_t _apiErrorEventId;
    std::uint32_t _onTabAddEventId;
};
