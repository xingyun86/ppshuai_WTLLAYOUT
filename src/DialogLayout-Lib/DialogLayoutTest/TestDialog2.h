#pragma once

#include <DialogLayout.h>


class CTestDialog2 :
	public CDialogImpl<CTestDialog2>,
	public CDialogLayout<CTestDialog2>
{
public:
	enum { IDD = IDD_TESTDIALOG2 };

	BEGIN_MSG_MAP(CTestDialog2)
		MSG_WM_INITDIALOG(OnInitDialog)
		COMMAND_ID_HANDLER_EX(IDOK, OnOK)
		COMMAND_ID_HANDLER_EX(IDCANCEL, OnCancel)
		CHAIN_MSG_MAP(CDialogLayout<CTestDialog2>)
	END_MSG_MAP()


	BEGIN_LAYOUT_MAP()
		LAYOUT_CONTROL(IDOK, LAYOUT_ANCHOR_RIGHT | LAYOUT_ANCHOR_BOTTOM)
		LAYOUT_CONTROL(IDCANCEL, LAYOUT_ANCHOR_RIGHT | LAYOUT_ANCHOR_BOTTOM)
		LAYOUT_CONTROL(IDC_LIST, LAYOUT_ANCHOR_ALL)
		LAYOUT_CONTROL(IDC_BUTTON_ADD, LAYOUT_ANCHOR_RIGHT | LAYOUT_ANCHOR_TOP)
		LAYOUT_CONTROL(IDC_BUTTON_REMOVE, LAYOUT_ANCHOR_RIGHT | LAYOUT_ANCHOR_TOP)
	END_LAYOUT_MAP()


	BOOL OnInitDialog(HWND, LPARAM)
	{
		// ...

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
