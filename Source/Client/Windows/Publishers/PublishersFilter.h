#pragma once

#include "Windows/WxBuilder/WxBuilder.h"

class PublishersFilter : public wxFormBuilder::PublishersListFilter
{
public:
    explicit PublishersFilter(wxWindow* parent);

    void Reset();
};
