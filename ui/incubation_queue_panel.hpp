#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_QUEUE_PANEL_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_QUEUE_PANEL_HPP_INCLUDED

#include <wx/panel.h>
#include <wx/htmllbox.h>
#include <wx/sizer.h>
#include <wx/statbmp.h>
#include "wx/stattext.h"
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

			wxPanel* list;
			wxBoxSizer* list_sizer;
			wxScrolledWindow* detail;
			wxBoxSizer* incubation_queue_panel_sizer;
			//wxMediaCtrl* video;
	};

	class panel_list : public wxPanel
	{
		public:
			panel_list();
			explicit panel_list(wxWindow* new_parent, wxWindowID new_id,wxPoint new_position,wxSize new_size);

			wxStaticBitmap* incubation_option_image;
			wxStaticText* incubation_option_name;
			wxStaticText* incubation_option_status;
			wxBoxSizer* incubation_option_text_sizer;
			wxBoxSizer* incubation_option_sizer;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATION_QUEUE_PANEL_HPP_INCLUDED