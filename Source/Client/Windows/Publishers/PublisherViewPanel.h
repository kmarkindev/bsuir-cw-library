#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/PublishersRepository.h>
#include <Windows/EntityViewPanel.h>

class PublisherViewPanel : public EntityViewPanel<wxFormBuilder::PublisherViewPanel>
{
public:
    explicit PublisherViewPanel(wxWindow* parent, std::uint64_t id);

    static wxString GetPanelName();

protected:
    void ShowLoggedInState() override;
    void ShowLoggedOutState() override;
    void OnSaveButtonClicked(wxCommandEvent& event) override;

private:
    PublishersRepository _repo;
};
