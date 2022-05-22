#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/AuthorsRepository.h>
#include <Windows/EntityViewPanel.h>

class AuthorViewPanel : public EntityViewPanel<wxFormBuilder::AuthorViewPanel>
{
public:
    explicit AuthorViewPanel(wxWindow* parent, std::uint64_t id);

    static wxString GetPanelName();

protected:
    void ShowLoggedInState() override;
    void ShowLoggedOutState() override;
    void OnSaveButtonClicked(wxCommandEvent& event) override;

private:
    AuthorsRepository _repo;
};
