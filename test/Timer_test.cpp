//
// Created by dimy1 on 16/02/24.
//
#include "gtest/gtest.h"
#include "../Timer.h"
#include "../Frame.h"
#include "../Timer_Chrono_panel.h"
#include <chrono>
#include <thread>

enum State{Init,Running,Stopped};

class Timer_test : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
    Frame *frame;
    Timer_Chrono_panel *t_c_panel;
    Timer *timer;
};

void Timer_test::SetUp() {
    frame = new Frame();
    t_c_panel = new Timer_Chrono_panel(frame);
    timer = new Timer(t_c_panel);
}
void Timer_test::TearDown() {
    delete frame;
}
/*
TEST_F(Timer_test, checkIsInit){  //controlla la corretta inizializzazione del Timer
    ASSERT_EQ(timer->getSecondsLeft(), 0);
    ASSERT_EQ(timer->getSs(), 0);
    ASSERT_EQ(timer->getMm(), 0);
    ASSERT_EQ(timer->getHh(), 0);
    ASSERT_EQ(timer->getSecondsLeft(), 0);
    ASSERT_EQ(timer->getStartStopResume()->GetLabel(), "Start");
    ASSERT_EQ(timer->getTimerDisplay()->GetLabel(), "00:00:00");
    ASSERT_EQ(timer->getState(), Init);
    ASSERT_FALSE(timer->getResetBTN()->IsShown());
    ASSERT_TRUE(timer->getInputTime()->IsEnabled());
}

TEST_F(Timer_test, checkIsRunning){  //controlla il corretto avvio del Timer
    timer->getInputTime()->SetTime(0,1,0);
    timer->start();
    ASSERT_EQ(timer->getStartStopResume()->GetLabel(), "Stop");
    ASSERT_EQ(timer->getState(), Running);
    ASSERT_TRUE(timer->getResetBTN()->IsShown());
    ASSERT_FALSE(timer->getInputTime()->IsEnabled());
}

TEST_F(Timer_test, checkIsStopped){   //controlla il corretto stop del Timer
    timer->getInputTime()->SetTime(0,1,0);
    timer->start();
    timer->stop();
    ASSERT_EQ(timer->getStartStopResume()->GetLabel(), "Resume");
    ASSERT_EQ(timer->getState(), Stopped);
    ASSERT_TRUE(timer->getResetBTN()->IsShown());
    ASSERT_FALSE(timer->getInputTime()->IsEnabled());
}

TEST_F(Timer_test, checkIsResetted){   //controlla il corretto reset del Timer
    timer->reset();
    ASSERT_EQ(timer->getSecondsLeft(), 0);
    ASSERT_EQ(timer->getSs(), 0);
    ASSERT_EQ(timer->getMm(), 0);
    ASSERT_EQ(timer->getHh(), 0);
    ASSERT_EQ(timer->getSecondsLeft(), 0);
    ASSERT_EQ(timer->getStartStopResume()->GetLabel(), "Start");
    ASSERT_EQ(timer->getTimerDisplay()->GetLabel(), "00:00:00");
    ASSERT_EQ(timer->getState(), Init);
    ASSERT_FALSE(timer->getResetBTN()->IsShown());
    ASSERT_TRUE(timer->getInputTime()->IsEnabled());
}
*/
std::time_t getCurrentTime() {
    return std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
}

TEST_F(Timer_test, checkElapsedTimeIsCorrect){   //controlla il corretto scorrimento del tempo

    int j=0;
    timer->getInputTime()->SetTime(0, 0, 3);
    timer->start();

    for(int i=0; i<1000; i++){
        for(int i=0; i<1000; i++){
                j+=i;

        }

    }


    ASSERT_EQ(timer->getSs(), 0);  // Verifica che il timer segnali effettivamente 0 secondi rimanenti
}
