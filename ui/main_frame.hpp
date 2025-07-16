#ifndef LIFE_INCUBATOR_DESKTOP_CLIENT_UI_MAIN_FRAME_HPP_INCLUDED
#define LIFE_INCUBATOR_DESKTOP_CLIENT_UI_MAIN_FRAME_HPP_INCLUDED

#define _HAS_STD_BYTE 0

#include <string>

#include "wx/frame.h"
#include "wx/listctrl.h"
#include "wx/panel.h"
#include "wx/toolbar.h"
#include "wx/treectrl.h"
#include "wx/colour.h"

#include "scifir/biology.hpp"

#include "data/incubation.hpp"
#include "data/incubator.hpp"

#include "./menu_bar.hpp"
#include "./incubators_notebook.hpp"

using namespace std;

namespace life_incubator
{
	enum class id
	{
		ID_New = 1,
		ID_Open,
		ID_Recent,
		ID_Save,
		ID_SaveAll,
		ID_Close,
		ID_CloseAll,
		ID_Explanation,
		ID_Settings,
		ID_Undo,
		ID_Redo,
		ID_Add_Gene,
		ID_Edit_Gene,
		ID_Add_Chromosome,
		ID_Edit_Chromosome,
		ID_DNA_list,
		MenuItemID
	};

	extern wxColour background_colour;
	extern wxColour dark_background_colour;
	extern wxColour dark_selection_background_colour;
	extern wxColour active_line_background_colour;
	extern wxColour text_colour;

	extern vector<incubation> incubations;
	extern vector<incubator> incubators;

	class main_frame: public wxFrame
	{
		public:
			main_frame(const wxString&, const wxPoint&, const wxSize&, long);

			menu_bar* menuBar;
			incubators_notebook* incubatorsNotebook;

		private:
			void OnTreeItemMenu(wxTreeEvent&);
			void OnMenuItem(wxCommandEvent&);
			void OnClose(wxCloseEvent& event);
	};
}

#endif // LIFE_INCUBATOR_DESKTOP_CLIENT_UI_MAIN_FRAME_HPP_INCLUDED
