//
// Created by dimy1 on 15/02/24.
//
#include "gtest/gtest.h"
#include "../Chrono.h"
#include "../Frame.h"
#include "../Timer_Chrono_panel.h"

enum State{Init,Running,Stopped};

class Chrono_test : public ::testing::Test {
protected:
    virtual void SetUp();
    virtual void TearDown();
    Frame *frame;
    Timer_Chrono_panel *t_c_panel;
    Chrono *chrono;
};

void Chrono_test::SetUp() {
    frame = new Frame();
    t_c_panel = new Timer_Chrono_panel(frame);
    chrono = new Chrono(t_c_panel);
}

void Chrono_test::TearDown() {
    delete frame;
}

TEST_F(Chrono_test, checkIsInit){  //controlla la corretta inizializzazione del Cronometro
    ASSERT_EQ(chrono->getCents(), 0);
    ASSERT_EQ(chrono->getSs(), 0);
    ASSERT_EQ(chrono->getMm(), 0);
    ASSERT_EQ(chrono->getHh(), 0);
    ASSERT_EQ(chrono->getTotalCents(), 0);
    ASSERT_EQ(chrono->getStartStopResume()->GetLabel(), "Start");
    ASSERT_EQ(chrono->getChronoDisplay()->GetLabel(), "00:00:00:00");
    ASSERT_EQ(chrono->getState(), Init);
    ASSERT_FALSE(chrono->getResetBTN()->IsShown());
}

TEST_F(Chrono_test, checkIsRunning){  //controlla il corretto avvio del Cronometro
    chrono->start();
    ASSERT_EQ(chrono->getStartStopResume()->GetLabel(), "Stop");
    ASSERT_EQ(chrono->getState(), Running);
    ASSERT_TRUE(chrono->getResetBTN()->IsShown());
}

TEST_F(Chrono_test, checkIsStopped){   //controlla il corretto stop del Cronometro
    chrono->start();
    chrono->stop();
    ASSERT_EQ(chrono->getStartStopResume()->GetLabel(), "Resume");
    ASSERT_EQ(chrono->getState(), Stopped);
    ASSERT_TRUE(chrono->getResetBTN()->IsShown());
}

TEST_F(Chrono_test, checkIsResetted){   //controlla il corretto resetBTN del Cronometro
    chrono->reset();
    ASSERT_EQ(chrono->getCents(), 0);
    ASSERT_EQ(chrono->getSs(), 0);
    ASSERT_EQ(chrono->getMm(), 0);
    ASSERT_EQ(chrono->getHh(), 0);
    ASSERT_EQ(chrono->getTotalCents(), 0);
    ASSERT_EQ(chrono->getStartStopResume()->GetLabel(), "Start");
    ASSERT_EQ(chrono->getChronoDisplay()->GetLabel(), "00:00:00:00");
    ASSERT_EQ(chrono->getState(), Init);
    ASSERT_FALSE(chrono->getResetBTN()->IsShown());
}