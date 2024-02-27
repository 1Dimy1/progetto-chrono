//
// Created by dimy1 on 08/02/24.
//

#ifndef PROGETTO_CHRONO_DATETIME_H
#define PROGETTO_CHRONO_DATETIME_H

#include <wx/wx.h>
#include "Date.h"
#include "Time.h"

class DateTime: public wxPanel {
public:
    DateTime(wxWindow* parent);
    Time *getActualTime() const;
    Date *getActualDate() const;
    void updateClock();
    void updateDate();
private:
    wxTimer m_dateClockTimer;
    Time *actualTime;
    wxStaticText *m_clockDisplay;
    wxRadioBox *radioClockBox;
    Date *actualDate;
    wxStaticText *m_dateDisplay;
    wxRadioBox *radioDateBox;
    wxBoxSizer *sizer;
    void OnUpdateDateClock(wxTimerEvent &);
    void OnSelectDateFormat(wxCommandEvent &event);
    void OnSelectTimeFormat(wxCommandEvent &event);
};


#endif //PROGETTO_CHRONO_DATETIME_H
