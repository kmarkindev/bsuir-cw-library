///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "ClientWindows.h"

///////////////////////////////////////////////////////////////////////////
using namespace wxFormBuilder;

MainWindow::MainWindow( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer3;
	bSizer3 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );

	notebook = new wxAuiNotebook( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxAUI_NB_CLOSE_ON_ALL_TABS|wxAUI_NB_DEFAULT_STYLE );

	bSizer6->Add( notebook, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );

	bSizer7->SetMinSize( wxSize( -1,50 ) );
	authorsButton = new wxButton( this, wxID_ANY, wxT("Авторы"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( authorsButton, 1, wxBOTTOM|wxEXPAND|wxLEFT|wxTOP, 5 );

	publishersButton = new wxButton( this, wxID_ANY, wxT("Издатели"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( publishersButton, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	readersButton = new wxButton( this, wxID_ANY, wxT("Читатели"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( readersButton, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	booksButton = new wxButton( this, wxID_ANY, wxT("Книги"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( booksButton, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	debtorsButton = new wxButton( this, wxID_ANY, wxT("Задолженности"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( debtorsButton, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	helpButton = new wxButton( this, wxID_ANY, wxT("Помощь"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( helpButton, 1, wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );


	bSizer6->Add( bSizer7, 0, wxEXPAND, 5 );


	bSizer3->Add( bSizer6, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	loginPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	logindesc = new wxStaticText( loginPanel, wxID_ANY, wxT("Для открытия всех возможностей нужно "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	logindesc->Wrap( -1 );
	logindesc->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( logindesc, 0, wxALIGN_CENTER_VERTICAL, 5 );

	m_hyperlink11 = new wxHyperlinkCtrl( loginPanel, wxID_ANY, wxT("войти как администратор"), wxT("http://lib.kmarkin.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlink11->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( m_hyperlink11, 0, 0, 5 );


	loginPanel->SetSizer( bSizer41 );
	loginPanel->Layout();
	bSizer41->Fit( loginPanel );
	bSizer5->Add( loginPanel, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );

	logoutPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	logoutdesc = new wxStaticText( logoutPanel, wxID_ANY, wxT("Чтобы перестать быть администратором "), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	logoutdesc->Wrap( -1 );
	logoutdesc->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer4->Add( logoutdesc, 0, wxALIGN_CENTER_VERTICAL, 5 );

	m_hyperlink1 = new wxHyperlinkCtrl( logoutPanel, wxID_ANY, wxT("нажмите сюда"), wxT("http://lib.kmarkin.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlink1->SetFont( wxFont( 9, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer4->Add( m_hyperlink1, 0, 0, 5 );


	logoutPanel->SetSizer( bSizer4 );
	logoutPanel->Layout();
	bSizer4->Fit( logoutPanel );
	bSizer5->Add( logoutPanel, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer3->Add( bSizer5, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer3 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	authorsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnAuthorsButtonClicked ), NULL, this );
	publishersButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnPublishersButtonClicked ), NULL, this );
	readersButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnReadersButtonClicked ), NULL, this );
	booksButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnBooksButtonClicked ), NULL, this );
	debtorsButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnDebtorsButtonClicked ), NULL, this );
	helpButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnHelpButtonClicked ), NULL, this );
	m_hyperlink11->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MainWindow::OnLoginLinkClicked ), NULL, this );
	m_hyperlink1->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MainWindow::OnLogoutLinkClicked ), NULL, this );
}

MainWindow::~MainWindow()
{
	// Disconnect Events
	authorsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnAuthorsButtonClicked ), NULL, this );
	publishersButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnPublishersButtonClicked ), NULL, this );
	readersButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnReadersButtonClicked ), NULL, this );
	booksButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnBooksButtonClicked ), NULL, this );
	debtorsButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnDebtorsButtonClicked ), NULL, this );
	helpButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MainWindow::OnHelpButtonClicked ), NULL, this );
	m_hyperlink11->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MainWindow::OnLoginLinkClicked ), NULL, this );
	m_hyperlink1->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MainWindow::OnLogoutLinkClicked ), NULL, this );

}

WelcomePanel::WelcomePanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Добро пожаловать"), wxDefaultPosition, wxSize( -1,35 ), wxALIGN_CENTER_HORIZONTAL );
	m_staticText15->Wrap( -1 );
	m_staticText15->SetFont( wxFont( 22, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer19->Add( m_staticText15, 0, wxEXPAND, 5 );

	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Для начала работы, нажмите на одну из кнопок ниже"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
	m_staticText16->Wrap( -1 );
	m_staticText16->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer19->Add( m_staticText16, 0, wxALL|wxEXPAND, 5 );


	bSizer18->Add( bSizer19, 1, wxALIGN_CENTER, 5 );


	bSizer17->Add( bSizer18, 1, wxALIGN_CENTER, 5 );


	this->SetSizer( bSizer17 );
	this->Layout();
}

WelcomePanel::~WelcomePanel()
{
}

LoginPanel::LoginPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* loginpanelsizer;
	loginpanelsizer = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );

	loginPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer191;
	bSizer191 = new wxBoxSizer( wxVERTICAL );

	m_staticText26 = new wxStaticText( loginPanel, wxID_ANY, wxT("Чтобы войти, введите пароль администратора:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	m_staticText26->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer191->Add( m_staticText26, 0, wxALL, 5 );

	passwordCtrl = new wxTextCtrl( loginPanel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 300,-1 ), wxTE_PASSWORD );
	passwordCtrl->SetFont( wxFont( 13, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer191->Add( passwordCtrl, 0, wxALL|wxEXPAND, 5 );

	m_button10 = new wxButton( loginPanel, wxID_ANY, wxT("Войти"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button10->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer191->Add( m_button10, 0, wxALL|wxEXPAND, 5 );


	loginPanel->SetSizer( bSizer191 );
	loginPanel->Layout();
	bSizer191->Fit( loginPanel );
	bSizer19->Add( loginPanel, 1, wxALL, 5 );

	logoutPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText13 = new wxStaticText( logoutPanel, wxID_ANY, wxT("Вы уже вошли как администратор, "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	m_staticText13->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer20->Add( m_staticText13, 0, wxBOTTOM|wxLEFT|wxTOP, 5 );

	logoutLing = new wxHyperlinkCtrl( logoutPanel, wxID_ANY, wxT("выйти"), wxT("http://lib.kmarkin.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	logoutLing->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer20->Add( logoutLing, 0, wxBOTTOM|wxRIGHT|wxTOP, 5 );


	logoutPanel->SetSizer( bSizer20 );
	logoutPanel->Layout();
	bSizer20->Fit( logoutPanel );
	bSizer19->Add( logoutPanel, 1, wxALIGN_CENTER|wxALL, 5 );


	loginpanelsizer->Add( bSizer19, 1, wxALIGN_CENTER, 5 );


	bSizer17->Add( loginpanelsizer, 1, wxALIGN_CENTER, 5 );


	this->SetSizer( bSizer17 );
	this->Layout();
	bSizer17->Fit( this );

	// Connect Events
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginPanel::OnLoginClicked ), NULL, this );
	logoutLing->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( LoginPanel::OnLogoutClicked ), NULL, this );
}

LoginPanel::~LoginPanel()
{
	// Disconnect Events
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( LoginPanel::OnLoginClicked ), NULL, this );
	logoutLing->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( LoginPanel::OnLogoutClicked ), NULL, this );

}

ErrorsPanel::ErrorsPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Ошибка: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	m_staticText27->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer40->Add( m_staticText27, 0, wxALIGN_CENTER|wxBOTTOM|wxLEFT|wxTOP, 5 );

	errorText = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	errorText->Wrap( -1 );
	errorText->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer40->Add( errorText, 0, wxBOTTOM|wxRIGHT|wxTOP, 5 );


	bSizer39->Add( bSizer40, 0, wxEXPAND, 5 );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Детали:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	m_staticText30->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer39->Add( m_staticText30, 0, wxLEFT|wxTOP, 5 );

	details = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	details->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer39->Add( details, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer39 );
	this->Layout();
}

ErrorsPanel::~ErrorsPanel()
{
}

HelpPanel::HelpPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Что это такое?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	m_staticText31->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( m_staticText31, 0, wxALL, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Это клиентское приложение, \nпозволяющее работать с удаленным API библиотеки. \nВ данный момент, такой API расположен \nпо следующему адресу:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	m_staticText32->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( m_staticText32, 0, wxALL, 5 );

	apiUrl = new wxHyperlinkCtrl( this, wxID_ANY, wxT("http://some-apt-host.com/"), wxT("http://some-apt-host.com/"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	apiUrl->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( apiUrl, 0, wxALL, 5 );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Как пользоваться программой?"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	m_staticText34->SetFont( wxFont( 14, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( m_staticText34, 0, wxALL, 5 );

	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("Вся рабочая область разделена на вкладки. \nДля открытия новых вкладок, используйте кнопки ниже. \nДля открытия возможности изменения данных, \nа так же просмотра конфиденциальных данных, \nнеобходимо войти как администратор."), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	m_staticText35->SetFont( wxFont( 11, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer41->Add( m_staticText35, 0, wxALL, 5 );


	this->SetSizer( bSizer41 );
	this->Layout();
}

HelpPanel::~HelpPanel()
{
}

EntityListPanel::EntityListPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer23;
	bSizer23 = new wxBoxSizer( wxHORIZONTAL );

	bSizer23->SetMinSize( wxSize( -1,30 ) );
	refreshButton = new wxButton( this, wxID_ANY, wxT("Обновить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( refreshButton, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	openButton = new wxButton( this, wxID_ANY, wxT("Открыть"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( openButton, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	createButton = new wxButton( this, wxID_ANY, wxT("Создать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( createButton, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	deleteButton = new wxButton( this, wxID_ANY, wxT("Удалить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer23->Add( deleteButton, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	listName = new wxStaticText( this, wxID_ANY, wxT("Название списка"), wxDefaultPosition, wxDefaultSize, 0 );
	listName->Wrap( -1 );
	listName->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer23->Add( listName, 0, wxALL, 5 );


	bSizer22->Add( bSizer23, 0, wxALIGN_LEFT|wxTOP, 5 );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxHORIZONTAL );

	m_splitter1 = new wxSplitterWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_3D|wxSP_3DBORDER|wxSP_3DSASH|wxSP_LIVE_UPDATE|wxSP_THIN_SASH );
	m_splitter1->SetSashGravity( 0 );
	m_splitter1->SetSashSize( 10 );
	m_splitter1->Connect( wxEVT_IDLE, wxIdleEventHandler( EntityListPanel::m_splitter1OnIdle ), NULL, this );
	m_splitter1->SetMinimumPaneSize( 100 );

	m_panel10 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	filterPanel = new wxPanel( m_panel10, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	filterPanel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );

	filterSizer = new wxBoxSizer( wxVERTICAL );


	filterPanel->SetSizer( filterSizer );
	filterPanel->Layout();
	filterSizer->Fit( filterPanel );
	bSizer25->Add( filterPanel, 1, wxALL|wxEXPAND, 5 );

	filterApply = new wxButton( m_panel10, wxID_ANY, wxT("Фильтр"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( filterApply, 0, wxALL|wxEXPAND, 5 );

	filterReset = new wxButton( m_panel10, wxID_ANY, wxT("Сбросить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( filterReset, 0, wxALL|wxEXPAND, 5 );


	m_panel10->SetSizer( bSizer25 );
	m_panel10->Layout();
	bSizer25->Fit( m_panel10 );
	m_panel9 = new wxPanel( m_splitter1, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	dataList = new wxDataViewListCtrl( m_panel9, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxDV_HORIZ_RULES|wxDV_SINGLE );
	bSizer33->Add( dataList, 1, wxALL|wxEXPAND, 5 );


	m_panel9->SetSizer( bSizer33 );
	m_panel9->Layout();
	bSizer33->Fit( m_panel9 );
	m_splitter1->SplitVertically( m_panel10, m_panel9, 1 );
	bSizer24->Add( m_splitter1, 1, wxEXPAND, 5 );


	bSizer22->Add( bSizer24, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer22 );
	this->Layout();

	// Connect Events
	refreshButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnRefreshButtonClicked ), NULL, this );
	openButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnOpenButtonClicked ), NULL, this );
	createButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnCreateButtonClicked ), NULL, this );
	deleteButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnDeleteButtonClicked ), NULL, this );
	filterApply->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnFilterApplyClicked ), NULL, this );
	filterReset->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnFilterResetClicked ), NULL, this );
}

EntityListPanel::~EntityListPanel()
{
	// Disconnect Events
	refreshButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnRefreshButtonClicked ), NULL, this );
	openButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnOpenButtonClicked ), NULL, this );
	createButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnCreateButtonClicked ), NULL, this );
	deleteButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnDeleteButtonClicked ), NULL, this );
	filterApply->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnFilterApplyClicked ), NULL, this );
	filterReset->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityListPanel::OnFilterResetClicked ), NULL, this );

}

EntityCreationPanel::EntityCreationPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );

	bSizer40->SetMinSize( wxSize( 200,-1 ) );
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxVERTICAL );

	fieldsPanel = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL );
	fieldsSizer = new wxBoxSizer( wxVERTICAL );


	fieldsPanel->SetSizer( fieldsSizer );
	fieldsPanel->Layout();
	fieldsSizer->Fit( fieldsPanel );
	bSizer41->Add( fieldsPanel, 1, wxEXPAND | wxALL, 5 );


	bSizer40->Add( bSizer41, 1, wxEXPAND, 5 );

	saveButton = new wxButton( this, wxID_ANY, wxT("Создать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( saveButton, 0, wxALL|wxEXPAND, 5 );


	bSizer39->Add( bSizer40, 1, wxEXPAND, 5 );


	bSizer38->Add( bSizer39, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer38 );
	this->Layout();

	// Connect Events
	saveButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityCreationPanel::SaveButtonClicked ), NULL, this );
}

EntityCreationPanel::~EntityCreationPanel()
{
	// Disconnect Events
	saveButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( EntityCreationPanel::SaveButtonClicked ), NULL, this );

}

AuthorsListFilter::AuthorsListFilter( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Имя автора"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer26->Add( m_staticText15, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	authorName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( authorName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer26 );
	this->Layout();
	bSizer26->Fit( this );
}

AuthorsListFilter::~AuthorsListFilter()
{
}

AuthorCreationFields::AuthorCreationFields( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	bSizer42->SetMinSize( wxSize( 250,-1 ) );
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Имя автора"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer42->Add( m_staticText18, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	authorName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( authorName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer42 );
	this->Layout();
	bSizer42->Fit( this );
}

AuthorCreationFields::~AuthorCreationFields()
{
}

AuthorViewPanel::AuthorViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	bSizer47->SetMinSize( wxSize( 250,-1 ) );
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Id автора"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer47->Add( m_staticText19, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	authorId = new wxSpinCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 9999999999, 1 );
	authorId->Enable( false );

	bSizer47->Add( authorId, 0, wxALL|wxEXPAND, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Имя автора"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer47->Add( m_staticText20, 0, wxALL|wxLEFT|wxRIGHT|wxTOP, 5 );

	authorName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( authorName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	bSizer46->Add( bSizer47, 1, wxEXPAND, 5 );

	saveAuthor = new wxButton( this, wxID_ANY, wxT("Сохранить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( saveAuthor, 0, wxALL|wxEXPAND, 5 );


	bSizer44->Add( bSizer46, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer44 );
	this->Layout();
	bSizer44->Fit( this );

	// Connect Events
	saveAuthor->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AuthorViewPanel::OnSaveButtonClicked ), NULL, this );
}

AuthorViewPanel::~AuthorViewPanel()
{
	// Disconnect Events
	saveAuthor->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( AuthorViewPanel::OnSaveButtonClicked ), NULL, this );

}

PublishersListFilter::PublishersListFilter( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Имя издателя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer26->Add( m_staticText15, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	publisherName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( publisherName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer26 );
	this->Layout();
	bSizer26->Fit( this );
}

PublishersListFilter::~PublishersListFilter()
{
}

PublisherCreationFields::PublisherCreationFields( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	bSizer42->SetMinSize( wxSize( 250,-1 ) );
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Имя издателя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer42->Add( m_staticText18, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	publisherName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer42->Add( publisherName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer42 );
	this->Layout();
	bSizer42->Fit( this );
}

PublisherCreationFields::~PublisherCreationFields()
{
}

PublisherViewPanel::PublisherViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	bSizer47->SetMinSize( wxSize( 250,-1 ) );
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Id издателя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer47->Add( m_staticText19, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	publisherId = new wxSpinCtrl( this, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 9999999999, 1 );
	publisherId->Enable( false );

	bSizer47->Add( publisherId, 0, wxALL|wxEXPAND, 5 );

	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Имя издателя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer47->Add( m_staticText20, 0, wxALL|wxLEFT|wxRIGHT|wxTOP, 5 );

	publisherName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( publisherName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	bSizer46->Add( bSizer47, 1, wxEXPAND, 5 );

	savePublisher = new wxButton( this, wxID_ANY, wxT("Сохранить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( savePublisher, 0, wxALL|wxEXPAND, 5 );


	bSizer44->Add( bSizer46, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer44 );
	this->Layout();
	bSizer44->Fit( this );

	// Connect Events
	savePublisher->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PublisherViewPanel::OnSaveButtonClicked ), NULL, this );
}

PublisherViewPanel::~PublisherViewPanel()
{
	// Disconnect Events
	savePublisher->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( PublisherViewPanel::OnSaveButtonClicked ), NULL, this );

}

ReadersListFilter::ReadersListFilter( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Имя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer26->Add( m_staticText15, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( readerName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Адрес"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer26->Add( m_staticText31, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerAddress = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( readerAddress, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Дата рождения"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer26->Add( m_staticText32, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerBirthday = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_ALLOWNONE|wxDP_DEFAULT|wxDP_DROPDOWN );
	bSizer26->Add( readerBirthday, 0, wxALL, 5 );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Пол"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer26->Add( m_staticText34, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerAnySex = new wxRadioButton( this, wxID_ANY, wxT("любой"), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer26->Add( readerAnySex, 0, wxLEFT|wxRIGHT, 5 );

	readerMale = new wxRadioButton( this, wxID_ANY, wxT("муж."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( readerMale, 0, wxLEFT|wxRIGHT, 5 );

	readerFemale = new wxRadioButton( this, wxID_ANY, wxT("жен."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( readerFemale, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

	m_staticText35 = new wxStaticText( this, wxID_ANY, wxT("Телефон"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer26->Add( m_staticText35, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerPhone = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( readerPhone, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText36 = new wxStaticText( this, wxID_ANY, wxT("Почта (Email)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer26->Add( m_staticText36, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerEmail = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( readerEmail, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer26 );
	this->Layout();
	bSizer26->Fit( this );
}

ReadersListFilter::~ReadersListFilter()
{
}

ReaderCreationFields::ReaderCreationFields( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );

	bSizer53->SetMinSize( wxSize( 250,-1 ) );
	m_staticText18 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Имя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer53->Add( m_staticText18, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	readerName = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( readerName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText31 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Адрес"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer53->Add( m_staticText31, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	readerAddress = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( readerAddress, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText32 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Дата рождения"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer53->Add( m_staticText32, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	readerBirthday = new wxDatePickerCtrl( m_scrolledWindow2, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_ALLOWNONE|wxDP_DEFAULT|wxDP_DROPDOWN );
	bSizer53->Add( readerBirthday, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText34 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Пол"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer53->Add( m_staticText34, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	readerMale = new wxRadioButton( m_scrolledWindow2, wxID_ANY, wxT("муж."), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer53->Add( readerMale, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	readerFemale = new wxRadioButton( m_scrolledWindow2, wxID_ANY, wxT("жен."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( readerFemale, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText52 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Минимум одно из следующих полей\nобязательно для заполнения"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer53->Add( m_staticText52, 0, wxALL, 5 );

	m_staticText35 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Телефон"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer53->Add( m_staticText35, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	readerPhone = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( readerPhone, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText36 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Почта (Email)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer53->Add( m_staticText36, 0, wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );

	readerEmail = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( readerEmail, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	m_scrolledWindow2->SetSizer( bSizer53 );
	m_scrolledWindow2->Layout();
	bSizer53->Fit( m_scrolledWindow2 );
	bSizer42->Add( m_scrolledWindow2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer42 );
	this->Layout();
	bSizer42->Fit( this );
}

ReaderCreationFields::~ReaderCreationFields()
{
}

ReaderViewPanel::ReaderViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	bSizer47->SetMinSize( wxSize( 250,-1 ) );
	m_staticText19 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Id читателя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer47->Add( m_staticText19, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerId = new wxSpinCtrl( m_scrolledWindow1, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 9999999999, 1 );
	readerId->Enable( false );

	bSizer47->Add( readerId, 0, wxALL|wxEXPAND, 5 );

	m_staticText20 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Имя читателя"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer47->Add( m_staticText20, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerName = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( readerName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText31 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Адрес"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer47->Add( m_staticText31, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerAddress = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( readerAddress, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText32 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Дата рождения"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText32->Wrap( -1 );
	bSizer47->Add( m_staticText32, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerBirthday = new wxDatePickerCtrl( m_scrolledWindow1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_ALLOWNONE|wxDP_DEFAULT|wxDP_DROPDOWN );
	bSizer47->Add( readerBirthday, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText34 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Пол"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer47->Add( m_staticText34, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerMale = new wxRadioButton( m_scrolledWindow1, wxID_ANY, wxT("муж."), wxDefaultPosition, wxDefaultSize, wxRB_GROUP );
	bSizer47->Add( readerMale, 0, wxEXPAND|wxLEFT|wxRIGHT, 5 );

	readerFemale = new wxRadioButton( m_scrolledWindow1, wxID_ANY, wxT("жен."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( readerFemale, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText52 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Минимум одно из следующих полей\nобязательно для заполнения"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText52->Wrap( -1 );
	m_staticText52->SetFont( wxFont( wxNORMAL_FONT->GetPointSize(), wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxEmptyString ) );

	bSizer47->Add( m_staticText52, 0, wxALL, 5 );

	m_staticText35 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Телефон"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText35->Wrap( -1 );
	bSizer47->Add( m_staticText35, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerPhone = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( readerPhone, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText36 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Почта (Email)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText36->Wrap( -1 );
	bSizer47->Add( m_staticText36, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	readerEmail = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( readerEmail, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	bSizer46->Add( bSizer47, 1, wxEXPAND, 5 );

	saveReader = new wxButton( m_scrolledWindow1, wxID_ANY, wxT("Сохранить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( saveReader, 0, wxALL|wxEXPAND, 5 );


	m_scrolledWindow1->SetSizer( bSizer46 );
	m_scrolledWindow1->Layout();
	bSizer46->Fit( m_scrolledWindow1 );
	bSizer44->Add( m_scrolledWindow1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer44 );
	this->Layout();
	bSizer44->Fit( this );

	// Connect Events
	saveReader->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReaderViewPanel::OnSaveButtonClicked ), NULL, this );
}

ReaderViewPanel::~ReaderViewPanel()
{
	// Disconnect Events
	saveReader->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ReaderViewPanel::OnSaveButtonClicked ), NULL, this );

}

BooksListFilter::BooksListFilter( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );

	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Название"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer26->Add( m_staticText15, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	bookName = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer26->Add( bookName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText113 = new wxStaticText( this, wxID_ANY, wxT("Автор"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113->Wrap( -1 );
	bSizer26->Add( m_staticText113, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxArrayString authorChoiceChoices;
	authorChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, authorChoiceChoices, 0 );
	authorChoice->SetSelection( 0 );
	bSizer26->Add( authorChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText114 = new wxStaticText( this, wxID_ANY, wxT("Издатель"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	bSizer26->Add( m_staticText114, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxArrayString publisherChoiceChoices;
	publisherChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, publisherChoiceChoices, 0 );
	publisherChoice->SetSelection( 0 );
	bSizer26->Add( publisherChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText115 = new wxStaticText( this, wxID_ANY, wxT("Дата публикации"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	bSizer26->Add( m_staticText115, 0, wxALL, 5 );

	bookPublishedAt = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_ALLOWNONE|wxDP_DEFAULT|wxDP_DROPDOWN );
	bSizer26->Add( bookPublishedAt, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText144 = new wxStaticText( this, wxID_ANY, wxT("Электронная версия"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText144->Wrap( -1 );
	bSizer26->Add( m_staticText144, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxString bookFileChoices[] = { wxEmptyString, wxT("Есть"), wxT("Нет") };
	int bookFileNChoices = sizeof( bookFileChoices ) / sizeof( wxString );
	bookFile = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, bookFileNChoices, bookFileChoices, 0 );
	bookFile->SetSelection( 0 );
	bSizer26->Add( bookFile, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_toggleBtn1 = new wxToggleButton( this, wxID_ANY, wxT("Обновить списки"), wxDefaultPosition, wxDefaultSize, 0 );
	m_toggleBtn1->SetValue( true );
	bSizer26->Add( m_toggleBtn1, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	this->SetSizer( bSizer26 );
	this->Layout();
	bSizer26->Fit( this );

	// Connect Events
	m_toggleBtn1->Connect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BooksListFilter::OnListsRefreshClicked ), NULL, this );
}

BooksListFilter::~BooksListFilter()
{
	// Disconnect Events
	m_toggleBtn1->Disconnect( wxEVT_COMMAND_TOGGLEBUTTON_CLICKED, wxCommandEventHandler( BooksListFilter::OnListsRefreshClicked ), NULL, this );

}

BookCreationFields::BookCreationFields( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow2->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );

	bSizer53->SetMinSize( wxSize( 250,-1 ) );
	m_staticText15 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Название"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer53->Add( m_staticText15, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	bookName = new wxTextCtrl( m_scrolledWindow2, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( bookName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText113 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Автор"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113->Wrap( -1 );
	bSizer53->Add( m_staticText113, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxArrayString authorChoiceChoices;
	authorChoice = new wxChoice( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, authorChoiceChoices, 0 );
	authorChoice->SetSelection( 0 );
	bSizer53->Add( authorChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText114 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Издатель"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	bSizer53->Add( m_staticText114, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxArrayString publisherChoiceChoices;
	publisherChoice = new wxChoice( m_scrolledWindow2, wxID_ANY, wxDefaultPosition, wxDefaultSize, publisherChoiceChoices, 0 );
	publisherChoice->SetSelection( 0 );
	bSizer53->Add( publisherChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText115 = new wxStaticText( m_scrolledWindow2, wxID_ANY, wxT("Дата публикации"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	bSizer53->Add( m_staticText115, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	bookPublishedAt = new wxDatePickerCtrl( m_scrolledWindow2, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN );
	bSizer53->Add( bookPublishedAt, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	m_scrolledWindow2->SetSizer( bSizer53 );
	m_scrolledWindow2->Layout();
	bSizer53->Fit( m_scrolledWindow2 );
	bSizer42->Add( m_scrolledWindow2, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer42 );
	this->Layout();
	bSizer42->Fit( this );
}

BookCreationFields::~BookCreationFields()
{
}

BookViewPanel::BookViewPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer44;
	bSizer44 = new wxBoxSizer( wxVERTICAL );

	m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
	m_scrolledWindow1->SetScrollRate( 5, 5 );
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxVERTICAL );

	bSizer47->SetMinSize( wxSize( 250,-1 ) );
	m_staticText145 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Id книги"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText145->Wrap( -1 );
	bSizer47->Add( m_staticText145, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	bookId = new wxSpinCtrl( m_scrolledWindow1, wxID_ANY, wxT("1"), wxDefaultPosition, wxDefaultSize, 0, 1, 9999999999, 1 );
	bookId->Enable( false );

	bSizer47->Add( bookId, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText15 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Название"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer47->Add( m_staticText15, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	bookName = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( bookName, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText113 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Автор"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText113->Wrap( -1 );
	bSizer47->Add( m_staticText113, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxArrayString authorChoiceChoices;
	authorChoice = new wxChoice( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, authorChoiceChoices, 0 );
	authorChoice->SetSelection( 0 );
	bSizer47->Add( authorChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText114 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Издатель"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText114->Wrap( -1 );
	bSizer47->Add( m_staticText114, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	wxArrayString publisherChoiceChoices;
	publisherChoice = new wxChoice( m_scrolledWindow1, wxID_ANY, wxDefaultPosition, wxDefaultSize, publisherChoiceChoices, 0 );
	publisherChoice->SetSelection( 0 );
	bSizer47->Add( publisherChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText115 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("Дата публикации"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText115->Wrap( -1 );
	bSizer47->Add( m_staticText115, 0, wxLEFT|wxRIGHT|wxTOP, 5 );

	bookPublishedAt = new wxDatePickerCtrl( m_scrolledWindow1, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN );
	bSizer47->Add( bookPublishedAt, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );


	bSizer46->Add( bSizer47, 0, wxEXPAND, 5 );

	saveBook = new wxButton( m_scrolledWindow1, wxID_ANY, wxT("Сохранить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( saveBook, 0, wxALL|wxEXPAND, 5 );

	wxStaticBoxSizer* sbSizer1;
	sbSizer1 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, wxT("Электронная версия") ), wxHORIZONTAL );

	downloadFile = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Скачать"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( downloadFile, 0, wxALL, 5 );

	uploadFile = new wxButton( sbSizer1->GetStaticBox(), wxID_ANY, wxT("Загрузить"), wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer1->Add( uploadFile, 0, wxALL, 5 );


	bSizer46->Add( sbSizer1, 0, wxBOTTOM|wxEXPAND|wxTOP, 5 );

	wxStaticBoxSizer* sbSizer3;
	sbSizer3 = new wxStaticBoxSizer( new wxStaticBox( m_scrolledWindow1, wxID_ANY, wxT("Экземпляры") ), wxVERTICAL );

	instancesList = new wxDataViewListCtrl( sbSizer3->GetStaticBox(), wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	sbSizer3->Add( instancesList, 0, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );

	addInstance = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Добавить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( addInstance, 0, wxBOTTOM|wxEXPAND|wxRIGHT|wxTOP, 5 );

	withdrawInstance = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Выдать"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( withdrawInstance, 0, wxALL, 5 );

	returnInstance = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Вернуть"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( returnInstance, 0, wxALL, 5 );

	removeInstance = new wxButton( sbSizer3->GetStaticBox(), wxID_ANY, wxT("Удалить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( removeInstance, 0, wxALL|wxBOTTOM|wxLEFT|wxTOP, 5 );


	sbSizer3->Add( bSizer68, 0, wxEXPAND, 5 );


	bSizer46->Add( sbSizer3, 1, wxBOTTOM|wxEXPAND|wxTOP, 5 );


	m_scrolledWindow1->SetSizer( bSizer46 );
	m_scrolledWindow1->Layout();
	bSizer46->Fit( m_scrolledWindow1 );
	bSizer44->Add( m_scrolledWindow1, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer44 );
	this->Layout();
	bSizer44->Fit( this );

	// Connect Events
	saveBook->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BookViewPanel::OnSaveButtonClicked ), NULL, this );
	downloadFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BookViewPanel::OnFileDownloadClicked ), NULL, this );
	uploadFile->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BookViewPanel::OnUploadClicked ), NULL, this );
}

BookViewPanel::~BookViewPanel()
{
	// Disconnect Events
	saveBook->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BookViewPanel::OnSaveButtonClicked ), NULL, this );
	downloadFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BookViewPanel::OnFileDownloadClicked ), NULL, this );
	uploadFile->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( BookViewPanel::OnUploadClicked ), NULL, this );

}

InstanceWithdrawPanel::InstanceWithdrawPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxVERTICAL );

	m_staticText146 = new wxStaticText( this, wxID_ANY, wxT("Читатель"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText146->Wrap( -1 );
	bSizer69->Add( m_staticText146, 0, wxBOTTOM|wxLEFT|wxRIGHT, 5 );

	wxArrayString readerChoiceChoices;
	readerChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, readerChoiceChoices, 0 );
	readerChoice->SetSelection( 0 );
	bSizer69->Add( readerChoice, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText147 = new wxStaticText( this, wxID_ANY, wxT("Номер экземпляра"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText147->Wrap( -1 );
	bSizer69->Add( m_staticText147, 0, wxLEFT|wxRIGHT, 5 );

	instanceId = new wxSpinCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 9999999, 1 );
	instanceId->Enable( false );

	bSizer69->Add( instanceId, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_staticText148 = new wxStaticText( this, wxID_ANY, wxT("Дата возврата"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText148->Wrap( -1 );
	bSizer69->Add( m_staticText148, 0, wxLEFT|wxRIGHT, 5 );

	returnAt = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT );
	bSizer69->Add( returnAt, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT, 5 );

	m_button27 = new wxButton( this, wxID_ANY, wxT("Выдать экземпляр"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer69->Add( m_button27, 0, wxBOTTOM|wxEXPAND|wxLEFT|wxRIGHT|wxTOP, 5 );


	this->SetSizer( bSizer69 );
	this->Layout();

	// Connect Events
	m_button27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InstanceWithdrawPanel::OnWithdrawClicked ), NULL, this );
}

InstanceWithdrawPanel::~InstanceWithdrawPanel()
{
	// Disconnect Events
	m_button27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( InstanceWithdrawPanel::OnWithdrawClicked ), NULL, this );

}

DebtorsListPanel::DebtorsListPanel( wxWindow* parent, wxWindowID id, const wxPoint& pos, const wxSize& size, long style, const wxString& name ) : wxPanel( parent, id, pos, size, style, name )
{
	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxHORIZONTAL );

	m_button28 = new wxButton( this, wxID_ANY, wxT("Обновить"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer71->Add( m_button28, 0, wxALL, 5 );

	m_button29 = new wxButton( this, wxID_ANY, wxT("Закрыть долг"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer71->Add( m_button29, 0, wxALL, 5 );

	m_staticText150 = new wxStaticText( this, wxID_ANY, wxT("Список должников"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText150->Wrap( -1 );
	m_staticText150->SetFont( wxFont( 12, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxEmptyString ) );

	bSizer71->Add( m_staticText150, 0, wxALL, 5 );


	bSizer70->Add( bSizer71, 0, wxEXPAND, 5 );

	list = new wxDataViewListCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( list, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer70 );
	this->Layout();

	// Connect Events
	m_button28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DebtorsListPanel::RefreshButtonClicked ), NULL, this );
	m_button29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DebtorsListPanel::ReturnButtonClicked ), NULL, this );
}

DebtorsListPanel::~DebtorsListPanel()
{
	// Disconnect Events
	m_button28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DebtorsListPanel::RefreshButtonClicked ), NULL, this );
	m_button29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( DebtorsListPanel::ReturnButtonClicked ), NULL, this );

}
