//
// Created by dimi on 20/09/2019.
//

#ifndef CHRONO_CLOCK_H
#define CHRONO_CLOCK_H


class Clock {
public:


    Clock();
    virtual ~Clock();

    int getHour() const;

    void setHour(int hour);

    int getMin() const;

    void setMin(int min);

    int getSec() const;

    void setSec(int sec);

    int getDay() const;

    void setDay(int day);

    int getMonth() const;

    void setMonth(int month);

    int getYear() const;

    void setYear(int year);


    void startClock();

private:

    void createCurrentTime();
    void display();

    int hour;
    int min;
    int sec;
    int day;
    int month;
    int year;
};


#endif //CHRONO_CLOCK_H
