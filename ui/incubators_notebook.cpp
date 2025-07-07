#include "./incubators_notebook.hpp"

#include "./main_frame.hpp"

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

		for (const incubation& x_incubation : life_incubator::incubations)
		{
			incubationQueuePanel->add_incubation(x_incubation);
		}

		for (const incubator& x_incubator : life_incubator::incubators)
		{
			incubatorPanel->add_incubator(x_incubator);
		}

		incubationQueuePanel->load_incubation_detail(life_incubator::incubations[0]);
		incubatorPanel->load_incubator_detail(life_incubator::incubators[0]);
	}
}