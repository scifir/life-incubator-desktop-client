#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATORS_NOTEBOOK_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATORS_NOTEBOOK_HPP_INCLUDED

#define _HAS_STD_BYTE 0

#include <wx/toolbook.h>

#include "./incubation_queue_panel.hpp"
#include "./incubation_panel.hpp"
#include "./incubator_panel.hpp"

#include "../data/incubation.hpp"

using namespace std;

namespace life_incubator
{
	class incubators_notebook : public wxToolbook
	{
		public:
			incubators_notebook();
			explicit incubators_notebook(wxWindow* new_parent, wxWindowID new_id);

			incubation_queue_panel* incubationQueuePanel;
			incubator_panel* incubatorPanel;
			incubation_panel* incubationPanel;
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_INCUBATORS_NOTEBOOK_HPP_INCLUDED