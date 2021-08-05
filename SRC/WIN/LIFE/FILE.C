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
 * FILE.C
 *
 * Code to get a file using common dialog
 *
 */
#include <stdlib.h>
#include <stdio.h>
#include <direct.h>
#include <malloc.h>
#include <sys/stat.h>
#include "life.h"
#include "filedll.h"

BOOL GetFileName( char *name, int type, char *ext,
		  char *buff, int len )
/**************************************

    Get the name of a pattern for either loading or saving
*/
{
    FILEOPEN		of;
    HANDLE		dll;
#if defined(__WINDOWS_386__)
    HINDIR		h;
#else
    BOOL  		(PASCAL FAR *gsn)( LPFILEOPEN );
#endif
    FARPROC		farp;
    DWORD		a1,a2,a3;
    BOOL		rc;

    dll = LoadLibrary( "filedll.dll" );
    if( dll < 32 ) {
	MessageBox( NULL, "Could not find filedll.dll!", "Life", MB_OK );
	return( FALSE );
    }
    farp = (FARPROC) GetProcAddress( dll, "GetFileName" );
#if defined(__WINDOWS_386__)
    h = GetIndirectFunctionHandle( farp, INDIR_PTR, INDIR_ENDLIST );
#else
    gsn = (void FAR *) farp;
#endif

    of.hwnd = WinHandle;
    buff[0] = 0;
    a1 = AllocAlias16( buff );
    of.name = (LPSTR) a1;
    of.namelen = len;
    a2 = AllocAlias16( name );
    of.title = (LPSTR) a2;
    of.type = type;
    a3 = AllocAlias16( ext );
    of.ext = (LPSTR) a3;
#if defined(__WINDOWS_386__)
    rc = InvokeIndirectFunction( h, &of );
#else
    rc = gsn( &of );
#endif
    if( rc ) rc = TRUE;
    else rc = FALSE;
    FlushMouse();
    FreeAlias16( a1 );
    FreeAlias16( a2 );
    FreeAlias16( a3 );
    FreeLibrary( dll );
    return( rc );
}

int CheckHeap()
{
	return( _heapchk() );

}
