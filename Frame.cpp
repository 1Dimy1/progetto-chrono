//
// Created by dimy1 on 08/02/24.
//

#include "Frame.h"
#include <wx/notebook.h>
#include "Clock.h"


// Declare some IDs. These are arbitrary.
const int BOOKCTRL = 100;
const int BUTTON1 = 101;
const int BUTTON2 = 102;
const int LISTBOX1 = 103;
const int TEXTBOX1 = 104;
const int FILE_QUIT = wxID_EXIT;
const int HELP_ABOUT = wxID_ABOUT;

// Attach the event handlers. Put this after MyFrame declaration.
BEGIN_EVENT_TABLE(Frame, wxFrame)
                EVT_BUTTON(BUTTON1, Frame::OnClock)
                EVT_BUTTON(BUTTON2, Frame::OnTimer)
END_EVENT_TABLE()







Frame::Frame() : wxFrame(nullptr, wxID_ANY, "Hello World")
{
    wxStaticText* m_clockDisplay;
    wxTimer       m_clockTimer;


    wxNotebook *book;
    book = new wxBookCtrl(this, BOOKCTRL);

    wxPanel *panel = new Clock(book);
    /*
    m_clockDisplay = new wxStaticText(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE_HORIZONTAL | wxST_NO_AUTORESIZE);
    wxFont font = m_clockDisplay->GetFont();
    font.MakeBold().MakeLarger();
    m_clockDisplay->SetFont(font);

    UpdateClock();

    m_clockTimer.Bind(wxEVT_TIMER, &MyFrame::OnUpdateClock, this);
    m_clockTimer.Start(1000);




*/
    book->AddPage(panel, _T("Orologio"), true);





    panel = new wxPanel(book);
    new wxButton( panel, BUTTON1,
                  _T("Button &1"), wxPoint(50,30), wxSize(100,30) );
    new wxButton( panel, BUTTON2,
                  _T("Button &2"), wxPoint(50,80), wxSize(100,30) );
    book->AddPage(panel, _T("Tab2"), false);


}

void Frame::OnClock(wxCommandEvent& event){
    this->SetTitle("Orologio");
    /*
    currentPanel->Destroy();
    currentPanel = new Clock(this);  // se voglio mettere il timer tolgo l'orologio (default)
    */

     // e lo sostituisco con un pannello per il timer
}

void Frame::OnTimer(wxCommandEvent& event){
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
/*
void UpdateClock()
{
    m_clockDisplay->SetLabel(wxDateTime::Now().FormatTime());
}


void OnUpdateClock(wxTimerEvent&)
{
    UpdateClock();
}
 */