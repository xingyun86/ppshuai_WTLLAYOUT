// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

// Change these values to use different versions
// Set max target Windows platform
#define WINVER 0x0500
#define _WIN32_WINNT 0x0501

// Use target Common Controls version for compatibility
// with CPropertyPageEx, CPropertySheetEx
#define _WIN32_IE 0x0500


#define _WTL_NO_UNION_CLASSES
#define _WTL_NO_CSTRING
#define _WTL_NO_WTYPES
#define _WTL_NEW_PAGE_NOTIFY_HANDLERS

#include <atlbase.h>
#include <atltypes.h>
#include <atlwin.h>
#include <atlcoll.h>

#include <atlapp.h>

extern CAppModule _Module;

#include <atlwin.h>

#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>
#include <atlctrlw.h>
#include <atlsplit.h>
#include <atlctrlx.h>
#include <atlstr.h>


#include "ResizableLib.h"



#define REGKEY_APPLICATION		_T("SOFTWARE\\AlexTheBoss\\ResizableLib_Test")
#define REGKEY_WP_MAINFRAME		_T("MainFrame")
#define REGKEY_WP_PROPSHEET		_T("PropSheet")
#define REGKEY_WP_WIZARD			_T("Wizard")
#define REGKEY_WP_TESTDIALOG	_T("TestDialog")
