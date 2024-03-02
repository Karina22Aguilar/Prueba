/***************************************************************
 * Name:      Prueba1Main.h
 * Purpose:   Defines Application Frame
 * Author:     ()
 * Created:   2023-06-09
 * Copyright:  ()
 * License:
 **************************************************************/

#ifndef PRUEBA1MAIN_H
#define PRUEBA1MAIN_H

//(*Headers(Prueba1Frame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
//*)

class Prueba1Frame: public wxFrame
{
    public:

        Prueba1Frame(wxWindow* parent,wxWindowID id = -1);
        virtual ~Prueba1Frame();

    private:

        //(*Handlers(Prueba1Frame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        //*)

        //(*Identifiers(Prueba1Frame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(Prueba1Frame)
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // PRUEBA1MAIN_H
