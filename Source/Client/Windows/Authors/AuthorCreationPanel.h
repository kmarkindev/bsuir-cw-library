#pragma once

#include <Windows/EntityCreationPanel.h>
#include <Repository/AuthorsRepository.h>
#include <Windows/Authors/AuthorViewPanel.h>

class AuthorCreationPanel : public EntityCreationPanel<wxFormBuilder::AuthorCreationFields>
{
public:
    explicit AuthorCreationPanel(wxWindow* parent);

    static wxString GetPanelName();

protected:
    void CreateModel() override;

private:
    AuthorsRepository _repo;
};
