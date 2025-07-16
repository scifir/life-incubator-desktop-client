#ifndef LIFE_INCUBATOR_UI_NEW_INCUBATION_DIALOG_HPP_INCLUDED
#define LIFE_INCUBATOR_UI_NEW_INCUBATION_DIALOG_HPP_INCLUDED

#include <wx/dialog.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/choice.h>
#include <wx/statbmp.h>
#include <wx/stattext.h>

using namespace std;

namespace life_incubator
{
	class new_incubation_dialog : public wxDialog
	{
		public:
			new_incubation_dialog();

			wxStaticText* dialog_title;
			wxStaticBitmap* incubation_image;
			wxStaticText* animal_name_text;
			wxTextCtrl* animal_name;
			wxStaticText* animal_species_text;
			wxTextCtrl* animal_species;
			wxStaticText* dna_file_text;
			wxButton* dna_file;
			wxStaticText* incubator_text;
			wxChoice* incubator;
			wxStaticText* incubation_time_text;
			wxTextCtrl* incubation_time;
			wxStaticText* nutrients_flow_text;
			wxTextCtrl* nutrients_flow;
			wxStaticText* sensor_registry_interval_text;
			wxTextCtrl* sensor_registry_interval;
			wxButton* incubate_button;
			wxButton* cancel_button;
	};
}

#endif // LIFE_INCUBATOR_UI_NEW_INCUBATION_DIALOG_HPP_INCLUDED