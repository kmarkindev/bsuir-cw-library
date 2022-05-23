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
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/radiobut.h>
#include <wx/scrolwin.h>
#include <wx/choice.h>
#include <wx/tglbtn.h>
#include <wx/statbox.h>

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
			virtual void OnPublishersButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnReadersButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnBooksButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnDebtorsButtonClicked( wxCommandEvent& event ) = 0;
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

			EntityCreationPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 504,481 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~EntityCreationPanel();

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

			AuthorViewPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~AuthorViewPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class PublishersListFilter
	///////////////////////////////////////////////////////////////////////////////
	class PublishersListFilter : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText15;

		public:
			wxTextCtrl* publisherName;

			PublishersListFilter( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~PublishersListFilter();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class PublisherCreationFields
	///////////////////////////////////////////////////////////////////////////////
	class PublisherCreationFields : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText18;

		public:
			wxTextCtrl* publisherName;

			PublisherCreationFields( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~PublisherCreationFields();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class PublisherViewPanel
	///////////////////////////////////////////////////////////////////////////////
	class PublisherViewPanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText19;
			wxSpinCtrl* publisherId;
			wxStaticText* m_staticText20;
			wxTextCtrl* publisherName;
			wxButton* savePublisher;

			// Virtual event handlers, override them in your derived class
			virtual void OnSaveButtonClicked( wxCommandEvent& event ) = 0;


		public:

			PublisherViewPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~PublisherViewPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class ReadersListFilter
	///////////////////////////////////////////////////////////////////////////////
	class ReadersListFilter : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText15;
			wxStaticText* m_staticText31;
			wxStaticText* m_staticText32;
			wxStaticText* m_staticText34;
			wxStaticText* m_staticText35;
			wxStaticText* m_staticText36;

		public:
			wxTextCtrl* readerName;
			wxTextCtrl* readerAddress;
			wxDatePickerCtrl* readerBirthday;
			wxRadioButton* readerAnySex;
			wxRadioButton* readerMale;
			wxRadioButton* readerFemale;
			wxTextCtrl* readerPhone;
			wxTextCtrl* readerEmail;

			ReadersListFilter( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~ReadersListFilter();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class ReaderCreationFields
	///////////////////////////////////////////////////////////////////////////////
	class ReaderCreationFields : public wxPanel
	{
		private:

		protected:
			wxScrolledWindow* m_scrolledWindow2;
			wxStaticText* m_staticText18;
			wxStaticText* m_staticText31;
			wxStaticText* m_staticText32;
			wxStaticText* m_staticText34;
			wxStaticText* m_staticText52;
			wxStaticText* m_staticText35;
			wxStaticText* m_staticText36;

		public:
			wxTextCtrl* readerName;
			wxTextCtrl* readerAddress;
			wxDatePickerCtrl* readerBirthday;
			wxRadioButton* readerMale;
			wxRadioButton* readerFemale;
			wxTextCtrl* readerPhone;
			wxTextCtrl* readerEmail;

			ReaderCreationFields( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~ReaderCreationFields();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class ReaderViewPanel
	///////////////////////////////////////////////////////////////////////////////
	class ReaderViewPanel : public wxPanel
	{
		private:

		protected:
			wxScrolledWindow* m_scrolledWindow1;
			wxStaticText* m_staticText19;
			wxSpinCtrl* readerId;
			wxStaticText* m_staticText20;
			wxTextCtrl* readerName;
			wxStaticText* m_staticText31;
			wxTextCtrl* readerAddress;
			wxStaticText* m_staticText32;
			wxDatePickerCtrl* readerBirthday;
			wxStaticText* m_staticText34;
			wxRadioButton* readerMale;
			wxRadioButton* readerFemale;
			wxStaticText* m_staticText52;
			wxStaticText* m_staticText35;
			wxTextCtrl* readerPhone;
			wxStaticText* m_staticText36;
			wxTextCtrl* readerEmail;
			wxButton* saveReader;

			// Virtual event handlers, override them in your derived class
			virtual void OnSaveButtonClicked( wxCommandEvent& event ) = 0;


		public:

			ReaderViewPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~ReaderViewPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BooksListFilter
	///////////////////////////////////////////////////////////////////////////////
	class BooksListFilter : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText15;
			wxStaticText* m_staticText113;
			wxStaticText* m_staticText114;
			wxStaticText* m_staticText115;
			wxStaticText* m_staticText144;
			wxToggleButton* m_toggleBtn1;

			// Virtual event handlers, override them in your derived class
			virtual void OnListsRefreshClicked( wxCommandEvent& event ) = 0;


		public:
			wxTextCtrl* bookName;
			wxChoice* authorChoice;
			wxChoice* publisherChoice;
			wxDatePickerCtrl* bookPublishedAt;
			wxChoice* bookFile;

			BooksListFilter( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~BooksListFilter();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BookCreationFields
	///////////////////////////////////////////////////////////////////////////////
	class BookCreationFields : public wxPanel
	{
		private:

		protected:
			wxScrolledWindow* m_scrolledWindow2;
			wxStaticText* m_staticText15;
			wxStaticText* m_staticText113;
			wxStaticText* m_staticText114;
			wxStaticText* m_staticText115;

		public:
			wxTextCtrl* bookName;
			wxChoice* authorChoice;
			wxChoice* publisherChoice;
			wxDatePickerCtrl* bookPublishedAt;

			BookCreationFields( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~BookCreationFields();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class BookViewPanel
	///////////////////////////////////////////////////////////////////////////////
	class BookViewPanel : public wxPanel
	{
		private:

		protected:
			wxScrolledWindow* m_scrolledWindow1;
			wxStaticText* m_staticText145;
			wxSpinCtrl* bookId;
			wxStaticText* m_staticText15;
			wxStaticText* m_staticText113;
			wxChoice* authorChoice;
			wxStaticText* m_staticText114;
			wxChoice* publisherChoice;
			wxStaticText* m_staticText115;
			wxDatePickerCtrl* bookPublishedAt;
			wxButton* saveBook;
			wxButton* downloadFile;
			wxButton* uploadFile;
			wxDataViewListCtrl* instancesList;
			wxButton* addInstance;
			wxButton* withdrawInstance;
			wxButton* returnInstance;
			wxButton* removeInstance;

			// Virtual event handlers, override them in your derived class
			virtual void OnSaveButtonClicked( wxCommandEvent& event ) = 0;
			virtual void OnFileDownloadClicked( wxCommandEvent& event ) = 0;
			virtual void OnUploadClicked( wxCommandEvent& event ) = 0;


		public:
			wxTextCtrl* bookName;

			BookViewPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( -1,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~BookViewPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class InstanceWithdrawPanel
	///////////////////////////////////////////////////////////////////////////////
	class InstanceWithdrawPanel : public wxPanel
	{
		private:

		protected:
			wxStaticText* m_staticText146;
			wxChoice* readerChoice;
			wxStaticText* m_staticText147;
			wxSpinCtrl* instanceId;
			wxStaticText* m_staticText148;
			wxDatePickerCtrl* returnAt;
			wxButton* m_button27;

			// Virtual event handlers, override them in your derived class
			virtual void OnWithdrawClicked( wxCommandEvent& event ) = 0;


		public:

			InstanceWithdrawPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 222,-1 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~InstanceWithdrawPanel();

	};

	///////////////////////////////////////////////////////////////////////////////
	/// Class DebtorsListPanel
	///////////////////////////////////////////////////////////////////////////////
	class DebtorsListPanel : public wxPanel
	{
		private:

		protected:
			wxButton* m_button28;
			wxButton* m_button29;
			wxStaticText* m_staticText150;
			wxDataViewListCtrl* list;

			// Virtual event handlers, override them in your derived class
			virtual void RefreshButtonClicked( wxCommandEvent& event ) = 0;
			virtual void ReturnButtonClicked( wxCommandEvent& event ) = 0;


		public:

			DebtorsListPanel( wxWindow* parent, wxWindowID id = wxID_ANY, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 500,300 ), long style = wxTAB_TRAVERSAL, const wxString& name = wxEmptyString );

			~DebtorsListPanel();

	};

} // namespace wxFormBuilder

