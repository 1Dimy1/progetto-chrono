//
// Created by dimy1 on 26/02/24.
//

#ifndef PROGETTO_CHRONO_TIME_H
#define PROGETTO_CHRONO_TIME_H


#include <wx/wx.h>

class Time {
public:
    Time();
    void updateTime();
    const wxString &getTime() const;
    void setTime(const wxString &time);
    enum Format{h12,h24};
    Format getFormat() const;
    void setFormat(Format format);

private:
    wxTimer m_timeTimer;
    wxString time;
    Format format;

    void OnUpdateTime(wxTimerEvent &);
};


#endif //PROGETTO_CHRONO_TIME_H
