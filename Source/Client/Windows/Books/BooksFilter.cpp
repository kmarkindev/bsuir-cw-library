#include "BooksFilter.h"

BooksFilter::BooksFilter(wxWindow* parent)
    : wxFormBuilder::BooksListFilter(parent)
{
    Refresh();
}

void BooksFilter::Reset()
{
    bookName->Clear();
    authorChoice->SetSelection(wxNOT_FOUND);
    publisherChoice->SetSelection(wxNOT_FOUND);
    bookPublishedAt->SetValue(wxInvalidDateTime);
    bookFile->Clear();
}

void BooksFilter::OnListsRefreshClicked(wxCommandEvent& event)
{
    Refresh();
}

void BooksFilter::Refresh()
{
    auto authors = _authorsRepo.GetAll();
    auto publishers = _publishersRepo.GetAll();

    authorChoice->Clear();
    authorChoice->Append(wxT(""));
    for(auto& author : authors)
        authorChoice->Append(wxString::FromUTF8(std::to_string(author.id.value()) + " - " + author.name.value()));

    publisherChoice->Clear();
    publisherChoice->Append(wxT(""));
    for(auto& publisher : publishers)
        publisherChoice->Append(wxString::FromUTF8(std::to_string(publisher.id.value()) + " - " + publisher.name.value()));
}
