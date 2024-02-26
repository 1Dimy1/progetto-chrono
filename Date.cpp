//
// Created by dimy1 on 26/02/24.
//

#include "Date.h"

enum
{
    ID_updateDate = 102
};


Date::Date(){

    date = "";
    format = "formato1";

    updateDate();

    m_dateTimer.Bind(wxEVT_TIMER, &Date::OnUpdateDate, this);
    m_dateTimer.Start(100);
}

void Date::updateDate(){
    if(format == "formato1"){
        date = wxDateTime::Now().FormatISODate();
    }
    else{
        date = wxDateTime::Now().Format(wxT("%B %d %Y"));
    }
}

void Date::OnUpdateDate(wxTimerEvent &event) {
    updateDate();
}

const wxString &Date::getDate() const {
    return date;
}

void Date::setDate(const wxString &date) {
    Date::date = date;
}

const wxString &Date::getFormat() const {
    return format;
}

void Date::setFormat(const wxString &format) {
    Date::format = format;
}
