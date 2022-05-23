#pragma once

#include <Windows/WxBuilder/WxBuilder.h>
#include <Repository/ReadersRepository.h>
#include <Repository/BookRepository.h>
#include <AppState.h>
#include <Helpers/ChoiceParser.h>

class InstanceWithdrawPanel : public wxFormBuilder::InstanceWithdrawPanel
{
public:
    InstanceWithdrawPanel(wxWindow* parent, std::uint64_t instanceId);

protected:
    void OnWithdrawClicked(wxCommandEvent& event) override;

private:
    ReadersRepository _repo;
    BookRepository _bookRepo;
};
