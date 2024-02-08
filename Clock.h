//
// Created by dimy1 on 08/02/24.
//

#ifndef PROGETTO_CHRONO_CLOCK_H
#define PROGETTO_CHRONO_CLOCK_H

#include<wx/wx.h>

class Clock: public wxPanel {
public:
    Clock(wxWindow* parent);
private:
    wxStaticText* m_clockDisplay;
    wxTimer m_clockTimer;
    void updateClock();
    void OnUpdateClock(wxTimerEvent& event);
};


#endif //PROGETTO_CHRONO_CLOCK_H
