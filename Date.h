//
// Created by dimy1 on 26/02/24.
//

#ifndef PROGETTO_CHRONO_DATE_H
#define PROGETTO_CHRONO_DATE_H

#include <wx/wx.h>

class Date {
public:
    Date();
    void updateDate();
    const wxString &getDate() const;
    void setDate(const wxString &date);
    enum Format{formato1,formato2};
    Format getFormat() const;
    void setFormat(Format format);
private:
    wxTimer m_dateTimer;
    wxString date;
    Format format;
    void OnUpdateDate(wxTimerEvent &);
};


#endif //PROGETTO_CHRONO_DATE_H
