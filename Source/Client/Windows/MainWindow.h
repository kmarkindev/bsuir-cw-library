#pragma once

#include "WxBuilder/ClientWindows.h"
#include <Windows/ErrorsPanel.h>
#include <Windows/HelpPanel.h>

class MainWindow : public wxFormBuilder::MainWindow
{
public:
    explicit MainWindow();

public:
    void ShowLoginPanel();
    void ShowLogoutPanel();
};
