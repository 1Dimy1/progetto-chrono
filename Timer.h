//
// Created by dimy1 on 12/02/24.
//

#ifndef PROGETTO_CHRONO_TIMER_H
#define PROGETTO_CHRONO_TIMER_H

#include <wx/wx.h>
#include <wx/timectrl.h>


class Timer: public wxPanel{
public:
    Timer(wxWindow *parent);
private:
    wxTimer timerTimer;
    wxStaticText *timerDisplay;
    wxTimePickerCtrl *inputTime;
    wxButton *start_stop_resume;
    wxButton *reset;
    wxString state; //"Init, Running, Stopped"
    int hh;
    int mm;
    int ss;
    int secondsLeft;

    void updateTimer();
    void OnUpdateTimer(wxTimerEvent &event);
    void OnReset(wxCommandEvent &event);
    void OnStartStopResume(wxCommandEvent &event);
    void OnChrono(wxCommandEvent &event);
};


#endif //PROGETTO_CHRONO_TIMER_H
