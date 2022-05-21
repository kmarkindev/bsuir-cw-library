#include "ErrorsPanel.h"

ErrorsPanel::ErrorsPanel(wxWindow* parent, const ApiErrorException& exception)
    : wxFormBuilder::ErrorsPanel(parent)
{
    errorText->SetLabel(wxString::FromUTF8(exception.GetErrorMessage()));

    for(const auto& detail : exception.GetDetails())
        details->Append(wxString::FromUTF8(detail));
}
