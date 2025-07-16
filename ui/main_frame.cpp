#include "./main_frame.hpp"

#include "./app.hpp"

#include <sstream>

#include "scifir/units.hpp"
#include "scifir/biology.hpp"

#include "core/bluetooth.hpp"

using namespace std;

namespace life_incubator
{
    wxColour background_colour = wxColour(0, 168, 104);
    wxColour dark_background_colour = wxColour(1, 105, 65);
    wxColour dark_selection_background_colour = wxColour(1, 120, 74);
    wxColour active_line_background_colour = wxColour(1, 145, 90);
	wxColour text_colour = wxColour(255, 255, 255);

    vector<incubation> incubations = vector<incubation>();
	vector<incubator> incubators = vector<incubator>();

	main_frame::main_frame(const wxString& title, const wxPoint& pos, const wxSize& size, long new_style)
		: wxFrame(nullptr, wxID_ANY, title, pos, size, new_style)
	{
        //SetBackgroundColour(background_colour);
        //wxIcon bitmap("ui/images/life_incubator_icon.png");
        //SetIcon(bitmap);

		menuBar = new menu_bar();
        SetMenuBar(menuBar);

        wxFrame::Bind(wxEVT_MENU, [this](wxCommandEvent& event) {
            Destroy();
        }, wxID_EXIT);

        incubator x_incubator = incubator("Incubator 1",incubator::AVAILABLE,incubator::NUTRIENTS_FLOW,scifir::scalar_unit("3 L"),scifir::scalar_unit("1 L"),scifir::scalar_unit("1 L"),2);
        incubators.push_back(x_incubator);
        incubator y_incubator = incubator("Incubator 2",incubator::INCUBATING,incubator::NUTRIENTS_FLOW,scifir::scalar_unit("3 L"),scifir::scalar_unit("1 L"),scifir::scalar_unit("1 L"),0);
        incubators.push_back(y_incubator);
        incubation incubation_example("Green hamster","Phodopus roborovski","C:/Users/iarfe/OneDrive/Escritorio/Iarfen/Proyectos/Ciencia/Laboratorio/life-incubator/desktop-client/tests/dna_example","ismaelc",scifir::scalar_unit("22 day"),std::chrono::system_clock::now(),make_shared<incubator>(x_incubator),scifir::scalar_unit("20 mL/s"),scifir::scalar_unit("311 K"),incubation::INCUBATING);
        incubations.push_back(incubation_example);

        incubatorsNotebook = new incubators_notebook(this,wxID_ANY);

        wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);

    	wxBoxSizer* main_frame_sizer = new wxBoxSizer(wxVERTICAL);
        main_frame_sizer->Add(incubatorsNotebook,1,wxEXPAND);

        //wxListBox* listBox = new wxListBox(this, wxID_ANY);

        /*wxMessageBox(wxString("List of bluetooth devices"));

        auto devices = ListBluetoothDevices();
        for (const auto& device : devices) {
            listBox->Append(wxString::FromUTF8(std::string(device.name.begin(), device.name.end())));
            wxMessageBox(wxString::FromUTF8(std::string(device.name.begin(), device.name.end())));
        }*/

        //main_frame_sizer->Add(listBox, 1, wxEXPAND | wxALL, 10);

        horizontal_sizer->Add(main_frame_sizer,1,wxEXPAND);

		SetSizer(horizontal_sizer);
	}

	void main_frame::OnTreeItemMenu(wxTreeEvent& evt)
    {
        // This event handler creates a new menu and displays
        // it as a popup menu with the wxWindow::PopupMenu function

        //wxMenu menu;
        //menu.Append(wxID_ANY, "Copy gene");
        //menu.Append(wxID_ANY, "Paste gene");

        // We need to pass some data (the text of the node) to
        // the menu event handler. We create a class that holds
        // the needed data and use the Connect function to
        // associate our event handler with the menu.
    // UserData* userData = new UserData();
        //userData->m_data = m_treeCtrl->GetItemText(evt.GetItem());
        //menu.Connect(MenuItemID, wxEVT_MENU,
            //(wxObjectEventFunction)&WxTreeCtrl3Frame::OnMenuItem,
        //userData, this);

        // Display the menu as a popup menu
        //PopupMenu(&menu);

        evt.Skip();
    }

    void main_frame::OnMenuItem(wxCommandEvent& evt)
    {
        // Display a message with the text of the node
        // the user right-clicked on
        //UserData* userData = dynamic_cast<UserData*>(evt.GetEventUserData());
        //if (userData)
        //{
            wxMessageBox("You clicked on the item");
        //}
    }

    void main_frame::OnClose(wxCloseEvent& event) {
        Destroy(); // Important: properly destroys the window and exits the app if it's the main window
    }
}
