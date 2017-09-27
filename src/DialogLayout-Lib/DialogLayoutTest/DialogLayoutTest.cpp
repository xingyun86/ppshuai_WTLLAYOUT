// DialogLayoutTest.cpp : main source file for DialogLayoutTest.exe
//

#include "stdafx.h"

#include "resource.h"

#include "TestDialog1.h"
#include "TestDialog2.h"
#include "TestDialog3.h"

CAppModule _Module;

int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpstrCmdLine, int nCmdShow)
{
	HRESULT hRes = ::CoInitialize(NULL);
// If you are running on NT 4.0 or higher you can use the following call instead to 
// make the EXE free threaded. This means that calls come in on a random RPC thread.
//	HRESULT hRes = ::CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));

	// this resolves ATL window thunking problem when Microsoft Layer for Unicode (MSLU) is used
	::DefWindowProc(NULL, 0, 0, 0L);

	AtlInitCommonControls(ICC_BAR_CLASSES);	// add flags to support other controls

	hRes = _Module.Init(NULL, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	INT_PTR nRet = 0;
	// BLOCK: Run application
	{
		CTestDialog1 dlg1;
		nRet = dlg1.DoModal();
		
		CTestDialog2 dlg2;
		nRet = dlg2.DoModal();

		CTestDialog3 dlg3;
		nRet = dlg3.DoModal();
	}

	_Module.Term();
	::CoUninitialize();

	return nRet;
}
