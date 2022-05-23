#pragma once

#include "Windows/WxBuilder/WxBuilder.h"
#include <Repository/AuthorsRepository.h>
#include <Repository/PublishersRepository.h>

class BooksFilter : public wxFormBuilder::BooksListFilter
{
public:
    explicit BooksFilter(wxWindow* parent);

    void Reset();
    void Refresh();

protected:
    void OnListsRefreshClicked(wxCommandEvent& event) override;

private:
    AuthorsRepository _authorsRepo;
    PublishersRepository _publishersRepo;
};
