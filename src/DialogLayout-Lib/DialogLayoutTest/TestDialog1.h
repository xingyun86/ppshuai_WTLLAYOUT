#pragma once

#include <DialogLayout.h>


class CTestDialog1 :
	public CDialogImpl<CTestDialog1>,
	public CDialogLayout<CTestDialog1>
{
public:
	enum { IDD = IDD_TESTDIALOG1 };

	BEGIN_MSG_MAP(CTestDialog1)
		MSG_WM_INITDIALOG(OnInitDialog)
		COMMAND_ID_HANDLER_EX(IDOK, OnOK)
		COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
		CHAIN_MSG_MAP(CDialogLayout<CTestDialog1>)
	END_MSG_MAP()


	BEGIN_LAYOUT_MAP()
		LAYOUT_CONTROL(IDOK, LAYOUT_ANCHOR_RIGHT | LAYOUT_ANCHOR_BOTTOM)
		LAYOUT_CONTROL(IDCANCEL, LAYOUT_ANCHOR_RIGHT | LAYOUT_ANCHOR_BOTTOM)
	END_LAYOUT_MAP()


	BOOL OnInitDialog(HWND, LPARAM)
	{
		// ...

		m_bGripper = TRUE;

		SetMsgHandled(FALSE);
		return TRUE;
	}

	
	void OnOK(UINT, int, HWND)
	{
		EndDialog(IDOK);
	}


	void OnCancel(UINT, int, HWND)
	{
		EndDialog(IDCANCEL);
	}
};
