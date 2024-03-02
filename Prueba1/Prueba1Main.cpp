/***************************************************************
 * Name:      Prueba1Main.cpp
 * Purpose:   Code for Application Frame
 * Author:     ()
 * Created:   2023-06-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Prueba1Main.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(Prueba1Frame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(Prueba1Frame)
const long Prueba1Frame::idMenuQuit = wxNewId();
const long Prueba1Frame::idMenuAbout = wxNewId();
const long Prueba1Frame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Prueba1Frame,wxFrame)
    //(*EventTable(Prueba1Frame)
    //*)
END_EVENT_TABLE()

Prueba1Frame::Prueba1Frame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(Prueba1Frame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Prueba1Frame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&Prueba1Frame::OnAbout);
    //*)
}

Prueba1Frame::~Prueba1Frame()
{
    //(*Destroy(Prueba1Frame)
    //*)
}

void Prueba1Frame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void Prueba1Frame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
