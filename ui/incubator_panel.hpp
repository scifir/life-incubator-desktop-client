#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATOR_PANEL_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATOR_PANEL_HPP_INCLUDED

#include <wx/panel.h>

namespace life_incubator
{
	class incubator_panel : public wxPanel
	{
		public:
			incubator_panel();
			explicit incubator_panel(wxWindow* new_parent, wxWindowID new_id);
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATOR_PANEL_HPP_INCLUDED