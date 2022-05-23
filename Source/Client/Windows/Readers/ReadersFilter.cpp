#include "ReadersFilter.h"

ReadersFilter::ReadersFilter(wxWindow* parent)
    : wxFormBuilder::ReadersListFilter(parent)
{

}

void ReadersFilter::Reset()
{
    readerName->Clear();
    readerAddress->Clear();
    readerAnySex->SetValue(true);
    readerMale->SetValue(false);
    readerFemale->SetValue(false);
    //todo: clear
    //readerBirthday->
    readerPhone->Clear();
    readerEmail->Clear();
}
