//
// Created by dimy1 on 08/02/24.
//

#include "Timer_Chrono_panel.h"
#include "Frame.h"
#include <wx/notebook.h>
#include "DateTime.h"

enum{
    ID_BOOKCTRL = 100
};

Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Progetto Laboratorio di Programmazione", wxDefaultPosition, wxSize(500,400)){

    book = new wxBookCtrl(this, ID_BOOKCTRL);

    wxPanel *panel = new DateTime(book);
    book->AddPage(panel, _T("Data e Ora"), true);

    panel = new Timer_Chrono_panel(book);
    book->AddPage(panel, _T("Timer - Cronometro"), false);
}
