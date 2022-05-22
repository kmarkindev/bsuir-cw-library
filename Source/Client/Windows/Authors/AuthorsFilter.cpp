#include "AuthorsFilter.h"

AuthorsFilter::AuthorsFilter(wxWindow* parent)
    : wxFormBuilder::AuthorsListFilter(parent)
{

}

void AuthorsFilter::Reset()
{
    authorName->Clear();
}
