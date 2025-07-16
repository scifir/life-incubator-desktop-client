#include "./app.hpp"

#include <string>

#include <wx/splash.h>

#include "./main_frame.hpp"
#include "./task_bar.hpp"

using namespace std;

wxIMPLEMENT_APP(main_app);

bool main_app::OnInit()
{
	wxInitAllImageHandlers();
	wxBitmap bitmap;
	if (bitmap.LoadFile("ui/images/life_incubator_splash_screen.png", wxBITMAP_TYPE_PNG))
	{
		wxSplashScreen* splash = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT, 2000, NULL, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxSTAY_ON_TOP);
		splash->GetSplashWindow()->Centre();
	}
	wxYield();

	SetAppDisplayName("Life incubator desktop client");
	SetAppName("life-incubator-desktop-client");
	SetClassName("app");
	SetVendorDisplayName("Ismael Correa Castro");
	SetVendorName("ismaelcc");

	frame = new life_incubator::main_frame("Life incubator desktop client", wxDefaultPosition, wxSize(2000, 1600),wxDEFAULT_FRAME_STYLE);
	SetTopWindow(frame);

	task_bar = new life_incubator::task_bar();

	wxBitmap icon_bitmap;
	if (icon_bitmap.LoadFile("ui/images/life-incubator-icon128.png", wxBITMAP_TYPE_PNG))
	{
		wxIcon frame_icon;
		frame_icon.CopyFromBitmap(icon_bitmap);
		frame->SetIcon(frame_icon);
	}

	frame->Centre();
	frame->Maximize(true);
	frame->Show(true);
	return true;
}

int main_app::OnExit() {
	frame->Destroy();
	task_bar->Destroy();
	this->wxApp::OnExit();
	return 0;
}