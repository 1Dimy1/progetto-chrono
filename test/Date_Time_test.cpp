//
// Created by dimy1 on 26/02/24.
//


#include "gtest/gtest.h"
#include "../Frame.h"
#include "../DateTime.h"


class Date_Time_test : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
    Frame *frame;
    DateTime *dt_panel;
};

void Date_Time_test::SetUp() {
    frame = new Frame();
    dt_panel = new DateTime(frame);
}

void Date_Time_test::TearDown() {
    delete frame;
}


TEST_F(Date_Time_test, checkTimeIsCorrect){  //controlla che l'ora sia corretta
    dt_panel->getActualTime()->setFormat(Time::h24);
    ASSERT_EQ(dt_panel->getActualTime()->getTime(), wxDateTime::Now().FormatISOTime());
    dt_panel->getActualTime()->setFormat(Time::h12);
    ASSERT_EQ(dt_panel->getActualTime()->getTime(), wxDateTime::Now().Format("%I:%M:%S %p"));
}

TEST_F(Date_Time_test, checkDateIsCorrect){  //controlla che la data sia corretta
    dt_panel->getActualDate()->setFormat(Date::formato1);
    ASSERT_EQ(dt_panel->getActualDate()->getDate(), wxDateTime::Now().FormatISODate());
    dt_panel->getActualDate()->setFormat(Date::formato2);
    ASSERT_EQ(dt_panel->getActualDate()->getDate(), wxDateTime::Now().Format(wxT("%B %d %Y")));
}