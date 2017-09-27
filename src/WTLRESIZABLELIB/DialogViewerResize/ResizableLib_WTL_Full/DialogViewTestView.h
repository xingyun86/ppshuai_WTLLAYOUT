// DialogViewTestView.h : interface of the CDialogViewTestView class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once
#include "resource.h"

class CDialogViewTestView : 
	public CResizableDialogImpl<CDialogViewTestView>
{
	typedef CDialogViewTestView thisClass;
	typedef CResizableDialogImpl<CDialogViewTestView> baseClass;
public:
	enum { IDD = IDD_DIALOGVIEWTEST_FORM };

	BOOL PreTranslateMessage(MSG* pMsg);

	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
		MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
		if (uMsg == WM_COMMAND && 
				 (ID_TEST_RESIZABLESHEET==LOWORD(wParam) || 
					ID_TEST_RESIZABLEDIALOG==LOWORD(wParam) || 
					ID_TEST_RESIZABLEWIZARD==LOWORD(wParam)) ) 
		{
			// Send it to Parent
			bHandled = TRUE;
			return GetParent().GetParent().SendMessage(WM_COMMAND, wParam, lParam);
		}
	END_MSG_MAP()

// Handler prototypes (uncomment arguments if needed):
//	LRESULT MessageHandler(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
//	LRESULT CommandHandler(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
//	LRESULT NotifyHandler(int /*idCtrl*/, LPNMHDR /*pnmh*/, BOOL& /*bHandled*/)
	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);
};
