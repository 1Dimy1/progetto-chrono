//
// Created by dimy1 on 08/02/24.
//

#include "Clock.h"

Clock::Clock(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition,wxDefaultSize){

    m_clockDisplay = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    wxFont font = m_clockDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_clockDisplay->SetFont(font);
    clockFormat = "24h";

    updateClock();

    wxArrayString *selection = new wxArrayString;
    selection->Add("24h");
    selection->Add("12h");
/*
    this->radioBox = new wxRadioBox(this, wxID_ANY, "start/stop orologio", wxPoint(20, 20),
                                    wxSize(200, 150), *selection, 1,  wxRA_SPECIFY_COLS);
*/
    this->radioClockBox = new wxRadioBox(this, wxID_ANY, "Seleziona formato ora", wxPoint(20, 20),
                                    wxDefaultSize, *selection, 1,  wxRA_SPECIFY_ROWS);

    Bind(wxEVT_RADIOBOX, &Clock::OnSelectTimeFormat, this);
    m_clockTimer.Bind(wxEVT_TIMER, &Clock::OnUpdateClock, this);
    m_clockTimer.Start(200);


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
    }
    else{
        clockFormat = "12h";
    }
}
