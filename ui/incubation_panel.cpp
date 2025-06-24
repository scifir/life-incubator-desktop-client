#include "./incubation_panel.hpp"

#include <wx/arrstr.h>
#include <wx/sizer.h>

using namespace std;

namespace life_incubator
{
	incubation_panel::incubation_panel() : wxPanel()
	{}

	incubation_panel::incubation_panel(wxWindow* new_parent, wxWindowID new_id) : wxPanel(new_parent,new_id)
	{
		wxArrayString choices = wxArrayString();
		choices.Add(wxString("<h2>Choice 1</h2><p>Available</p>"));
		list = new wxSimpleHtmlListBox(this,wxID_ANY,wxDefaultPosition,wxSize(300,100),choices);
		detail = new wxPanel(this,wxID_ANY);

		wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
		horizontal_sizer->Add(list,1);
		horizontal_sizer->Add(detail,2,wxEXPAND);

		wxBoxSizer* vertical_sizer = new wxBoxSizer(wxVERTICAL);
		vertical_sizer->Add(horizontal_sizer,1,wxEXPAND);

		SetSizer(vertical_sizer);
	}
}