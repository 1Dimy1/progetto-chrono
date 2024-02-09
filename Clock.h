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
    wxTimer m_clockTimer;
    wxStaticText *m_clockDisplay;
    wxRadioBox *radioClockBox;
    wxStaticText *m_dateDisplay;
    wxRadioBox *radioDateBox;
    wxString clockFormat;

    void updateClock();
    void OnUpdateClock(wxTimerEvent &);
    void OnSelectTimeFormat(wxCommandEvent &event);
};


#endif //PROGETTO_CHRONO_CLOCK_H
