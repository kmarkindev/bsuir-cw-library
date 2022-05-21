#pragma once

#include "WxBuilder/ClientWindows.h"
#include <Exceptions/ApiErrorException.h>

class ErrorsPanel : public wxFormBuilder::ErrorsPanel
{
public:
    ErrorsPanel(wxWindow* parent, const ApiErrorException& exception);
};
