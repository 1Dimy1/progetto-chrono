//
// Created by dimi on 20/09/2019.
//

#include <iostream>
#include <sys/types.h>
#include <ctime>
#include <chrono>
#include <thread>
#include "Clock.h"

Clock::Clock() {
    createCurrentTime();
}

Clock::~Clock() {}

int Clock::getHour() const {
    return hour;
}

void Clock::setHour(int h) {
    Clock::hour = h;
}

int Clock::getMin() const {
    return min;
}

void Clock::setMin(int m) {
    Clock::min = m;
}

int Clock::getSec() const {
    return sec;
}

void Clock::setSec(int s) {
    Clock::sec = s;
}

int Clock::getDay() const {
    return day;
}

void Clock::setDay(int d) {
    Clock::day = d;
}

int Clock::getMonth() const {
    return month;
}

void Clock::setMonth(int m) {
    Clock::month = m;
}

int Clock::getYear() const {
    return year;
}

void Clock::setYear(int y) {
    Clock::year = y;
}

void Clock::createCurrentTime() {
    std::time_t t = std::time(0);   // get time now
    std::tm* now = std::localtime(&t);
    hour=now->tm_hour;
    min=now->tm_min;
    sec=now->tm_sec;
    day=now->tm_mday;
    month=(now->tm_mon)+1;
    year=(now->tm_year)+1900;
}

void Clock::startClock() {

    while(true){
        createCurrentTime();
        display();
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }



}

void Clock::display() {
    std::cout << "ore:" << hour << std::endl;
    std::cout << "min:" << min << std::endl;
    std::cout << "sec:" << sec << std::endl;

}
