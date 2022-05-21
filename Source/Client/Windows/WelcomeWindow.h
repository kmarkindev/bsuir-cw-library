#pragma once

#include <wx/wx.h>
#include <AppState.h>
#include <Windows/WxBuilder/ClientWindows.h>

class WelcomeWindow : public wxFormBuilder::WelcomeWindow
{
public:
    explicit WelcomeWindow();
};
