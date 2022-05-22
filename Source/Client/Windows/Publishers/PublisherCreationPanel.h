#pragma once

#include <Windows/EntityCreationPanel.h>
#include <Repository/PublishersRepository.h>
#include <Windows/Publishers/PublisherViewPanel.h>

class PublisherCreationPanel : public EntityCreationPanel<wxFormBuilder::PublisherCreationFields>
{
public:
    explicit PublisherCreationPanel(wxWindow* parent);

    static wxString GetPanelName();

protected:
    void CreateModel() override;

private:
    PublishersRepository _repo;
};
