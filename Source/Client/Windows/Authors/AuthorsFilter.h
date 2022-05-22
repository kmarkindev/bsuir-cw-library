#pragma once

#include "Windows/WxBuilder/WxBuilder.h"

class AuthorsFilter : public wxFormBuilder::AuthorsListFilter
{
public:
    explicit AuthorsFilter(wxWindow* parent);

    void Reset();
};
