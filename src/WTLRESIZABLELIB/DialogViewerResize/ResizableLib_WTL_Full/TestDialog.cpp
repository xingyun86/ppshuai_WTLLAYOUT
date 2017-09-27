#include "StdAfx.h"
#include "testdialog.h"

CTestDialog::CTestDialog(void)
{
	m_dwGripTempState = 1;
}

CTestDialog::~CTestDialog(void)
{
}

BOOL CTestDialog::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	AddAnchor(IDOK, TOP_RIGHT, TOP_RIGHT);
	AddAnchor(IDCANCEL, TOP_RIGHT, TOP_RIGHT);
	AddAnchor(IDC_SHOW_GRIP, BOTTOM_RIGHT, BOTTOM_RIGHT);
	AddAnchor(IDC_EDIT1, TOP_LEFT, MIDDLE_RIGHT);
	AddAnchor(IDC_EDIT2, MIDDLE_LEFT, BOTTOM_RIGHT);
	SetDlgItemText(IDC_EDIT1, "This top Edit control and bottom Edit control change size proportionaly");
	SetDlgItemText(IDC_EDIT2, "This bottom Edit control and top Edit control change size proportionaly");
	CheckDlgButton(IDC_SHOW_GRIP, BST_CHECKED);
	EnableSaveRestore(HKEY_CURRENT_USER, REGKEY_APPLICATION, PLACEMENT_ENT, REGKEY_WP_TESTDIALOG);
	return TRUE;
}


void CTestDialog::OnShowGrip(UINT wNotifyCode, int wID, HWND hWndCtl)
{
	if (wNotifyCode == BN_CLICKED)
	{
		if (IsDlgButtonChecked(IDC_SHOW_GRIP) == BST_CHECKED)
			ShowSizeGrip(&m_dwGripTempState);
		else
			HideSizeGrip(&m_dwGripTempState);
		UpdateSizeGrip();
	}
}
