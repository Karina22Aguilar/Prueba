/***************************************************************
 * Name:      Prueba1App.cpp
 * Purpose:   Code for Application Class
 * Author:     ()
 * Created:   2023-06-09
 * Copyright:  ()
 * License:
 **************************************************************/

#include "Prueba1App.h"

//(*AppHeaders
#include "Prueba1Main.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(Prueba1App);

bool Prueba1App::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	Prueba1Frame* Frame = new Prueba1Frame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
