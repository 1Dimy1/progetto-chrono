//
// Created by dimy1 on 08/02/24.
//

#ifndef PROGETTO_CHRONO_DATETIME_H
#define PROGETTO_CHRONO_DATETIME_H

#include<wx/wx.h>

class DateTime: public wxPanel {
public:
    DateTime(wxWindow* parent);
private:
    wxTimer m_dateClockTimer;
    wxStaticText *m_clockDisplay;
    wxRadioBox *radioClockBox;
    wxString clockFormat;
    wxStaticText *m_dateDisplay;
    wxRadioBox *radioDateBox;
    wxString dateFormat;
    wxBoxSizer *sizer;

    void updateClock();
    void updateDate();
    void OnUpdateDateClock(wxTimerEvent &);
    void OnSelectDateFormat(wxCommandEvent &event);
    void OnSelectTimeFormat(wxCommandEvent &event);
};


#endif //PROGETTO_CHRONO_DATETIME_H
