//
// Created by dimy1 on 12/02/24.
//

#include "Chrono.h"

enum{
    ID_chronoDisplay = 101,
    ID_startStopResumeButton = 120,
    ID_resetButton = 121
};

Chrono::Chrono(wxWindow *parent) : wxPanel(parent, wxID_ANY, wxPoint(0,70), wxSize(500, 500)) {

    chronoDisplay = new wxStaticText(this, ID_chronoDisplay, "00:00:00:00", wxPoint(5,0), wxSize(100, 15));
    wxFont font = chronoDisplay->GetFont();
    font.MakeBold().MakeLarger();
    chronoDisplay->SetFont(font);

    reset = new wxButton(this, ID_resetButton, "Reset", wxPoint(130,0), wxDefaultSize);
    reset->Show(false);


    start_stop_resume = new wxButton(this, ID_startStopResumeButton, "Start", wxPoint(5,110), wxDefaultSize);

    state = "Init";


    chronoTimer.Bind(wxEVT_TIMER, &Chrono::OnUpdateChrono, this);
    Bind(wxEVT_BUTTON, &Chrono::OnStartStopResume, this, ID_startStopResumeButton);
    Bind(wxEVT_BUTTON, &Chrono::OnReset, this, ID_resetButton);

}

void Chrono::updateChrono(){

    std::string time = "";
    if(hh<10){
        time += "0";
    }
    time += std::to_string(hh) + ":";
    if(mm<10){
        time += "0";
    }
    time += std::to_string(mm) + ":";
    if(ss<10){
        time += "0";
    }
    time += std::to_string(ss) + ":";
    if(cents<10){
        time += "0";
    }
    time += std::to_string(cents);
    chronoDisplay->SetLabel(time);

}
void Chrono::OnUpdateChrono(wxTimerEvent &event){

    totalCents ++;

    hh = (int) (totalCents/360000);
    mm = (int) ((totalCents - (hh*360000))/6000);
    ss = (int) ((totalCents - ((hh*360000) + (mm*6000)))/100);
    cents = totalCents - ((hh*360000) + (mm*6000) + (ss*100));

    updateChrono();
}
void Chrono::OnReset(wxCommandEvent &event){

    chronoTimer.Stop();
    hh = 0;
    mm = 0;
    ss = 0;
    cents = 0;

    totalCents = 0;

    updateChrono();
    state = "Init";
    reset->Show(false);
    start_stop_resume->SetLabel("Start");
}
void Chrono::OnStartStopResume(wxCommandEvent &event){

    if(state == "Init") {
        hh = 0;
        mm = 0;
        ss = 0;
        cents = 0;

        totalCents = 0;

        updateChrono();
        chronoTimer.Start(10);
        state = "Running";
        reset->Show(true);
        start_stop_resume->SetLabel("Stop");

    }else if(state == "Running"){
        chronoTimer.Stop();
        state = "Stopped";
        start_stop_resume->SetLabel("Resume");
    }else{
        chronoTimer.Start(10);
        state = "Running";
        start_stop_resume->SetLabel("Stop");
    }
}