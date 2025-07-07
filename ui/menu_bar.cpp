#include "./menu_bar.hpp"

#include <wx/msgdlg.h>

#ifdef IS_UNIX
	#include <bluetooth/bluetooth.h>
	#include <bluetooth/hci.h>
	#include <bluetooth/hci_lib.h>
#endif

using namespace std;

namespace life_incubator
{
	//wxBEGIN_EVENT_TABLE(menu_bar, wxFrame)
		//EVT_MENU(id::ID_New, menu_bar::OnHello)
		//T_MENU(wxID_EXIT, menu_bar::OnExit)
		//EVT_MENU(wxID_ABOUT, menu_bar::OnAbout)
		//EVT_TREE_ITEM_MENU(ID_DNA_list, menu_bar::OnTreeItemMenu)
		//EVT_MENU(id::MenuItemID, menu_bar::OnMenuItem)
	//wxEND_EVENT_TABLE()

	menu_bar::menu_bar() : wxMenuBar()
	{
		wxMenu *incubationMenu = new wxMenu;
        incubationMenu->Append(1, "&New incubation");
        incubationMenu->AppendSeparator();
        incubationMenu->Append(wxID_EXIT, "&Quit");

        wxMenu *incubatorsMenu = new wxMenu;
        incubatorsMenu->Append(3, "&Detect local incubators");
        incubatorsMenu->Append(4, "&Configure remote network");

		wxMenu *helpMenu = new wxMenu;
		helpMenu->Append(5, "&Search updates");
		helpMenu->Append(6, "&About the incubator");

        this->Append(incubationMenu, "&Incubate");
        this->Append(incubatorsMenu, "&Incubators");
		this->Append(helpMenu, "&Help");

		Bind(wxEVT_MENU, &menu_bar::detect_local_incubators, this, 3);
		Bind(wxEVT_MENU, &menu_bar::OnAbout, this, 6);
	}

	void menu_bar::OnExit(wxCommandEvent& event)
	{
		Close(true);
	}

	void menu_bar::OnAbout(wxCommandEvent& event)
	{
		wxMessageBox("Life Incubator is the desktop client that manages any number of incubator machines, connected locally or by network. Incubators allow the development of embryos that finally become animals.", "About Life Incubator", wxOK | wxICON_INFORMATION);
	}

	void menu_bar::OnHello(wxCommandEvent& event)
	{
		//wxLogMessage("Hello world from wxWidgets!");
	}

	void menu_bar::detect_local_incubators(wxCommandEvent& event)
	{
		wxMessageBox("This is sample message", "Detect local incubators");
		/*int dev_id = hci_get_route(NULL); // Get the ID of the first available Bluetooth adapter
    	if (dev_id < 0)
		{
        	wxMessageBox("No bluetooth adapter found", "Detect local incubators");
    	}
		else
		{
			wxMessageBox("Device ID: " + to_string(dev_id), "Detect local incubators");
		}*/
	}
}
