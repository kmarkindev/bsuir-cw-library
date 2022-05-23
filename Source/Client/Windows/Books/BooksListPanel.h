#pragma once

#include "Windows/EntityList.h"
#include "Windows/WxBuilder/WxBuilder.h"
#include "Repository/BookRepository.h"
#include "Repository/AuthorsRepository.h"
#include "Repository/PublishersRepository.h"
#include "BookCreationPanel.h"
#include "BooksFilter.h"
#include <Helpers/DateParser.h>
#include <Helpers/ChoiceParser.h>
#include "BookViewPanel.h"

class BooksListPanel : public EntityList<BooksFilter, BookCreationPanel, BookViewPanel>
{
public:
    explicit BooksListPanel(wxWindow* parent);
protected:
    BookRepository _repo;
    AuthorsRepository _authorsRepo;
    PublishersRepository _publishersRepo;

    wxVector<wxVector<wxVariant>> GetRows(BooksFilter* filter) override;
    void RemoveRow(std::uint64_t id) override;
};
