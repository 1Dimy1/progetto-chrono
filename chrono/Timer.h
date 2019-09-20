//
// Created by dimi on 20/09/2019.
//

#ifndef CHRONO_TIMER_H
#define CHRONO_TIMER_H


class Timer {

public:

    Timer();

    virtual ~Timer();

    int getHour() const;

    void setHour(int hour);

    int getMin() const;

    void setMin(int min);

    int getSec() const;

    void setSec(int sec);

    bool isLoop() const;

    void setLoop(bool loop);

    void startTimer();

    void stopTimer();

    void resetTimer();






private:
    int hour;
    int min;
    int sec;
    bool loop;
    void timerLoop();
};


#endif //CHRONO_TIMER_H
