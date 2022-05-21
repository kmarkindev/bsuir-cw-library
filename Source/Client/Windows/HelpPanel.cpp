#include "HelpPanel.h"

HelpPanel::HelpPanel(wxWindow* parent)
    : wxFormBuilder::HelpPanel(parent)
{
    auto config = AppState::GetAppState().GetConfig();
    apiUrl->SetLabel(config.apiUrl);
    apiUrl->SetURL(config.apiUrl);
}
