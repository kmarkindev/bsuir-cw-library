#pragma once

#include "Windows/WxBuilder/WxBuilder.h"

class ReadersFilter : public wxFormBuilder::ReadersListFilter
{
public:
    explicit ReadersFilter(wxWindow* parent);

    void Reset();
};
