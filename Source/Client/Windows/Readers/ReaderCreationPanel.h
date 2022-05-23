#pragma once

#include <Windows/EntityCreationPanel.h>
#include <Repository/ReadersRepository.h>
#include <Windows/Readers/ReaderViewPanel.h>

class ReaderCreationPanel : public EntityCreationPanel<wxFormBuilder::ReaderCreationFields>
{
public:
    explicit ReaderCreationPanel(wxWindow* parent);

    static wxString GetPanelName();

protected:
    void CreateModel() override;

private:
    ReadersRepository _repo;
};
