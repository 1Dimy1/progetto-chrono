//
// Created by dimy1 on 12/02/24.
//

#include "Timer.h"
#include "Chrono.h"

enum{
    ID_inputTime = 100,
    ID_timerDisplay = 101,
    ID_startStopResumeButton = 120,
    ID_resetButton = 121
};

Timer::Timer(wxWindow *parent): wxPanel(parent, wxID_ANY, wxPoint(0,70), wxSize(500, 500)) {

    timerDisplay = new wxStaticText(this, ID_timerDisplay, "00:00:00", wxPoint(5,0), wxSize(70, 15));
    wxFont font = timerDisplay->GetFont();
    font.MakeBold().MakeLarger();
    timerDisplay->SetFont(font);

    resetBTN = new wxButton(this, ID_resetButton, "Interrompi", wxPoint(90, 0), wxDefaultSize);
    resetBTN->Show(false);

    inputTime = new wxTimePickerCtrl(this, ID_inputTime, wxDefaultDateTime, wxPoint(5,70), wxDefaultSize);
    inputTime->SetTime(0,0,0);

    start_stop_resume = new wxButton(this, ID_startStopResumeButton, "Start", wxPoint(5,110), wxDefaultSize);

    state = Init;


    timerTimer.Bind(wxEVT_TIMER, &Timer::OnUpdateTimer, this);
    Bind(wxEVT_BUTTON, &Timer::OnStartStopResume, this, ID_startStopResumeButton);
    Bind(wxEVT_BUTTON, &Timer::OnReset, this, ID_resetButton);
}

void Timer::updateTimer() {
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
    time += std::to_string(ss);
    timerDisplay->SetLabel(time);
}

void Timer::start() {
    hh = inputTime->GetValue().GetHour();
    mm = inputTime->GetValue().GetMinute();
    ss = inputTime->GetValue().GetSecond();
    secondsLeft = ss + mm*60 + hh*3600;

    if(secondsLeft != 0){
        updateTimer();
        timerTimer.Start(1000);
        state = Running;
        resetBTN->Show(true);
        inputTime->Disable();
        start_stop_resume->SetLabel("Stop");
    }
}

void Timer::stop() {
    timerTimer.Stop();
    state = Stopped;
    start_stop_resume->SetLabel("Resume");
}

void Timer::resume() {
    timerTimer.Start(1000);
    state = Running;
    start_stop_resume->SetLabel("Stop");
}

void Timer::reset() {
    timerTimer.Stop();
    hh = 0;
    mm = 0;
    ss = 0;
    secondsLeft = 0;
    updateTimer();
    state = Init;
    resetBTN->Show(false);
    inputTime->Enable();
    start_stop_resume->SetLabel("Start");
}

void Timer::OnUpdateTimer(wxTimerEvent &event) {
    secondsLeft --;

    hh = (int) (secondsLeft/3600);
    mm = (int) ((secondsLeft - (hh*3600))/60);
    ss = secondsLeft - ((hh*3600) + (mm*60));

    updateTimer();

    if(secondsLeft == 0){
        timerTimer.Stop();
        state = Init;
        resetBTN->Show(false);
        inputTime->Enable();
        start_stop_resume->SetLabel("Start");
    }
}

void Timer::OnStartStopResume(wxCommandEvent &event) {

    if(state == Init) {
        start();
    }else if(state == Running){
        stop();
    }else{
        resume();
    }
}

void Timer::OnReset(wxCommandEvent &event) {
    reset();
}

wxStaticText *Timer::getTimerDisplay() const {
    return timerDisplay;
}

wxTimePickerCtrl *Timer::getInputTime() const {
    return inputTime;
}

wxButton *Timer::getStartStopResume() const {
    return start_stop_resume;
}

wxButton *Timer::getResetBTN() const {
    return resetBTN;
}

Timer::State Timer::getState() const {
    return state;
}

int Timer::getHh() const {
    return hh;
}

int Timer::getMm() const {
    return mm;
}

int Timer::getSs() const {
    return ss;
}

int Timer::getSecondsLeft() const {
    return secondsLeft;
}

void Timer::setHh(int hh) {
    Timer::hh = hh;
}

void Timer::setMm(int mm) {
    Timer::mm = mm;
}

void Timer::setSs(int ss) {
    Timer::ss = ss;
}
