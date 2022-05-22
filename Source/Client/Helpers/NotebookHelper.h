#pragma once

#include <wx/wx.h>
#include <wx/aui/auibook.h>

inline bool AddPageAndSelect(wxAuiNotebook* notebook, wxWindow* panel, const wxString& tabName)
{
    auto res = notebook->AddPage(panel, tabName);
    auto index = notebook->GetPageIndex(panel);
    notebook->ChangeSelection(index);

    return res;
}