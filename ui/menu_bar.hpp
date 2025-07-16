#ifndef LIFE_INCUBATOR_UI_MENU_BAR_HPP_INCLUDED
#define LIFE_INCUBATOR_UI_MENU_BAR_HPP_INCLUDED

#define _HAS_STD_BYTE 0

#include "wx/frame.h"
#include "wx/menu.h"

#include "wx/listctrl.h"
#include "wx/panel.h"
#include "wx/toolbar.h"
#include "wx/treectrl.h"

#include "./new_incubation_dialog.hpp"

using namespace std;

namespace life_incubator
{
	class menu_bar : public wxMenuBar
	{
		public:
			menu_bar();

		private:
			void OnHello(wxCommandEvent& event);
			void OnExit(wxCommandEvent& event);
			void OnAbout(wxCommandEvent& event);
			void new_incubation(wxCommandEvent& event);
			void detect_local_incubators(wxCommandEvent& event);
			
			new_incubation_dialog* new_incubation_dialog;
			wxMenu* incubationMenu;
			wxMenu* incubatorsMenu;
			wxMenu* helpMenu;
			//wxDECLARE_EVENT_TABLE();
	};
}

#endif // LIFE_INCUBATOR_UI_MENU_BAR_HPP_INCLUDED
