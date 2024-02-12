//
// Created by dimy1 on 12/02/24.
//

#include "Timer_Chrono_panel.h"

enum{
    ID_timerButton = 10,
    ID_chronoButton = 11,
};

Timer_Chrono_panel::Timer_Chrono_panel(wxWindow *parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize){

    timer = new wxButton(this, ID_timerButton, "Timer", wxPoint(20, 20), wxDefaultSize);
    chrono = new wxButton(this, ID_chronoButton, "Cronometro", wxPoint(100,20), wxSize(100,20) );

    Bind(wxEVT_BUTTON, &Timer_Chrono_panel::OnTimer, this, ID_timerButton);
    Bind(wxEVT_BUTTON, &Timer_Chrono_panel::OnChrono, this, ID_chronoButton);

}

void Timer_Chrono_panel::OnChrono(wxCommandEvent &event) {
    wxPanel *panel = new Chrono(this);
}

void Timer_Chrono_panel::OnTimer(wxCommandEvent &event) {
    wxPanel *panel = new Timer(this);
}