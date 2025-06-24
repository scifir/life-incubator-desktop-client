#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_QUEUE_PANEL_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_QUEUE_PANEL_HPP_INCLUDED

#include <wx/panel.h>
#include <wx/htmllbox.h>
//#include <wx/mediactrl.h>

#include "data/incubation.hpp"

namespace life_incubator
{
	class incubation_queue_panel : public wxPanel
	{
		public:
			incubation_queue_panel();
			explicit incubation_queue_panel(wxWindow* new_parent, wxWindowID new_id);

			void add_incubation(const incubation& x_incubation);
			void load_incubation_detail(const incubation& x_incubation);

			wxSimpleHtmlListBox* list;
			wxScrolledWindow* detail;
			//wxMediaCtrl* video;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_QUEUE_PANEL_HPP_INCLUDED