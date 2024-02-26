//
// Created by dimy1 on 26/02/24.
//

#ifndef PROGETTO_CHRONO_DATE_H
#define PROGETTO_CHRONO_DATE_H

#include <wx/wx.h>

class Date {
public:
    Date();
    const wxString &getDate() const;
    void setDate(const wxString &date);
    const wxString &getFormat() const;
    void setFormat(const wxString &format);
private:
    wxTimer m_dateTimer;
    wxString date;
    wxString format;

    void updateDate();
    void OnUpdateDate(wxTimerEvent &);
};


#endif //PROGETTO_CHRONO_DATE_H
