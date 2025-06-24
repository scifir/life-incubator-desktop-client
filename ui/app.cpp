#include "./app.hpp"
#include "./main_frame.hpp"

#include <string>

#include <wx/splash.h>

using namespace std;

wxIMPLEMENT_APP(main_app);

bool main_app::OnInit()
{
	wxBitmap bitmap;
	if (bitmap.LoadFile("ui/images/life_incubator_splash_screen.png", wxBITMAP_TYPE_PNG))
	{
		wxSplashScreen* splash = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT, 2000, NULL, -1, wxDefaultPosition, wxDefaultSize, wxBORDER_SIMPLE|wxSTAY_ON_TOP);
		splash->GetSplashWindow()->Centre();
	}
	wxYield();

	SetAppDisplayName("Life Incubator");
	SetAppName("life-incubator");
	SetClassName("app");
	SetVendorDisplayName("Ismael Correa Castro");
	SetVendorName("ismaelcc");

	string filename = "";
	if (main_app::argc > 1)
	{
		filename = string(main_app::argv[1].c_str());
	}

	life_incubator::main_frame *frame = new life_incubator::main_frame(filename,"Life Incubator", wxDefaultPosition, wxSize(2000, 1600),wxDEFAULT_FRAME_STYLE);

	wxBitmap icon_bitmap;
	if (icon_bitmap.LoadFile("ui/images/life_incubator_icon.png", wxBITMAP_TYPE_PNG))
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
	return this->wxApp::OnExit();
}