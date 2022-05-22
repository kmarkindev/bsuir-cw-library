#pragma once

#include "WxBuilder/WxBuilder.h"
#include <AppState.h>
#include <Exceptions/ApiErrorException.h>
#include <Services/Api/AuthService.h>

class LoginPanel : public wxFormBuilder::LoginPanel
{
public:
    explicit LoginPanel(wxWindow* parent);
    ~LoginPanel() override;

    void ShowLoginPanel();
    void ShowLogoutPanel();

protected:
    void OnLoginClicked(wxCommandEvent& event) override;
    void OnLogoutClicked(wxHyperlinkEvent& event) override;

private:
    std::uint32_t _loginEventId;
    std::uint32_t _logoutEventId;
    AuthService _authService;
};
