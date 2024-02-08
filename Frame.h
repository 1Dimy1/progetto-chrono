//
// Created by dimy1 on 08/02/24.
//

#ifndef PROGETTO_CHRONO_FRAME_H
#define PROGETTO_CHRONO_FRAME_H

#include <wx/wx.h>

class Frame : public wxFrame{

public:
    Frame();

private:
    void OnClock(wxCommandEvent& event);
    void OnTimer(wxCommandEvent& event);
    DECLARE_EVENT_TABLE()
};


#endif //PROGETTO_CHRONO_FRAME_H
