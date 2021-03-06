#pragma once

#include "Windows/EntityList.h"
#include "Windows/WxBuilder/WxBuilder.h"
#include "Repository/AuthorsRepository.h"
#include "AuthorCreationPanel.h"
#include "AuthorsFilter.h"
#include "AuthorViewPanel.h"

class AuthorsListPanel : public EntityList<AuthorsFilter, AuthorCreationPanel, AuthorViewPanel>
{
public:
    explicit AuthorsListPanel(wxWindow* parent);
protected:
    AuthorsRepository _repo;
    wxVector<wxVector<wxVariant>> GetRows(AuthorsFilter* filter) override;
    void RemoveRow(std::uint64_t id) override;
};
