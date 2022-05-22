#pragma once

#include "WxBuilder/WxBuilder.h"
#include <Exceptions/ApiErrorException.h>

class ErrorsPanel : public wxFormBuilder::ErrorsPanel
{
public:
    ErrorsPanel(wxWindow* parent, const ApiErrorException& exception);
};
