#pragma once

#include "resource.h"

class CTestDialog : 
	public CResizableDialogImpl<CTestDialog>
{
	typedef CResizableDialogImpl<CTestDialog> baseClass;
	typedef CTestDialog thisClass;
public:
	enum { IDD = IDD_TEST_DIALOG };
	CTestDialog(void);
	~CTestDialog(void);


	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
		MSG_WM_INITDIALOG(OnInitDialog)
		COMMAND_ID_HANDLER_EX(IDOK, OnOK)
		COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
		COMMAND_ID_HANDLER_EX(IDC_SHOW_GRIP, OnShowGrip)
	END_MSG_MAP()

	DWORD m_dwGripTempState;

	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);
	void OnOK(UINT wNotifyCode, int wID, HWND hWndCtl)
	{
		EndDialog(wID);
	}
	void OnCancel(UINT wNotifyCode, int wID, HWND hWndCtl)
	{
		EndDialog(wID);
	}
	void OnShowGrip(UINT wNotifyCode, int wID, HWND hWndCtl);
};
