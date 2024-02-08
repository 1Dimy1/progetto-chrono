//
// Created by dimy1 on 08/02/24.
//

#include "Clock.h"

Clock::Clock(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition,wxDefaultSize){

    m_clockDisplay = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    wxFont font = m_clockDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_clockDisplay->SetFont(font);

    updateClock();

    m_clockTimer.Bind(wxEVT_TIMER, &Clock::OnUpdateClock, this);
    m_clockTimer.Start(200);
}

void Clock::updateClock() {
    m_clockDisplay->SetLabel(wxDateTime::Now().FormatTime());
    //m_clockDisplay->SetLabel(wxDateTime::Now().Format("%I:%M:%S %p"));
}

void Clock::OnUpdateClock(wxTimerEvent&) {
    updateClock();
}