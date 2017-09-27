// DialogViewTestView.cpp : implementation of the CDialogViewTestView class
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "resource.h"
#include "DialogViewTestView.h"

BOOL CDialogViewTestView::PreTranslateMessage(MSG* pMsg)
{
	return CWindow::IsDialogMessage(pMsg);
}

LRESULT CDialogViewTestView::OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
{
	CListBox list=GetDlgItem(IDC_LIST);
	list.AddString("String 1");
	list.AddString("String 2");
	list.AddString("String 3");
	list.AddString("String 4");
	list.AddString("String 5");
	list.AddString("String 6");
	list.AddString("String 7");
	AddAnchor(list, TOP_LEFT, MIDDLE_RIGHT);
	AddAnchor(IDC_GB1, MIDDLE_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_EDIT1, MIDDLE_LEFT, BOTTOM_CENTER);
	AddAnchor(IDC_EDIT2, MIDDLE_CENTER, BOTTOM_RIGHT);
	AddAnchor(ID_TEST_RESIZABLESHEET, BOTTOM_LEFT, BOTTOM_CENTER);
	AddAnchor(ID_TEST_RESIZABLEWIZARD, BOTTOM_CENTER, BOTTOM_RIGHT);
	AddAnchor(ID_TEST_RESIZABLEDIALOG, BOTTOM_LEFT, BOTTOM_RIGHT);
	return TRUE;
}

