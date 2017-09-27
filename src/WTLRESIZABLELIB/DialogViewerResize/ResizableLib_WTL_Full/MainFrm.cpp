// MainFrm.cpp : implmentation of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "DialogViewTestView.h"
#include "MainFrm.h"
#include "PropertyPages.h"
#include "testdialog.h"

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if(CFrameWindowImpl<CMainFrame>::PreTranslateMessage(pMsg))
		return TRUE;

	return m_view.PreTranslateMessage(pMsg);
}

BOOL CMainFrame::OnIdle()
{
	UIUpdateToolBar();
	return FALSE;
}

void CMainFrame::OnDestroy()
{
	// Saving Window size and position
	SaveWindowRect(HKEY_CURRENT_USER, REGKEY_APPLICATION, PLACEMENT_ENT, REGKEY_WP_MAINFRAME);
	SetMsgHandled(FALSE);
}
LRESULT CMainFrame::OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	SetMinTrackSize(CPoint(320, 280));
	// create command bar window
	HWND hWndCmdBar = m_CmdBar.Create(m_hWnd, rcDefault, NULL, ATL_SIMPLE_CMDBAR_PANE_STYLE);
	// attach menu
	m_CmdBar.AttachMenu(GetMenu());
	// load command bar images
	m_CmdBar.LoadImages(IDR_MAINFRAME);
	// remove old menu
	SetMenu(NULL);

	HWND hWndToolBar = CreateSimpleToolBarCtrl(m_hWnd, IDR_MAINFRAME, FALSE, ATL_SIMPLE_TOOLBAR_PANE_STYLE);

	CreateSimpleReBar(ATL_SIMPLE_REBAR_NOBORDER_STYLE);
	AddSimpleReBarBand(hWndCmdBar);
	AddSimpleReBarBand(hWndToolBar, NULL, TRUE);

	CreateSimpleStatusBar();

	m_hWndClient = m_wndSplitter.Create(m_hWnd, rcDefault, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
	m_wndDialogPane.Create(m_wndSplitter, _T("DialogViewPane"), WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN);
	m_wndDialogPane.SetPaneContainerExtendedStyle(PANECNT_NOCLOSEBUTTON, PANECNT_NOCLOSEBUTTON);

	m_wndTreeView.Create(m_wndSplitter, rcDefault, NULL, 
		WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | 
		TVS_HASLINES | TVS_LINESATROOT | TVS_HASBUTTONS | TVS_SHOWSELALWAYS, 
		WS_EX_CLIENTEDGE);
	
	HTREEITEM hItemRoot = m_wndTreeView.InsertItem("Root Item", TVI_ROOT, TVI_FIRST);
	for (int i = 0; i < 5; i++)
	{
		CString s;
		s.Format("Item %d", i+1);
		HTREEITEM hParent = m_wndTreeView.InsertItem(s, hItemRoot, TVI_LAST);
		for (int j = 0; j < 10; j++)
		{
			s.Format("SubItem %d (of %d)", j+1, i+1);
			m_wndTreeView.InsertItem(s, hParent, TVI_LAST);
		}
	}
	m_view.Create(m_wndDialogPane);
	m_wndDialogPane.SetClient(m_view);

	m_wndSplitter.SetSplitterPanes(m_wndTreeView, m_wndDialogPane);

	UpdateLayout();

	RECT rect;
	GetClientRect(&rect);
	m_wndSplitter.SetSplitterPos((rect.right - rect.left) / 4);


	UIAddToolBar(hWndToolBar);
	UISetCheck(ID_VIEW_TOOLBAR, 1);
	UISetCheck(ID_VIEW_STATUS_BAR, 1);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	return 0;
}

LRESULT CMainFrame::OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	PostMessage(WM_CLOSE);
	return 0;
}

LRESULT CMainFrame::OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: add code to initialize document

	return 0;
}

LRESULT CMainFrame::OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	static BOOL bVisible = TRUE;	// initially visible
	bVisible = !bVisible;
	CReBarCtrl rebar = m_hWndToolBar;
	int nBandIndex = rebar.IdToIndex(ATL_IDW_BAND_FIRST + 1);	// toolbar is 2nd added band
	rebar.ShowBand(nBandIndex, bVisible);
	UISetCheck(ID_VIEW_TOOLBAR, bVisible);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	BOOL bVisible = !::IsWindowVisible(m_hWndStatusBar);
	::ShowWindow(m_hWndStatusBar, bVisible ? SW_SHOWNOACTIVATE : SW_HIDE);
	UISetCheck(ID_VIEW_STATUS_BAR, bVisible);
	UpdateLayout();
	return 0;
}

LRESULT CMainFrame::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CAboutDlg dlg;
	dlg.DoModal();
	return 0;
}

LRESULT CMainFrame::OnTestResizableSheet(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add your command handler code here
	CPropSheet sheet;
	CPropPage1 page1;
	CPropPage2 page2;
	CPropPage3 page3;
	sheet.AddPage(page1);
	sheet.AddPage(page2);
	sheet.AddPage(page3);
	sheet.DoModal();
	return 0;
}

LRESULT CMainFrame::OnTestResizableDialog(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add your command handler code here
	CTestDialog dlg;
	dlg.DoModal();
	return 0;
}

LRESULT CMainFrame::OnTestResizableWizard(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add your command handler code here
	CPropSheet sheet;
	CPropPage1 page1;
	CPropPage2 page2;
	CPropPage3 page3;
	sheet.AddPage(page1);
	sheet.AddPage(page2);
	sheet.AddPage(page3);
	sheet.SetWizardMode();
	sheet.DoModal();
	return 0;
}
