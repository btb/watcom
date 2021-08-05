/*
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *%									   %
 *%	Copyright (C) 1991, by WATCOM Systems Inc. All rights reserved.    %
 *%									   %
 *%     Permission is granted to anyone to use this example program for	   %
 *%     any purpose on any computer system, subject to the following	   %
 *%	restrictions:							   %
 *%									   %
 *%     1. This example is provided on an "as is" basis, without warranty. %
 *%	   You indemnify, hold harmless and defend WATCOM from and against %
 *%	   any claims or lawsuits, including attorney's, that arise or	   %
 *%	   result from the use or distribution of this example, or any     %
 *%	   modification thereof.					   %
 *%									   %
 *%     2. You may not remove, alter or suppress this notice from this	   %
 *%        example program or any modification thereof.			   %
 *%									   %
 *%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 *
 * TESTCHT2.C
 *
 * creates callback routine for chart.dll
 *
 */
#define NOAUTOPROCS
#include <windows.h>
#include "testcht.h"
#include "chart.h"

BOOL _EXPORT FAR PASCAL FetchData( int, LPFLOAT );

void CreateMe( HWND hwnd )
{
CALLBACKPTR		cbp;

#ifdef __WINDOWS_386__
    DefineUserProc16( GETPROC_USERDEFINED_1, (PROCPTR) FetchData,
	    UDP16_WORD, UDP16_DWORD, UDP16_ENDLIST );
#endif
    cbp = GetProc16( (PROCPTR) FetchData, GETPROC_USERDEFINED_1 );
    SetWindowWord( hwnd, 0,
		    ChartAdd( MakeProcInstance( cbp,
		    GetWindowWord( hwnd, GWW_HINSTANCE ) ) ) );
}
