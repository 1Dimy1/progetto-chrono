//
// Created by dimy1 on 08/02/24.
//

#ifndef PROGETTO_CHRONO_FRAME_H
#define PROGETTO_CHRONO_FRAME_H

#include <wx/wx.h>
#include <wx/notebook.h>

class Frame : public wxFrame{

public:
    Frame();
private:
    wxNotebook *book;
};


#endif //PROGETTO_CHRONO_FRAME_H
