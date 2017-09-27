// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

class CMainFrame : 
	public CFrameWindowImpl<CMainFrame>, 
	public CResizableMinMax<CMainFrame>, 
	public CResizableState<CMainFrame>, 
	public CUpdateUI<CMainFrame>,
	public CMessageFilter, 
	public CIdleHandler
{
public:
	DECLARE_FRAME_WND_CLASS(NULL, IDR_MAINFRAME)

	CDialogViewTestView m_view;
	CSplitterWindow m_wndSplitter;
	CTreeViewCtrlEx m_wndTreeView;
	CPaneContainer m_wndDialogPane;

	CCommandBarCtrl m_CmdBar;

	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnIdle();

	BEGIN_UPDATE_UI_MAP(CMainFrame)
		UPDATE_ELEMENT(ID_VIEW_TOOLBAR, UPDUI_MENUPOPUP)
		UPDATE_ELEMENT(ID_VIEW_STATUS_BAR, UPDUI_MENUPOPUP)
	END_UPDATE_UI_MAP()

	BEGIN_MSG_MAP(CMainFrame)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		MSG_WM_DESTROY(OnDestroy)
		COMMAND_ID_HANDLER(ID_APP_EXIT, OnFileExit)
		COMMAND_ID_HANDLER(ID_FILE_NEW, OnFileNew)
		COMMAND_ID_HANDLER(ID_VIEW_TOOLBAR, OnViewToolBar)
		COMMAND_ID_HANDLER(ID_VIEW_STATUS_BAR, OnViewStatusBar)
		COMMAND_ID_HANDLER(ID_APP_ABOUT, OnAppAbout)
		COMMAND_ID_HANDLER(ID_TEST_RESIZABLESHEET, OnTestResizableSheet)
		COMMAND_ID_HANDLER(ID_TEST_RESIZABLEDIALOG, OnTestResizableDialog)
		COMMAND_ID_HANDLER(ID_TEST_RESIZABLEWIZARD, OnTestResizableWizard)
		CHAIN_MSG_MAP(CUpdateUI<CMainFrame>)
		CHAIN_MSG_MAP(CFrameWindowImpl<CMainFrame>)
		MSG_WM_GETMINMAXINFO(OnGetMinMaxInfo)
		CHAIN_CLIENT_COMMANDS()
	END_MSG_MAP()
	void OnGetMinMaxInfo(LPMINMAXINFO lpMinMaxInfo)
	{
		MinMaxInfo(lpMinMaxInfo);
	}
// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)

	void OnDestroy();
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
	LRESULT OnFileExit(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnFileNew(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewToolBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnViewStatusBar(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);

	// We need this cause ShowWindow corrup wp.rcNormalPosition
	// Call ActivateFrame instead ShowWindow in you App::Run method
	void ActivateFrame(int nCmdShow)
	{
		// Main Window State
		if (nCmdShow == -1)
		{
			if (!IsWindowVisible())
				nCmdShow = SW_SHOWNOACTIVATE;
			else if (IsIconic())
				nCmdShow = SW_RESTORE;
		}
		if (nCmdShow != -1)
		{
			// show the window as specified
			if (!	LoadWindowRect(HKEY_CURRENT_USER, REGKEY_APPLICATION, PLACEMENT_ENT, REGKEY_WP_MAINFRAME, FALSE))
			{
				WINDOWPLACEMENT wp = {0};
				wp.length = sizeof(WINDOWPLACEMENT);
				wp.flags = 0;
				nCmdShow = wp.showCmd = SW_SHOWMAXIMIZED;
				::SetRect(&wp.rcNormalPosition, 100, 100, 600, 400);
				SetWindowPlacement(&wp);
				//ShowWindow(nCmdShow);
			}
		}
	}
	LRESULT OnTestResizableSheet(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnTestResizableDialog(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
	LRESULT OnTestResizableWizard(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/);
};
