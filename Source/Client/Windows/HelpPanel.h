#pragma once

#include "WxBuilder/WxBuilder.h"
#include <AppState.h>

class HelpPanel : public wxFormBuilder::HelpPanel
{
public:
    HelpPanel(wxWindow* parent);
};
