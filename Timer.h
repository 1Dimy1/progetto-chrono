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
    enum State{Init,Running,Stopped};
    void start();
    void stop();
    void resume();
    void reset();

    wxStaticText *getTimerDisplay() const;
    wxTimePickerCtrl *getInputTime() const;
    wxButton *getStartStopResume() const;
    wxButton *getResetBTN() const;
    State getState() const;
    int getHh() const;
    int getMm() const;
    int getSs() const;
    int getSecondsLeft() const;

    void setHh(int hh);
    void setMm(int mm);
    void setSs(int ss);
private:
    wxTimer timerTimer;
    wxStaticText *timerDisplay;
    wxTimePickerCtrl *inputTime;
    wxButton *start_stop_resume;
    wxButton *resetBTN;

    State state; //"Init, Running, Stopped"
    int hh = 0;
    int mm = 0;
    int ss = 0;
    int secondsLeft = 0;

    void updateTimer();
    void OnUpdateTimer(wxTimerEvent &event);
    void OnReset(wxCommandEvent &event);
    void OnStartStopResume(wxCommandEvent &event);

};



#endif //PROGETTO_CHRONO_TIMER_H
