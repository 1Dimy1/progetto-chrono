//
// Created by dimy1 on 12/02/24.
//

#include "Timer_Chrono_panel.h"

enum{
    ID_timerButton = 10,
    ID_chronoButton = 11,
};

Timer_Chrono_panel::Timer_Chrono_panel(wxWindow *parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize){

    sizer = new wxBoxSizer(wxHORIZONTAL);
    timer = new wxButton(this, ID_timerButton, "Timer", wxDefaultPosition, wxDefaultSize);
    chrono = new wxButton(this, ID_chronoButton, "Cronometro", wxDefaultPosition, wxDefaultSize);
    sizer->Add(timer, 0, wxALL, 5);
    sizer->Add(chrono, 0, wxALL, 5);
    SetSizer(sizer);

    currentPanel = new Timer(this);
    timer->Disable();

    Bind(wxEVT_BUTTON, &Timer_Chrono_panel::OnTimer, this, ID_timerButton);
    Bind(wxEVT_BUTTON, &Timer_Chrono_panel::OnChrono, this, ID_chronoButton);

}

void Timer_Chrono_panel::OnTimer(wxCommandEvent &event) {
    currentPanel->Destroy();
    currentPanel = new Timer(this);
    timer->Disable();
    chrono->Enable();
}

void Timer_Chrono_panel::OnChrono(wxCommandEvent &event) {
    currentPanel->Destroy();
    currentPanel = new Chrono(this);
    chrono->Disable();
    timer->Enable();
}