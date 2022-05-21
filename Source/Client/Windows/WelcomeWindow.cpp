#include "WelcomeWindow.h"

WelcomeWindow::WelcomeWindow()
    : wxFrame(nullptr, wxID_ANY, wxString::FromUTF8("Добро пожаловать в билиотеку"), wxDefaultPosition, wxSize(600, 400),
        wxSYSTEM_MENU | wxMINIMIZE_BOX | wxCLOSE_BOX | wxCAPTION | wxCLIP_CHILDREN)
{

}