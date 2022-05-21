///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/gdicmn.h>
#include <wx/aui/auibook.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/sizer.h>
#include <wx/stattext.h>
#include <wx/hyperlink.h>
#include <wx/panel.h>
#include <wx/frame.h>
#include <wx/textctrl.h>
#include <wx/listbox.h>

#include "Header.h"

///////////////////////////////////////////////////////////////////////////

namespace wxFormBuilder
{
	///////////////////////////////////////////////////////////////////////////////
	/// Class MainWindow
	///////////////////////////////////////////////////////////////////////////////
	class MainWindow : public wxFrame
	{
		private:

		protected:
			wxAuiNotebook* notebook;
			wxButton* authorsButton;
			wxButton* publishersButton;
			wxButton* readersButton;
			wxButton* booksButton;
			wxButton* debtorsButton;
			wxButton* helpButton;
			wxPanel* loginPanel;
			wxStaticText* logindesc;
			wxHyperlinkCtrl* m_hyperlink11;
			wxPanel* logoutPanel;
			wxStaticText* logoutdesc;
			wxHyperlinkCtrl* m_hyperlink1;

		public:

			MainWindow( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Библиотека | Kirill Markin 2022"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 685,540 ), long style = wxCAPTION|wxCLOSE_BOX|wxMAXIMIZE_BOX|wxMINIMIZE_BOX|wxRESIZE_BORDER|wxSYSTEM_MENU|wxTAB_TRAVERSAL );

			~MainWindow();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class WelcomePanel
	///////////////////////////////////////////////////////////////////////////////
	class WelcomePanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText15;
			wxStaticText* m_staticText16;

		public:

			WelcomePanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 614,328 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~WelcomePanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class LoginPanel
	///////////////////////////////////////////////////////////////////////////////
	class LoginPanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText26;
			wxTextCtrl* m_textCtrl1;
			wxButton* m_button10;

		public:

			LoginPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~LoginPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class ErrorsPanel
	///////////////////////////////////////////////////////////////////////////////
	class ErrorsPanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText27;
			wxStaticText* errorText;
			wxStaticText* m_staticText30;
			wxListBox* details;

		public:

			ErrorsPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 492,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~ErrorsPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class HelpPanel
	///////////////////////////////////////////////////////////////////////////////
	class HelpPanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText31;
			wxStaticText* m_staticText32;
			wxHyperlinkCtrl* apiUrl;
			wxStaticText* m_staticText34;
			wxStaticText* m_staticText35;

		public:

			HelpPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~HelpPanel();

	};

} // namespace wxFormBuilder

