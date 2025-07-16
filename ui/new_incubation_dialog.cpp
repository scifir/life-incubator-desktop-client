#include "./new_incubation_dialog.hpp"

#include <wx/sizer.h>

using namespace std;

namespace life_incubator
{
	new_incubation_dialog::new_incubation_dialog() : wxDialog(nullptr,wxID_ANY,wxString(""))
	{
		dialog_title = new wxStaticText(this,wxID_ANY,wxString("New incubation"));
		dialog_title->GetFont().SetPointSize(20.0f);
		wxFont font = dialog_title->GetFont();
		font.SetPointSize(font.GetPointSize() + 10);
		dialog_title->SetFont(font);
		dialog_title->Refresh();
		incubation_image = new wxStaticBitmap(this,wxID_ANY,wxBitmap("ui/images/new-incubation-image256.png",wxBITMAP_TYPE_PNG));
		animal_name_text = new wxStaticText(this,wxID_ANY,wxString("Name"));
		animal_name = new wxTextCtrl(this,wxID_ANY,wxString(""),wxDefaultPosition,wxSize(200,-1));
		animal_species_text = new wxStaticText(this,wxID_ANY,wxString("Species"));
		animal_species = new wxTextCtrl(this,wxID_ANY,wxString(""),wxDefaultPosition,wxSize(200,-1));
		dna_file_text = new wxStaticText(this,wxID_ANY,wxString("DNA file"));
		dna_file = new wxButton(this,wxID_ANY,wxString("Select DNA file"));
		incubator_text = new wxStaticText(this,wxID_ANY,wxString("Incubator"));
		incubator = new wxChoice(this,wxID_ANY);
		incubation_time_text = new wxStaticText(this,wxID_ANY,wxString("Incubation time"));
		incubation_time = new wxTextCtrl(this,wxID_ANY,wxString(""),wxDefaultPosition,wxSize(200,-1));
		nutrients_flow_text = new wxStaticText(this,wxID_ANY,wxString("Nutrients flow magnitude"));
		nutrients_flow = new wxTextCtrl(this,wxID_ANY,wxString(""),wxDefaultPosition,wxSize(200,-1));
		sensor_registry_interval_text = new wxStaticText(this,wxID_ANY,wxString("Interval of sensor registry"));
		sensor_registry_interval = new wxTextCtrl(this,wxID_ANY,wxString(""),wxDefaultPosition,wxSize(200,-1));
		incubate_button = new wxButton(this,wxID_OK,wxString("Incubate"),wxDefaultPosition,wxDefaultSize,wxTE_RIGHT);
		cancel_button = new wxButton(this,wxID_CANCEL,wxString("Cancel"),wxDefaultPosition,wxDefaultSize,wxTE_RIGHT);
		
		wxBoxSizer* new_incubation_sizer = new wxBoxSizer(wxVERTICAL);
		new_incubation_sizer->Add(animal_name_text,0);
		new_incubation_sizer->Add(animal_name,0);
		new_incubation_sizer->Add(animal_species_text,0,wxTOP,5);
		new_incubation_sizer->Add(animal_species,0);
		new_incubation_sizer->Add(dna_file_text,0,wxTOP,20);
		new_incubation_sizer->Add(dna_file,0);
		new_incubation_sizer->Add(incubator_text,0,wxTOP,5);
		new_incubation_sizer->Add(incubator,0);
		new_incubation_sizer->Add(incubation_time_text,0,wxTOP,20);
		new_incubation_sizer->Add(incubation_time,0);
		new_incubation_sizer->Add(nutrients_flow_text,0,wxTOP,5);
		new_incubation_sizer->Add(nutrients_flow,0);
		new_incubation_sizer->Add(sensor_registry_interval_text,0,wxTOP,5);
		new_incubation_sizer->Add(sensor_registry_interval,0);
		
		wxBoxSizer* image_sizer = new wxBoxSizer(wxHORIZONTAL);
		image_sizer->Add(incubation_image,0, wxALL, 20);
		image_sizer->Add(new_incubation_sizer,0, wxRIGHT, 20);
		
		wxBoxSizer* button_sizer = new wxBoxSizer(wxHORIZONTAL);
		button_sizer->Add(cancel_button, 0, wxALL, 5);
		button_sizer->Add(incubate_button, 0, wxALL, 5);

		wxBoxSizer* dialog_sizer = new wxBoxSizer(wxVERTICAL);
		dialog_sizer->Add(dialog_title, 0, wxALIGN_CENTER | wxBOTTOM, 20);
		dialog_sizer->Add(image_sizer, 0, wxALL, 5);
        dialog_sizer->Add(button_sizer, 0, wxALIGN_RIGHT | wxALL, 5);

		SetSizerAndFit(dialog_sizer);
        Centre();
		Show(true);
	}
}