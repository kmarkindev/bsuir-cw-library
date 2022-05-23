#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/ReadersRepository.h>
#include <Windows/EntityViewPanel.h>
#include <Windows/Books/BookViewPanel.h>

class ReaderViewPanel : public EntityViewPanel<wxFormBuilder::ReaderViewPanel>
{
public:
    explicit ReaderViewPanel(wxWindow* parent, std::uint64_t id);

    static wxString GetPanelName();

protected:
    void ShowLoggedInState() override;
    void ShowLoggedOutState() override;
    void OnSaveButtonClicked(wxCommandEvent& event) override;

private:
    ReadersRepository _repo;
};
