#pragma once

#include "Windows/EntityList.h"
#include "Windows/WxBuilder/WxBuilder.h"
#include "Repository/PublishersRepository.h"
#include "PublisherCreationPanel.h"
#include "PublishersFilter.h"
#include "PublisherViewPanel.h"

class PublishersListPanel : public EntityList<PublishersFilter, PublisherCreationPanel, PublisherViewPanel>
{
public:
    explicit PublishersListPanel(wxWindow* parent);
protected:
    PublishersRepository _repo;
    wxVector<wxVector<wxVariant>> GetRows(PublishersFilter* filter) override;
    void RemoveRow(std::uint64_t id) override;
};
