//
// Created by dimy1 on 08/02/24.
//

#include "Frame.h"
#include <wx/notebook.h>



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
    wxNotebook *book;
    book = new wxBookCtrl(this, BOOKCTRL);

    wxPanel *panel = new wxPanel(book);
    new wxButton( panel, BUTTON1,
                  _T("Button &1"), wxPoint(50,30), wxSize(100,30) );
    new wxButton( panel, BUTTON2,
                  _T("Button &2"), wxPoint(50,80), wxSize(100,30) );
    book->AddPage(panel, _T("Tab1"), true);

    wxString choices[] =
            {
                    _T("Washington"),
                    _T("Adams"),
                    _T("Jefferson"),
                    _T("Madison"),
                    _T("Lincoln"),
                    _T("One"),
                    _T("Two"),
                    _T("Three"),
                    _T("Four")
            };
    panel = new wxPanel(book);
/*
    listbox1 = new wxListBox( panel, LISTBOX1,
                              wxPoint(0,0), wxSize(150,70),
                              9, choices, wxLB_SORT | wxLB_EXTENDED);
     */
    book->AddPage(panel, _T("Tab2"), false);

    panel = new wxPanel(book);

    /*
    wxBoxSizer *mysizer = new wxBoxSizer( wxVERTICAL );
    panel->SetSizer(mysizer);
    textLog = new wxTextCtrl(panel, TEXTBOX1, _T("Log\n"),
                             wxPoint(0, 250), wxSize(100, 50), wxTE_MULTILINE);
    mysizer->Add(textLog, 1, wxEXPAND | wxALL, 5)*/
    book->AddPage(panel, _T("Debug"), false);
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

