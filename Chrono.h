//
// Created by dimy1 on 12/02/24.
//

#ifndef PROGETTO_CHRONO_CHRONO_H
#define PROGETTO_CHRONO_CHRONO_H

#include <wx/wx.h>

class Chrono : public wxPanel{
public:
    Chrono(wxWindow *parent);
private:
    wxTimer timerTimer;

    wxButton *timer;
    wxButton *chrono;
    wxButton *start_stop_resume;
    wxButton *reset;

/*
    wxTimePickerCtrl *inputTime;
    wxStaticText *timerDisplay;

    wxString state; //"Init, Running, Stopped"
    bool isGoing;

    int hh = 0;
    int mm = 0;
    int ss = 0;

    int secondsLeft = 0;

    void updateTimer();
    void OnUpdateTimer(wxTimerEvent &event);
    void OnReset(wxCommandEvent &event);
    void OnStartStopResume(wxCommandEvent &event);
*/
};


#endif //PROGETTO_CHRONO_CHRONO_H
