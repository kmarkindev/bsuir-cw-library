#include "InstanceWithdrawPanel.h"

InstanceWithdrawPanel::InstanceWithdrawPanel(wxWindow* parent, std::uint64_t instId)
    : wxFormBuilder::InstanceWithdrawPanel(parent)
{
    instanceId->SetValue(std::to_string(instId));

    auto readers = _repo.GetAll();

    for(auto& reader : readers)
        readerChoice->Append(wxString::FromUTF8(std::to_string(reader.id.value())) + " - " + wxString::FromUTF8(reader.name.value()));
}

void InstanceWithdrawPanel::OnWithdrawClicked(wxCommandEvent& event)
{
    try
    {
        auto instId = instanceId->GetValue();
        auto readerId = ParseIdFromChoice(readerChoice);
        auto returnDate = ParseTime(returnAt->GetValue().Format("%Y-%m-%d").utf8_string());

        _bookRepo.WithdrawBook(instId, readerId, returnDate);
        Close();
    }
    catch(ApiErrorException& ex)
    {
        AppState::GetAppState().GetApiErrorEvent().Notify(ex);
    }
}
