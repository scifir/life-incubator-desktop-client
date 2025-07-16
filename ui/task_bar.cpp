#include "./task_bar.hpp"

using namespace std;

namespace life_incubator
{
	wxBEGIN_EVENT_TABLE(task_bar, wxTaskBarIcon)
    	EVT_MENU(wxID_EXIT, task_bar::OnMenuExit)
    	EVT_TASKBAR_LEFT_DOWN(task_bar::OnLeftClick)
	wxEND_EVENT_TABLE()

	task_bar::task_bar() : wxTaskBarIcon()
    {
        SetIcon(wxIcon("ui/images/life-incubator-task-bar-icon.png",wxBITMAP_TYPE_PNG), "Life incubator desktop client");
        Bind(wxEVT_TASKBAR_LEFT_DOWN, &task_bar::OnLeftClick, this);
    }

    task_bar::~task_bar()
    {
        RemoveIcon();
        Destroy();
    }

     wxMenu* task_bar::CreatePopupMenu() {
         wxMenu *menu = new wxMenu;
         menu->Append(wxID_EXIT, "Exit");
         Bind(wxEVT_MENU, &task_bar::OnMenuExit, this, wxID_EXIT);
         return menu;
     }

     void task_bar::OnMenuExit(wxCommandEvent& event) {
         // Handle exit action
         RemoveIcon();
         Destroy();
         //wxGetApp().ExitMainLoop();
     }

     void task_bar::OnLeftClick(wxTaskBarIconEvent& event) {
         // Handle left-click on the taskbar icon
         // Example: Show/hide the main window
         /*wxFrame* mainFrame = (wxFrame*)wxGetApp().GetTopWindow();
         if (mainFrame) {
             if (mainFrame->IsShown()) {
                 mainFrame->Hide();
             } else {
                 mainFrame->Show();
             }
         }*/
     }
}