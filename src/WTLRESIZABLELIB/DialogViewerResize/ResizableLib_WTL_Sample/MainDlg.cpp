// MainDlg.cpp : implementation of the CMainDlg class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"

#include "aboutdlg.h"
#include "MainDlg.h"

BOOL CMainDlg::PreTranslateMessage(MSG* pMsg)
{
	return CWindow::IsDialogMessage(pMsg);
}

BOOL CMainDlg::OnIdle()
{
	return FALSE;
}

LRESULT CMainDlg::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	// center the dialog on the screen
	CenterWindow();

	// set icons
	HICON hIcon = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXICON), ::GetSystemMetrics(SM_CYICON), LR_DEFAULTCOLOR);
	SetIcon(hIcon, TRUE);
	HICON hIconSmall = (HICON)::LoadImage(_Module.GetResourceInstance(), MAKEINTRESOURCE(IDR_MAINFRAME), 
		IMAGE_ICON, ::GetSystemMetrics(SM_CXSMICON), ::GetSystemMetrics(SM_CYSMICON), LR_DEFAULTCOLOR);
	SetIcon(hIconSmall, FALSE);

	// register object for message filtering and idle updates
	CMessageLoop* pLoop = _Module.GetMessageLoop();
	ATLASSERT(pLoop != NULL);
	pLoop->AddMessageFilter(this);
	pLoop->AddIdleHandler(this);

	UIAddChildWindowContainer(m_hWnd);

	AddAnchor(IDC_S1, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_LIST1, TOP_LEFT, BOTTOM_RIGHT);

	AddAnchor(IDOK, BOTTOM_LEFT);
	AddAnchor(IDCANCEL, BOTTOM_CENTER);
	AddAnchor(ID_APP_ABOUT, BOTTOM_RIGHT);
	
	EnableSaveRestore(HKEY_CURRENT_USER, "Software\\AlexTheBoss\\Settings\\", PLACEMENT_ENT, "MainDlg");
	return TRUE;
}

class CPage1 : public CResizablePropertyPageImpl<CPage1>
{
	typedef CPage1 thisClass;
	typedef CResizablePropertyPageImpl<CPage1> baseClass;
public:
	enum { IDD = IDD_PAGE_1 };
	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
		MSG_WM_INITDIALOG(OnInitDialog)
	END_MSG_MAP()
	BOOL OnInitDialog(HWND hDlg, LPARAM lParam)
	{
		AddAnchor(IDC_S1, TOP_LEFT, BOTTOM_RIGHT);
		AddAnchor(IDC_RADIO1, MIDDLE_LEFT);
		AddAnchor(IDC_RADIO2, MIDDLE_CENTER);
		AddAnchor(IDC_RADIO3, MIDDLE_RIGHT);
		SetMsgHandled(FALSE);
		return TRUE;
	}
};

class CPropSheet :
	public CResizablePropertySheetImpl<CPropSheet>
{
public:
	void OnInitDialog()
	{
		EnableSaveRestore(HKEY_CURRENT_USER, "Software\\AlexTheBoss\\Settings\\", PLACEMENT_ENT, "PropSheet");
	}
};

LRESULT CMainDlg::OnAppAbout(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CPage1 page1;
	CResizablePropertyPage<IDD_PAGE_2> page2;
	CResizablePropertyPage<IDD_PAGE_3> page3;
	CPropSheet propSheet;
	//CPropertySheet propSheet;
	propSheet.m_psh.dwFlags |= PSH_NOCONTEXTHELP;
	propSheet.AddPage(page1);
	propSheet.AddPage(page2);
	propSheet.AddPage(page3);
	propSheet.DoModal();
	//CAboutDlg dlg;
	//dlg.DoModal();
	return 0;
}

LRESULT CMainDlg::OnOK(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	// TODO: Add validation code 
	CloseDialog(wID);
	return 0;
}

LRESULT CMainDlg::OnCancel(WORD /*wNotifyCode*/, WORD wID, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
{
	CloseDialog(wID);
	return 0;
}

void CMainDlg::CloseDialog(int nVal)
{
	DestroyWindow();
	::PostQuitMessage(nVal);
}
