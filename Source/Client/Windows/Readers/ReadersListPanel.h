#pragma once

#include "Windows/EntityList.h"
#include "Windows/WxBuilder/WxBuilder.h"
#include "Repository/ReadersRepository.h"
#include "ReaderCreationPanel.h"
#include "ReadersFilter.h"
#include <Helpers/DateParser.h>
#include "ReaderViewPanel.h"

class ReadersListPanel : public EntityList<ReadersFilter, ReaderCreationPanel, ReaderViewPanel>
{
public:
    explicit ReadersListPanel(wxWindow* parent);
protected:
    ReadersRepository _repo;
    wxVector<wxVector<wxVariant>> GetRows(ReadersFilter* filter) override;
    void RemoveRow(std::uint64_t id) override;
};
