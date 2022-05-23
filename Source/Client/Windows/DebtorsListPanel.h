#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/BookRepository.h>
#include <Repository/ReadersRepository.h>

class DebtorsListPanel : public wxFormBuilder::DebtorsListPanel
{
public:
    DebtorsListPanel(wxWindow* parent);
    void LoadList();

protected:
    void RefreshButtonClicked(wxCommandEvent& event) override;
    void ReturnButtonClicked(wxCommandEvent& event) override;

private:
    BookRepository _bookRepo;
    ReadersRepository _readersRepo;

    std::uint64_t GetSelectedId();
};
