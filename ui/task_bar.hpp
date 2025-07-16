#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_TASK_BAR_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_TASK_BAR_HPP_INCLUDED

#include <wx/taskbar.h>
#include <wx/menu.h>

using namespace std;

namespace life_incubator
{
	class task_bar : public wxTaskBarIcon {
	   public:
		   task_bar();
		   virtual ~task_bar();
	
	   protected:
		   virtual wxMenu* CreatePopupMenu() override;
		   void OnMenuRestore(wxCommandEvent& event);
		   void OnMenuExit(wxCommandEvent& event);
		   void OnLeftClick(wxTaskBarIconEvent& event);
	
		   wxDECLARE_EVENT_TABLE();
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_TASK_BAR_HPP_INCLUDED