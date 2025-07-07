#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_APP_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_APP_HPP_INCLUDED

#define _HAS_STD_BYTE 0

#define wxUSE_COMPILER_TLS 1
//#define wxUSE_LONGLONG 0
//#define wxUSE_STD_CONTAINERS_COMPATIBLY 0

//#include "msvc/setup_inc.h"
//#include "C:\Programas\wxWidgets-3.3.0\setup.h.in"

#define __WXMSW__
//#define NDEBUG
#define WXUSINGDLL

#define wxUSE_ON_FATAL_EXCEPTION 1

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class main_app: public wxApp
{
    public:
        virtual bool OnInit() override;
        virtual int OnExit();
};

wxDECLARE_APP(main_app);

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_APP_HPP_INCLUDED
