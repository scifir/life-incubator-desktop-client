#include "./incubation_queue_panel.hpp"

#include <wx/arrstr.h>

#include <wx/mediactrl.h>

#ifdef IS_UNIX
	#include "extra/wxVLCMain.h"
#endif

using namespace std;

namespace life_incubator
{
	incubation_queue_panel::incubation_queue_panel() : wxPanel()
	{}

	incubation_queue_panel::incubation_queue_panel(wxWindow* new_parent, wxWindowID new_id) : wxPanel(new_parent,new_id)
	{
		list = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(300,200));
		list_sizer = new wxBoxSizer(wxVERTICAL);
		list->SetSizer(list_sizer);
		detail = new wxScrolledWindow(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxVSCROLL);

		incubation_queue_panel_sizer = new wxBoxSizer(wxHORIZONTAL);
		incubation_queue_panel_sizer->Add(list,0,wxEXPAND);
		incubation_queue_panel_sizer->Add(detail,1,wxEXPAND);

		SetSizer(incubation_queue_panel_sizer);
	}

	panel_list::panel_list() : wxPanel()
	{}

	panel_list::panel_list(wxWindow* new_parent, wxWindowID new_id,wxPoint new_position,wxSize new_size) : wxPanel(new_parent,new_id,new_position,new_size)
	{}

	void incubation_queue_panel::add_incubation(const incubation& x_incubation)
	{
		panel_list* incubation_option = new panel_list(list,wxID_ANY,wxDefaultPosition,wxSize(300,200));
		incubation_option->incubation_option_image = new wxStaticBitmap(incubation_option, wxID_ANY, wxBitmap("tests/cobaya-icon.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);
		
		incubation_option->incubation_option_name = new wxStaticText(incubation_option,wxID_ANY,wxString(x_incubation.name));
		incubation_option->incubation_option_status = new wxStaticText(incubation_option,wxID_ANY,wxString(x_incubation.get_status_text()));
		incubation_option->incubation_option_text_sizer = new wxBoxSizer(wxVERTICAL);
		incubation_option->incubation_option_text_sizer->Add(incubation_option->incubation_option_name,0);
		incubation_option->incubation_option_text_sizer->Add(incubation_option->incubation_option_status,0);

		incubation_option->incubation_option_sizer = new wxBoxSizer(wxHORIZONTAL);
		incubation_option->incubation_option_sizer->Add(incubation_option->incubation_option_image,0);
		incubation_option->incubation_option_sizer->Add(incubation_option->incubation_option_text_sizer,0);

		incubation_option->SetSizer(incubation_option->incubation_option_sizer);

		list->GetSizer()->Add(incubation_option);
	}

	void incubation_queue_panel::load_incubation_detail(const incubation& x_incubation)
	{
		wxMediaCtrl* video = new wxMediaCtrl(detail,wxID_ANY,"tests/incubator-example.mp4",wxDefaultPosition,wxSize(1280,1024),wxMC_NO_AUTORESIZE);
		video->ShowPlayerControls(wxMEDIACTRLPLAYERCONTROLS_DEFAULT);
		video->Play();
		video->Lower();
		/*wxVLCFrame *video = new wxVLCFrame(detail,wxID_ANY);
        video->Show();*/
        //SetTopWindow(Frame);
		wxStaticText* incubation_name = new wxStaticText(detail,wxID_ANY,wxString("Green hamster"));
		incubation_name->GetFont().SetPointSize(16.0f);
		wxFont font = incubation_name->GetFont();
		font.SetPointSize(font.GetPointSize() + 10);
		incubation_name->SetFont(font);
		incubation_name->Refresh();
		wxStaticText* incubation_species = new wxStaticText(detail,wxID_ANY,wxString("Phodopus roborovski"));
		wxStaticText* incubation_time = new wxStaticText(detail,wxID_ANY,wxString("2 days / 22 days"));
		wxStaticBitmap* incubation_time_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/time-icon48.png", wxBITMAP_TYPE_PNG));

		wxStaticText* incubator_name = new wxStaticText(detail,wxID_ANY,wxString(x_incubation.incubator->name));

		wxBoxSizer* incubation_sizer = new wxBoxSizer(wxVERTICAL);
		incubation_sizer->Add(incubation_name,0);
		incubation_sizer->Add(incubation_species,0);
		incubation_sizer->Add(incubator_name,0);

		wxBoxSizer* time_sizer = new wxBoxSizer(wxHORIZONTAL);
		time_sizer->Add(incubation_time,0,wxALIGN_CENTER_VERTICAL | wxRIGHT,5);
		time_sizer->Add(incubation_time_icon,0);

		wxBoxSizer* first_detail_sizer = new wxBoxSizer(wxHORIZONTAL);
		first_detail_sizer->Add(incubation_sizer,0);
		first_detail_sizer->Add(time_sizer,0,wxLEFT,200);

		wxBoxSizer* temperature_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* temperature_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/temperature-icon100.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(100,-1));
		wxStaticText* temperature_value = new wxStaticText(detail,wxID_ANY,wxString("33 C"));
		temperature_sizer->Add(temperature_icon,0);
		temperature_sizer->Add(temperature_value,0,wxALIGN_CENTER_VERTICAL | wxLEFT,5);

		wxBoxSizer* nutrients_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* nutrients_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/nutrients-icon100.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(100,-1));
		wxStaticText* nutrients_value = new wxStaticText(detail,wxID_ANY,wxString("80%"));
		nutrients_sizer->Add(nutrients_icon,0);
		nutrients_sizer->Add(nutrients_value,0,wxALIGN_CENTER_VERTICAL | wxLEFT,5);

		wxBoxSizer* blood_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* blood_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/blood-icon100.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(100,-1));
		wxStaticText* blood_value = new wxStaticText(detail,wxID_ANY,wxString("93%"));
		blood_sizer->Add(blood_icon,0);
		blood_sizer->Add(blood_value,0,wxALIGN_CENTER_VERTICAL | wxLEFT,5);

		wxBoxSizer* water_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* water_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/water-icon100.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(100,-1));
		wxStaticText* water_value = new wxStaticText(detail,wxID_ANY,wxString("3 L"));
		water_sizer->Add(water_icon,0);
		water_sizer->Add(water_value,0,wxALIGN_CENTER_VERTICAL | wxLEFT,5);

		wxBoxSizer* energy_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* energy_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/battery-icon100.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(100,-1));
		wxStaticText* energy_value = new wxStaticText(detail,wxID_ANY,wxString("95%"));
		energy_sizer->Add(energy_icon,0);
		energy_sizer->Add(energy_value,0,wxALIGN_CENTER_VERTICAL | wxLEFT,5);

		wxBoxSizer* incubation_parameters_sizer = new wxBoxSizer(wxHORIZONTAL);
		incubation_parameters_sizer->Add(temperature_sizer,0,wxRIGHT,50);
		incubation_parameters_sizer->Add(nutrients_sizer,0,wxRIGHT,50);
		incubation_parameters_sizer->Add(blood_sizer,0,wxRIGHT,50);
		incubation_parameters_sizer->Add(water_sizer,0,wxRIGHT,50);
		incubation_parameters_sizer->Add(energy_sizer,0);

		wxStaticText* dna_filepath = new wxStaticText(detail,wxID_ANY,wxString(x_incubation.dna_filepath));
		wxStaticText* total_chromosomes = new wxStaticText(detail,wxID_ANY,wxString("5 chromosomes"));
		wxStaticText* total_bases = new wxStaticText(detail,wxID_ANY,wxString("2.500.123 bases"));
		wxStaticText* total_genes = new wxStaticText(detail,wxID_ANY,wxString("18.757 genes"));
		wxStaticText* added_genes = new wxStaticText(detail,wxID_ANY,wxString("3 genes added"));
		wxStaticText* modified_genes = new wxStaticText(detail,wxID_ANY,wxString("5 genes modified"));
		wxStaticText* deleted_genes = new wxStaticText(detail,wxID_ANY,wxString("2 genes deleted"));

		wxBoxSizer* detail_sizer = new wxBoxSizer(wxVERTICAL);
		detail_sizer->Add(video,0);
		detail_sizer->Add(first_detail_sizer,0,wxTOP,20);
		detail_sizer->Add(incubation_parameters_sizer,0,wxTOP,20);
		detail_sizer->Add(dna_filepath,0,wxTOP,20);
		detail_sizer->Add(total_chromosomes,0);
		detail_sizer->Add(total_bases,0);
		detail_sizer->Add(total_genes,0);
		detail_sizer->Add(added_genes,0);
		detail_sizer->Add(modified_genes,0);
		detail_sizer->Add(deleted_genes,0);

		detail->SetSizer(detail_sizer);
		detail->SetScrollRate(0,10);
		detail->FitInside();
	}
}