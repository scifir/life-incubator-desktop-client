#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_APP_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_APP_HPP_INCLUDED

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

class main_app: public wxApp
{
    public:
        virtual bool OnInit();
        virtual int OnExit();
};

wxDECLARE_APP(main_app);

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_APP_HPP_INCLUDED
