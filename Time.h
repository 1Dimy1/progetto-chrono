//
// Created by dimy1 on 26/02/24.
//

#ifndef PROGETTO_CHRONO_TIME_H
#define PROGETTO_CHRONO_TIME_H


#include <wx/wx.h>

class Time {
public:
    Time();

    const wxString &getTime() const;
    void setTime(const wxString &time);
    const wxString &getFormat() const;
    void setFormat(const wxString &format);

private:
    wxTimer m_timeTimer;
    wxString time;
    wxString format;

    void updateTime();
    void OnUpdateTime(wxTimerEvent &);
};


#endif //PROGETTO_CHRONO_TIME_H
