#pragma once

#include <Windows/WxBuilder/ClientWindows.h>
#include <AppState.h>

class HelpPanel : public wxFormBuilder::HelpPanel
{
public:
    HelpPanel(wxWindow* parent);
};
