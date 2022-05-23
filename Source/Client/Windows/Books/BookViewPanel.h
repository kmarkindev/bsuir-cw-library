#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/BookRepository.h>
#include <Repository/AuthorsRepository.h>
#include <Repository/PublishersRepository.h>
#include <Windows/EntityViewPanel.h>
#include <Helpers/ChoiceParser.h>

class BookViewPanel : public EntityViewPanel<wxFormBuilder::BookViewPanel>
{
public:
    explicit BookViewPanel(wxWindow* parent, std::uint64_t id);

    static wxString GetPanelName();

protected:
    void ShowLoggedInState() override;
    void ShowLoggedOutState() override;
    void OnSaveButtonClicked(wxCommandEvent& event) override;

private:
    BookRepository _repo;
    AuthorsRepository _authorsRepo;
    PublishersRepository _publishersRepo;
};
