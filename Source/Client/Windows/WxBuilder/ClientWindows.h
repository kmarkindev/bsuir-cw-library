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
#include <wx/dataview.h>
#include <wx/splitter.h>
#include <wx/spinctrl.h>

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

			// Virtual event handlers, override them in your derived class
			virtual void OnAuthorsButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnHelpButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnLoginLinkClicked( wxHyperlinkEvent& event ) = 0;
			virtual void OnLogoutLinkClicked( wxHyperlinkEvent& event ) = 0;


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
			wxPanel* loginPanel;
			wxStaticText* m_staticText26;
			wxTextCtrl* passwordCtrl;
			wxButton* m_button10;
			wxPanel* logoutPanel;
			wxStaticText* m_staticText13;
			wxHyperlinkCtrl* logoutLing;

			// Virtual event handlers, override them in your derived class
			virtual void OnLoginClicked( wxCommandEvent& event ) = 0;
			virtual void OnLogoutClicked( wxHyperlinkEvent& event ) = 0;


		public:

			LoginPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

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

	///////////////////////////////////////////////////////////////////////////////
	/// Class EntityListPanel
	///////////////////////////////////////////////////////////////////////////////
	class EntityListPanel : public wxPanel
	{
		private:

		protected:
			wxButton* refreshButton;
			wxButton* openButton;
			wxButton* createButton;
			wxButton* deleteButton;
			wxStaticText* listName;
			wxSplitterWindow* m_splitter1;
			wxPanel* m_panel10;
			wxPanel* filterPanel;
			wxBoxSizer* filterSizer;
			wxButton* filterApply;
			wxButton* filterReset;
			wxPanel* m_panel9;
			wxDataViewListCtrl* dataList;

			// Virtual event handlers, override them in your derived class
			virtual void OnRefreshButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnOpenButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnCreateButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnDeleteButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnFilterApplyClicked( wxCommandEvent& event ) = 0;
			virtual void OnFilterResetClicked( wxCommandEvent& event ) = 0;


		public:

			EntityListPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 561,351 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~EntityListPanel();

			void m_splitter1OnIdle( wxIdleEvent& )
			{
				m_splitter1->SetSashPosition( 1 );
				m_splitter1->Disconnect( wxEVT_IDLE, wxIdleEventHandler( EntityListPanel::m_splitter1OnIdle ), NULL, this );
			}

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class AuthorsListFilter
	///////////////////////////////////////////////////////////////////////////////
	class AuthorsListFilter : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText15;

		public:
			wxTextCtrl* authorName;

			AuthorsListFilter( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~AuthorsListFilter();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class EntityCreationPanel
	///////////////////////////////////////////////////////////////////////////////
	class EntityCreationPanel : public wxPanel
	{
		private:

		protected:
			wxPanel* fieldsPanel;
			wxBoxSizer* fieldsSizer;
			wxButton* saveButton;

			// Virtual event handlers, override them in your derived class
			virtual void SaveButtonClicked( wxCommandEvent& event ) = 0;


		public:

			EntityCreationPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 518,360 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~EntityCreationPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class AuthorCreationFields
	///////////////////////////////////////////////////////////////////////////////
	class AuthorCreationFields : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText18;

		public:
			wxTextCtrl* authorName;

			AuthorCreationFields( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~AuthorCreationFields();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class AuthorViewPanel
	///////////////////////////////////////////////////////////////////////////////
	class AuthorViewPanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText19;
			wxSpinCtrl* authorId;
			wxStaticText* m_staticText20;
			wxTextCtrl* authorName;
			wxButton* saveAuthor;

			// Virtual event handlers, override them in your derived class
			virtual void OnSaveButtonClicked( wxCommandEvent& event ) = 0;


		public:

			AuthorViewPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 491,374 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~AuthorViewPanel();

	};

} // namespace wxFormBuilder

