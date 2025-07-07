#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATOR_PANEL_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATOR_PANEL_HPP_INCLUDED

#include <wx/panel.h>
#include <wx/htmllbox.h>

#include "data/incubator.hpp"

namespace life_incubator
{
	class incubator_panel : public wxPanel
	{
		public:
			incubator_panel();
			explicit incubator_panel(wxWindow* new_parent, wxWindowID new_id);

			void add_incubator(const incubator& x_incubator);
			void load_incubator_detail(const incubator& x_incubator);

			wxPanel* list;
			wxScrolledWindow* detail;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATOR_PANEL_HPP_INCLUDED