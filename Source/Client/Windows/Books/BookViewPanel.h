#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/BookRepository.h>
#include <Repository/AuthorsRepository.h>
#include <Repository/PublishersRepository.h>
#include <Windows/EntityViewPanel.h>
#include <Helpers/ChoiceParser.h>
#include <Windows/InstanceWithdrawPanel.h>
#include <fstream>

class BookViewPanel : public EntityViewPanel<wxFormBuilder::BookViewPanel>
{
public:
    explicit BookViewPanel(wxWindow* parent, std::uint64_t id);
    void ReloadInstances();
    static wxString GetPanelName();

protected:
    void ShowLoggedInState() override;
    void ShowLoggedOutState() override;
    void OnSaveButtonClicked(wxCommandEvent& event) override;
    void OnFileDownloadClicked(wxCommandEvent& event) override;
    void OnUploadClicked(wxCommandEvent& event) override;
    void OnAddInstanceClicked(wxCommandEvent& event) override;
    void OnWithdrawInstanceClicked(wxCommandEvent& event) override;
    void OnReturnInstanceClicked(wxCommandEvent& event) override;
    void OnRemoveInstanceClicked(wxCommandEvent& event) override;
    void OnInstancesUpdateClicked(wxCommandEvent& event) override;

private:
    std::uint64_t _bookId;
    BookRepository _repo;
    AuthorsRepository _authorsRepo;
    PublishersRepository _publishersRepo;

    std::uint64_t GetSelectedInstanceId();
};
