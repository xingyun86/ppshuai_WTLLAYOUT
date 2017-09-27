#include "StdAfx.h"
#include "propertypages.h"

CPropPage1::CPropPage1(void)
{
}

CPropPage1::~CPropPage1(void)
{
}

BOOL CPropPage1::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	AddAnchor(IDC_COMBO1, TOP_LEFT, TOP_RIGHT);
	AddAnchor(IDC_EDIT1, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_BUTTON1, TOP_RIGHT, BOTTOM_RIGHT);
	return TRUE;
}


CPropPage2::CPropPage2(void)
{
}

CPropPage2::~CPropPage2(void)
{
}

BOOL CPropPage2::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	AddAnchor(IDC_LIST1, TOP_LEFT, CSize(50,70));
	AddAnchor(IDC_PICTURE1, CSize(50,0), CSize(100,70));
	AddAnchor(IDC_GROUP1, CSize(0,70), BOTTOM_RIGHT);
	AddAnchor(IDC_CHECK1, CSize(0,85));
	AddAnchor(IDC_RADIO1, CSize(100,85));
	AddAnchor(IDC_COMBO2, CSize(100,70));
	AddAnchor(IDC_BUTTON1, BOTTOM_RIGHT);
	return TRUE;
}


CPropPage3::CPropPage3(void)
{
}

CPropPage3::~CPropPage3(void)
{
}

BOOL CPropPage3::OnInitDialog(HWND hWnd, LPARAM lParam)
{
	AddAnchor(IDC_LABEL1, TOP_LEFT);
	AddAnchor(IDC_EDIT1, TOP_LEFT, BOTTOM_RIGHT);
	AddAnchor(IDC_SLIDER1, BOTTOM_LEFT, BOTTOM_RIGHT);
	return TRUE;
}



void CPropSheet::OnInitDialog()
{
	EnableSaveRestore(
		HKEY_CURRENT_USER, 
		REGKEY_APPLICATION, 
		PLACEMENT_ENT, 
		IsWizard() ? REGKEY_WP_WIZARD : REGKEY_WP_PROPSHEET, FALSE, TRUE);
}
