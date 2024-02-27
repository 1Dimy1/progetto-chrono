//
// Created by dimy1 on 08/02/24.
//

#include "DateTime.h"

enum
{
    ID_timeFormat = 1,
    ID_dateFormat = 2,
    ID_updateTime = 101,
    ID_updateDate = 102
};


DateTime::DateTime(wxWindow *parent): wxPanel(parent, wxID_ANY, wxDefaultPosition, wxDefaultSize){

    actualDate = new Date();
    actualTime = new Time();

    sizer = new wxBoxSizer(wxVERTICAL);

    m_dateDisplay = new wxStaticText(this, ID_updateDate, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    wxFont font = m_dateDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_dateDisplay->SetFont(font);
    actualDate->setFormat("formato1");

    updateDate();

    wxArrayString *dateSelection = new wxArrayString;
    dateSelection->Add("tipo1");
    dateSelection->Add("tipo2");
    this->radioDateBox = new wxRadioBox(this, ID_dateFormat, "Seleziona formato data", wxPoint(20, 80), wxDefaultSize, *dateSelection, 1,  wxRA_SPECIFY_ROWS);
    delete dateSelection;

    m_clockDisplay = new wxStaticText(this, ID_updateTime, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL);
    font = m_clockDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_clockDisplay->SetFont(font);
    actualTime->setFormat("24h");

    updateClock();

    wxArrayString *selection = new wxArrayString;
    selection->Add("24h");
    selection->Add("12h");
    this->radioClockBox = new wxRadioBox(this, ID_timeFormat, "Seleziona formato ora", wxDefaultPosition, wxDefaultSize, *selection, 1,  wxRA_SPECIFY_ROWS);
    delete selection;

    sizer->Add(m_dateDisplay, 0,  wxALL, 5);
    sizer->Add(radioDateBox, 0, wxALL, 5);
    sizer->Add(m_clockDisplay, 0, wxALL, 5);
    sizer->Add(radioClockBox, 0, wxALL, 5);
    SetSizer(sizer);


    m_dateClockTimer.Bind(wxEVT_TIMER, &DateTime::OnUpdateDateClock, this);
    m_dateClockTimer.Start(50);
    Bind(wxEVT_RADIOBOX, &DateTime::OnSelectTimeFormat, this, ID_timeFormat);
    Bind(wxEVT_RADIOBOX, &DateTime::OnSelectDateFormat, this, ID_dateFormat);

}

void DateTime::updateClock() {
    m_clockDisplay->SetLabel(actualTime->getTime());
}

void DateTime::updateDate() {
    m_dateDisplay->SetLabel(actualDate->getDate());
}

void DateTime::OnUpdateDateClock(wxTimerEvent &event) {
    updateClock();
    updateDate();
}

void DateTime::OnSelectTimeFormat(wxCommandEvent &event) {
    if(radioClockBox->GetSelection() == 0){
        actualTime->setFormat("24h");
        actualTime->updateTime();
        updateClock();
    }
    else{
        actualTime->setFormat("12h");
        actualTime->updateTime();
        updateClock();
    }
}

void DateTime::OnSelectDateFormat(wxCommandEvent &event) {
    if(radioDateBox->GetSelection() == 0){
        actualDate->setFormat("formato1");
        actualDate->updateDate();
        updateDate();
    }
    else{
        actualDate->setFormat("formato2");
        actualDate->updateDate();
        updateDate();
    }
}

Time *DateTime::getActualTime() const {
    return actualTime;
}

Date *DateTime::getActualDate() const {
    return actualDate;
}
