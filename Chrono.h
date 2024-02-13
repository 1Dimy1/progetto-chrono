//]
// Created by dimy1 on 12/02/24.
//

#ifndef PROGETTO_CHRONO_CHRONO_H
#define PROGETTO_CHRONO_CHRONO_H

#include <wx/wx.h>

class Chrono : public wxPanel{
public:
    Chrono(wxWindow *parent);
private:
    wxTimer chronoTimer;

    wxStaticText *chronoDisplay;
    wxButton *start_stop_resume;
    wxButton *reset;
    wxString state; //"Init, Running, Stopped"

    int hh = 0;
    int mm = 0;
    int ss = 0;
    int cents = 0;

    int totalCents = 0;

    void updateChrono();
    void OnUpdateChrono(wxTimerEvent &event);
    void OnReset(wxCommandEvent &event);
    void OnStartStopResume(wxCommandEvent &event);

};


#endif //PROGETTO_CHRONO_CHRONO_H
