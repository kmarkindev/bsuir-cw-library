#pragma once

#include "WxBuilder/WxBuilder.h"
#include <Windows/ErrorsPanel.h>
#include <Windows/HelpPanel.h>
#include <Windows/LoginPanel.h>
#include <Helpers/NotebookHelper.h>

class MainWindow : public wxFormBuilder::MainWindow
{
public:
    explicit MainWindow();
    ~MainWindow() override;

    void ShowLoginPanel();
    void ShowLogoutPanel();

    void AddWelcomePanel();
    void AddHelpPanel();

protected:
    void OnLogoutLinkClicked(wxHyperlinkEvent& event) override;
    void OnLoginLinkClicked(wxHyperlinkEvent& event) override;
    void OnHelpButtonClicked(wxCommandEvent& event) override;

private:
    std::uint32_t _loginEventId;
    std::uint32_t _logoutEventId;
    std::uint32_t _apiErrorEventId;
};
