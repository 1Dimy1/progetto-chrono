//
// Created by dimy1 on 08/02/24.
//

#include "Clock.h"

enum
{
    ID_updateTime = 101,
    ID_updateDate = 102,

    ID_timeFormat = 1,
    ID_dateFormat = 2
};


Clock::Clock(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition,wxDefaultSize){

    m_clockDisplay = new wxStaticText(this, ID_updateTime, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    wxFont font = m_clockDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_clockDisplay->SetFont(font);
    clockFormat = "24h";

    updateClock();

    wxArrayString *selection = new wxArrayString;
    selection->Add("24h");
    selection->Add("12h");
    this->radioClockBox = new wxRadioBox(this, ID_timeFormat, "Seleziona formato ora", wxPoint(20, 20), wxDefaultSize, *selection, 1,  wxRA_SPECIFY_ROWS);

////////////////////////////////////////////////////////////////

    m_dateDisplay = new wxStaticText(this, ID_updateDate, "", wxPoint(20, 60), wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    font = m_dateDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_clockDisplay->SetFont(font);
    dateFormat = "formato1";

    updateDate();

    selection->clear();
    selection->Add("tipo1");
    selection->Add("tipo2");
    this->radioDateBox = new wxRadioBox(this, ID_dateFormat, "Seleziona formato data", wxPoint(20, 80), wxDefaultSize, *selection, 1,  wxRA_SPECIFY_ROWS);







    m_clockTimer.Bind(wxEVT_TIMER, &Clock::OnUpdateClock, this);
    m_dateTimer.Bind(wxEVT_TIMER, &Clock::OnUpdateDate, this);
    m_clockTimer.Start(200);
    m_dateTimer.Start(200);

    Bind(wxEVT_RADIOBOX, &Clock::OnSelectTimeFormat, this, ID_timeFormat);
    Bind(wxEVT_RADIOBOX, &Clock::OnSelectDateFormat, this, ID_dateFormat);

}

void Clock::updateClock() {

    if(clockFormat == "24h"){
        m_clockDisplay->SetLabel(wxDateTime::Now().FormatISOTime());
    }
    else{
        m_clockDisplay->SetLabel(wxDateTime::Now().Format("%I:%M:%S %p"));
    }
}

void Clock::OnUpdateClock(wxTimerEvent &event) {
    updateClock();
}

void Clock::OnSelectTimeFormat(wxCommandEvent &event) {
    if(radioClockBox->GetSelection() == 0){
        clockFormat = "24h";
        updateClock();
    }
    else{
        clockFormat = "12h";
        updateClock();
    }
}
/////////////////////////////////////////////////////////
void Clock::updateDate() {

    if(dateFormat == "formato1"){
        m_dateDisplay->SetLabel(wxDateTime::Now().FormatISODate());
    }
    else{
        m_dateDisplay->SetLabel(wxDateTime::Now().Format(wxT("%B %d %Y")));
    }
}

void Clock::OnUpdateDate(wxTimerEvent &event) {
    updateDate();
}

void Clock::OnSelectDateFormat(wxCommandEvent &event) {
    if(radioDateBox->GetSelection() == 0){
        dateFormat = "formato1";
        updateDate();
    }
    else{
        dateFormat = "formato2";
        updateDate();
    }
}