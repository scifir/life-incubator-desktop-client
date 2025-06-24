#include "./incubators_notebook.hpp"

using namespace std;

namespace life_incubator
{
	incubators_notebook::incubators_notebook() : wxToolbook()
	{}

	incubators_notebook::incubators_notebook(wxWindow* new_parent, wxWindowID new_id) : wxToolbook(new_parent,new_id)
	{
		incubationQueuePanel = new incubation_queue_panel(this,wxID_ANY);
		AddPage(incubationQueuePanel,"Incubation",true);
		incubatorPanel = new incubator_panel(this,wxID_ANY);
		AddPage(incubatorPanel,"Incubators");
		incubationPanel = new incubation_panel(this,wxID_ANY);
		AddPage(incubationPanel,"Incubations history");

		incubation incubation_example("Green hamster","Phodopus roborovski","C:/Users/iarfe/OneDrive/Escritorio/Iarfen/Proyectos/Ciencia/Laboratorio/life-incubator/desktop-client/tests/dna_example","ismaelc",scifir::time_duration("22 day"),std::chrono::system_clock::now(),"incubator-1",scifir::scalar_unit("20 mL/s"),scifir::temperature("311 K"));
		incubationQueuePanel->load_incubation_detail(incubation_example);

		//wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);
		//horizontal_sizer->Add(treeCtrl,1);
		//horizontal_sizer->Add(genesNotebook,2,wxEXPAND);

		//SetSizer(horizontal_sizer);
	}
}