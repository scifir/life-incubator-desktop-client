#include "./incubator_panel.hpp"

#include <wx/arrstr.h>
#include <wx/sizer.h>

#include <wx/statbmp.h>
#include "wx/stattext.h"

using namespace std;

namespace life_incubator
{
	incubator_panel::incubator_panel() : wxPanel()
	{}

	incubator_panel::incubator_panel(wxWindow* new_parent, wxWindowID new_id) : wxPanel(new_parent,new_id)
	{
		list = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxSize(300,200));
		wxBoxSizer* list_sizer = new wxBoxSizer(wxVERTICAL);
		list->SetSizer(list_sizer);
		detail = new wxScrolledWindow(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxVSCROLL);

		wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
		horizontal_sizer->Add(list,0,wxEXPAND);
		horizontal_sizer->Add(detail,1,wxEXPAND);

		wxBoxSizer* vertical_sizer = new wxBoxSizer(wxVERTICAL);
		vertical_sizer->Add(horizontal_sizer,1,wxEXPAND);

		SetSizer(vertical_sizer);
	}

	void incubator_panel::add_incubator(const incubator& x_incubator)
	{
		wxPanel* incubator_option = new wxPanel(list,wxID_ANY,wxDefaultPosition,wxSize(300,200));
		wxStaticBitmap* incubator_option_image = new wxStaticBitmap(incubator_option, wxID_ANY, wxBitmap("tests/incubator-icon.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);
		
		wxStaticText* incubator_option_name = new wxStaticText(incubator_option,wxID_ANY,wxString(x_incubator.name));
		wxStaticText* incubator_option_status = new wxStaticText(incubator_option,wxID_ANY,wxString(x_incubator.get_status_text()));
		wxBoxSizer* incubator_option_text_sizer = new wxBoxSizer(wxVERTICAL);
		incubator_option_text_sizer->Add(incubator_option_name,0);
		incubator_option_text_sizer->Add(incubator_option_status,0);

		wxBoxSizer* incubator_option_sizer = new wxBoxSizer(wxHORIZONTAL);
		incubator_option_sizer->Add(incubator_option_image,0);
		incubator_option_sizer->Add(incubator_option_text_sizer,0);

		incubator_option->SetSizer(incubator_option_sizer);

		list->GetSizer()->Add(incubator_option);
	}

	void incubator_panel::load_incubator_detail(const incubator& x_incubator)
	{
		wxStaticBitmap* incubator_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("tests/life-incubator.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxDefaultSize);

		wxStaticText* incubator_name = new wxStaticText(detail,wxID_ANY,wxString(x_incubator.name));

		wxStaticText* status = new wxStaticText(detail,wxID_ANY,wxString(x_incubator.get_status_text()));
		
		string nutrients_type_text;
		if (x_incubator.nutrients_injection_type == incubator::NUTRIENTS_FLOW)
		{
			nutrients_type_text = "Incubator of injection by flow";
		}
		else if (x_incubator.nutrients_injection_type == incubator::INDIVIDUAL_NUTRIENTS)
		{
			nutrients_type_text = "Incubator of injection by individual nutrients";
		}
		wxStaticText* incubator_nutrients_type = new wxStaticText(detail,wxID_ANY,wxString(nutrients_type_text));

		wxStaticText* number_incubations = new wxStaticText(detail,wxID_ANY,wxString(to_string(x_incubator.number_incubations) + " incubations done"));

		wxBoxSizer* nutrients_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* nutrients_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/nutrients-icon.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(200,-1));
		wxStaticText* nutrients_value = new wxStaticText(detail,wxID_ANY,wxString("80%"));
		nutrients_sizer->Add(nutrients_icon,0);
		nutrients_sizer->Add(nutrients_value,0);

		wxBoxSizer* blood_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* blood_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/blood-icon.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(200,-1));
		wxStaticText* blood_value = new wxStaticText(detail,wxID_ANY,wxString("93%"));
		blood_sizer->Add(blood_icon,0);
		blood_sizer->Add(blood_value,0);

		wxBoxSizer* water_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* water_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/water-icon.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(200,-1));
		wxStaticText* water_value = new wxStaticText(detail,wxID_ANY,wxString("3 L"));
		water_sizer->Add(water_icon,0);
		water_sizer->Add(water_value,0);

		wxBoxSizer* energy_sizer = new wxBoxSizer(wxHORIZONTAL);
		wxStaticBitmap* energy_icon = new wxStaticBitmap(detail, wxID_ANY, wxBitmap("ui/images/energy-icon.png", wxBITMAP_TYPE_PNG), wxDefaultPosition, wxSize(200,-1));
		wxStaticText* energy_value = new wxStaticText(detail,wxID_ANY,wxString("95%"));
		energy_sizer->Add(energy_icon,0);
		energy_sizer->Add(energy_value,0);

		wxBoxSizer* incubation_parameters_sizer = new wxBoxSizer(wxHORIZONTAL);
		incubation_parameters_sizer->Add(nutrients_sizer,0);
		incubation_parameters_sizer->Add(blood_sizer,0);
		incubation_parameters_sizer->Add(water_sizer,0);
		incubation_parameters_sizer->Add(energy_sizer,0);

		wxBoxSizer* detail_sizer = new wxBoxSizer(wxVERTICAL);
		detail_sizer->Add(incubator_icon,0);
		detail_sizer->Add(incubator_name,0);
		detail_sizer->Add(status,0);
		detail_sizer->Add(incubator_nutrients_type,0);
		detail_sizer->Add(number_incubations,0);
		detail_sizer->Add(incubation_parameters_sizer,0);

		detail->SetSizer(detail_sizer);
		detail->SetScrollRate(0,10);
		detail->FitInside();
	}
}