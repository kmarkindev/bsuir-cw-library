#pragma once

#include <wx/wx.h>

inline std::uint64_t ParseIdFromChoice(wxChoice* choice)
{
    std::uint64_t result;

    auto row = choice->GetStringSelection();
    if(row.empty())
        return 0;

    auto idStr = row.SubString(0, row.find(wxString::FromUTF8(" - ")));
    idStr.ToULongLong(&result);

    return result;
}