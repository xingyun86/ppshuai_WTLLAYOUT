// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#pragma once

// Change these values to use different versions
#define WINVER 0x0500
#define _WIN32_WINNT 0x0501
//#define _WIN32_WINNT	0x0400
#define _WIN32_IE 0x0500
#define _RICHEDIT_VER	0x0300

#define _WTL_NO_UNION_CLASSES
#define _WTL_NO_CSTRING
#define _WTL_NO_WTYPES

#include <windows.h>
#include <atlbase.h>
#include <atltypes.h>
#include <atlwin.h>
#include <atlcom.h>
#include <atlcoll.h>

#include <atlapp.h>

extern CAppModule _Module;


#include <atlframe.h>
#include <atlctrls.h>
#include <atldlgs.h>

#include <atlstr.h>

//#define RSZLIB_NO_XP_DOUBLE_BUFFER
#include <ResizableLib.h>