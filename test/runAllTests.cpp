//
// Created by dimy1 on 15/02/24.
//
#include "gtest/gtest.h"
#include <wx/wx.h>

class AppTest: public wxApp{
public:
    virtual bool OnInit();
    virtual int OnRun();
};

bool AppTest::OnInit() {
    return true;
}

int AppTest::OnRun() {
    ::testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

wxIMPLEMENT_APP(AppTest);