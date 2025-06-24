#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_PANEL_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_PANEL_HPP_INCLUDED

#include <wx/panel.h>
#include <wx/htmllbox.h>

namespace life_incubator
{
	class incubation_panel : public wxPanel
	{
		public:
			incubation_panel();
			explicit incubation_panel(wxWindow* new_parent, wxWindowID new_id);

			wxSimpleHtmlListBox* list;
			wxPanel* detail;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_PANEL_HPP_INCLUDED