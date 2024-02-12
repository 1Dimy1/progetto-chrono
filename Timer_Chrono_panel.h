//
// Created by dimy1 on 12/02/24.
//

#ifndef PROGETTO_CHRONO_TIMER_CHRONO_PANEL_H
#define PROGETTO_CHRONO_TIMER_CHRONO_PANEL_H

#include <wx/wx.h>
#include "Timer.h"
#include "Chrono.h"

class Timer_Chrono_panel : wxPanel{
public:
    Timer_Chrono_panel(wxWindow *parent);
private:
    wxButton *timer;
    wxButton *chrono;

    void OnChrono(wxCommandEvent &event);
    void OnTimer(wxCommandEvent &event);
};



#endif //PROGETTO_CHRONO_TIMER_CHRONO_PANEL_H
