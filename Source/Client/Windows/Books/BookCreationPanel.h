#pragma once

#include <Windows/EntityCreationPanel.h>
#include <Repository/BookRepository.h>
#include <Repository/AuthorsRepository.h>
#include <Repository/PublishersRepository.h>
#include <Helpers/ChoiceParser.h>
#include <Windows/Readers/ReaderViewPanel.h>

class BookCreationPanel : public EntityCreationPanel<wxFormBuilder::BookCreationFields>
{
public:
    explicit BookCreationPanel(wxWindow* parent);

    static wxString GetPanelName();

protected:
    void CreateModel() override;

private:
    BookRepository _repo;
    AuthorsRepository _authorsRepo;
    PublishersRepository _publishersRepo;
};
