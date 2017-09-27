#pragma once

#include "resource.h"

class CPropPage1 :
	public CResizablePropertyPageImpl<CPropPage1>
{
	typedef CPropPage1 thisClass;
	typedef CResizablePropertyPageImpl<CPropPage1> baseClass;
public:
	enum { IDD = IDD_PROPPAGE_1 };
	CPropPage1(void);
	~CPropPage1(void);

	int OnSetActive()
	{
		GetParent().PostMessage(PSM_SETWIZBUTTONS, 0, PSWIZB_NEXT);
		return 0;
	}

	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);
	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
		MSG_WM_INITDIALOG(OnInitDialog)
	END_MSG_MAP()
};


class CPropPage2 :
	public CResizablePropertyPageImpl<CPropPage2>
{
	typedef CPropPage2 thisClass;
	typedef CResizablePropertyPageImpl<CPropPage2> baseClass;
public:
	enum { IDD = IDD_PROPPAGE_2 };
	CPropPage2(void);
	~CPropPage2(void);

	int OnSetActive()
	{
		GetParent().PostMessage(PSM_SETWIZBUTTONS, 0, PSWIZB_NEXT|PSWIZB_BACK);
		return 0;
	}

	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);
	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
		MSG_WM_INITDIALOG(OnInitDialog)
	END_MSG_MAP()
};


class CPropPage3 :
	public CResizablePropertyPageImpl<CPropPage3>
{
	typedef CPropPage3 thisClass;
	typedef CResizablePropertyPageImpl<CPropPage3> baseClass;
public:
	enum { IDD = IDD_PROPPAGE_3 };
	CPropPage3(void);
	~CPropPage3(void);

	BOOL OnInitDialog(HWND hWnd, LPARAM lParam);
	
	int OnSetActive()
	{
		GetParent().PostMessage(PSM_SETWIZBUTTONS, 0, PSWIZB_FINISH|PSWIZB_BACK);
		return 0;
	}

	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
		MSG_WM_INITDIALOG(OnInitDialog)
	END_MSG_MAP()
};


class CPropSheet:
	public CResizablePropertySheetImpl<CPropSheet>
{
	typedef CPropSheet thisClass;
	typedef CResizablePropertySheetImpl<CPropSheet> baseClass;
public:
	BEGIN_MSG_MAP(thisClass)
		CHAIN_MSG_MAP(baseClass)
	END_MSG_MAP()
	void OnInitDialog();
};