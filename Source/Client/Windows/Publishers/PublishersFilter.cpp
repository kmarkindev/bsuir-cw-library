#include "PublishersFilter.h"

PublishersFilter::PublishersFilter(wxWindow* parent)
    : wxFormBuilder::PublishersListFilter(parent)
{

}

void PublishersFilter::Reset()
{
    publisherName->Clear();
}
