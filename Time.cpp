//
// Created by dimy1 on 26/02/24.
//

#include "Time.h"

enum
{
    ID_updateTime = 101
};


Time::Time(){

    time = "";
    format = "24h";

    updateTime();

    m_timeTimer.Bind(wxEVT_TIMER, &Time::OnUpdateTime, this);
    m_timeTimer.Start(100);
}

void Time::updateTime() {

    if(format == "24h"){
        time = wxDateTime::Now().FormatISOTime();
    }
    else{
        time = wxDateTime::Now().Format("%I:%M:%S %p");
    }
}

void Time::OnUpdateTime(wxTimerEvent &event) {
    updateTime();
}

const wxString &Time::getTime() const {
    return time;
}

void Time::setTime(const wxString &time) {
    Time::time = time;
}

const wxString &Time::getFormat() const {
    return format;
}

void Time::setFormat(const wxString &format) {
    Time::format = format;
    updateTime();
}
