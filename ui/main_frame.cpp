#include "./main_frame.hpp"

#include "./app.hpp"

#include <sstream>

#include "scifir/biology.hpp"

using namespace std;

namespace life_incubator
{
    wxColour background_colour = wxColour(0, 168, 104);
    wxColour dark_background_colour = wxColour(1, 105, 65);
    wxColour dark_selection_background_colour = wxColour(1, 120, 74);
    wxColour active_line_background_colour = wxColour(1, 145, 90);
	wxColour text_colour = wxColour(255, 255, 255);

	main_frame::main_frame(const string& open_file,const wxString& title, const wxPoint& pos, const wxSize& size, long new_style)
		: wxFrame(NULL, wxID_ANY, title, pos, size, new_style)
	{
        //SetBackgroundColour(background_colour);
        wxIcon bitmap("ui/images/life_incubator_icon.png");
        SetIcon(bitmap);

		menuBar = new menu_bar();
        SetMenuBar(menuBar);

        wxFrame::Bind(wxEVT_MENU, [this](wxCommandEvent& event) {
            Close(true);
        }, wxID_EXIT);

        incubatorsNotebook = new incubators_notebook(this,wxID_ANY);

        wxBoxSizer* horizontal_sizer = new wxBoxSizer(wxHORIZONTAL);

    	wxBoxSizer* main_frame_sizer = new wxBoxSizer(wxVERTICAL);
        main_frame_sizer->Add(incubatorsNotebook,1,wxEXPAND);

        horizontal_sizer->Add(main_frame_sizer,1,wxEXPAND);

		SetSizer(horizontal_sizer);
	}

	void main_frame::OnTreeItemMenu(wxTreeEvent& evt)
    {
        // This event handler creates a new menu and displays
        // it as a popup menu with the wxWindow::PopupMenu function

        wxMenu menu;
        menu.Append(wxID_ANY, "Copy gene");
        menu.Append(wxID_ANY, "Paste gene");

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
        PopupMenu(&menu);

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
}
