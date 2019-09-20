//
// Created by dimi on 20/09/2019.
//

#include <chrono>
#include "Timer.h"
#include <thread>

Timer::Timer() : hour(0), min(0), sec(0), loop(false) {}

Timer::~Timer() {}

int Timer::getHour() const {
    return hour;
}

void Timer::setHour(int h) {
    Timer::hour = h;
}

int Timer::getMin() const {
    return min;
}

void Timer::setMin(int m) {
    Timer::min = m;
}

int Timer::getSec() const {
    return sec;
}

void Timer::setSec(int s) {
    Timer::sec = s;
}

bool Timer::isLoop() const {
    return loop;
}

void Timer::setLoop(bool l) {
    Timer::loop = l;
}




void Timer::timerLoop() {

    while(loop){

        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        sec--;

        if(hour==0 && min==0 && sec==0)
            loop=false;


        if(sec==-1){
            min--;
            sec=59;
        }
        if(min==-1){
            min=59;
            hour--;
        }


        //notifyObserver();

    }
}


void Timer::startTimer() {

    loop=true;

    timerLoop();
}

void Timer::stopTimer() {

    loop=false;
}

void Timer::resetTimer() {

    loop=false;
    hour=0;
    min=0;
    sec=0;
}
