//]
// Created by dimy1 on 12/02/24.
//

#ifndef PROGETTO_CHRONO_CHRONO_H
#define PROGETTO_CHRONO_CHRONO_H

#include <wx/wx.h>

class Chrono : public wxPanel{
public:
    Chrono(wxWindow *parent);
    void start();
    void stop();
    void resume();
    void reset();
    enum State{Init,Running,Stopped};

    wxButton *getStartStopResume() const;
    wxStaticText *getChronoDisplay() const;
    wxButton *getReset() const;
    State getState() const;
    int getHh() const;
    int getMm() const;
    int getSs() const;
    int getCents() const;
    int getTotalCents() const;

private:

    wxTimer chronoTimer;
    wxStaticText *chronoDisplay;
    wxButton *start_stop_resume;
    wxButton *resetBTN;
    State state; //"Init, Running, Stopped"

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
