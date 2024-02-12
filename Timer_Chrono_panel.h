//
// Created by dimy1 on 12/02/24.
//

#ifndef PROGETTO_CHRONO_TIMER_CHRONO_PANEL_H
#define PROGETTO_CHRONO_TIMER_CHRONO_PANEL_H

#include <wx/wx.h>
#include "Timer.h"
#include "Chrono.h"

class Timer_Chrono_panel : public wxPanel{
public:
    Timer_Chrono_panel(wxWindow *parent);
private:
    wxBoxSizer *sizer;
    wxButton *timer;
    wxButton *chrono;
    wxPanel *currentPanel;

    void OnChrono(wxCommandEvent &event);
    void OnTimer(wxCommandEvent &event);
};



#endif //PROGETTO_CHRONO_TIMER_CHRONO_PANEL_H
