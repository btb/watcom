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
 * GENERIC.C
 *
 * Generic windows program, demonstrates basic message handling
 *
 */
#include <windows.h>
#include <stdio.h>
#include <malloc.h>
#include "generic.h"

static char GenericClass[32]="GenericClass";

static BOOL FirstInstance( HANDLE );
static BOOL AnyInstance( HANDLE, int, LPSTR );
long _EXPORT FAR PASCAL WindowProc( HWND, unsigned, WORD, LONG );

/*
 * WinMain - initialization, message loop
 */
int PASCAL WinMain( HANDLE this_inst, HANDLE prev_inst, LPSTR cmdline,
		    int cmdshow )
{
    MSG		msg;

    prev_inst = prev_inst;
#ifdef __WINDOWS_386__
    sprintf( GenericClass,"GenericClass%d", this_inst );
#else
    if( !prev_inst )
#endif
	if( !FirstInstance( this_inst ) ) return( FALSE );

    if( !AnyInstance( this_inst, cmdshow, cmdline ) ) return( FALSE );

    while( GetMessage( &msg, NULL, NULL, NULL ) ) {

	TranslateMessage( &msg );
	DispatchMessage( &msg );

    }

    return( msg.wParam );

} /* WinMain */

/*
 * FirstInstance - register window class for the application,
 *		   and do any other application initialization
 */
static BOOL FirstInstance( HANDLE this_inst )
{
    WNDCLASS	wc;
    BOOL	rc;

    /*
     * set up and register window class
     */
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpfnWndProc = (LPVOID) WindowProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = sizeof( DWORD );
    wc.hInstance = this_inst;
    wc.hIcon = LoadIcon( this_inst, "GenericIcon" );
    wc.hCursor = LoadCursor( NULL, IDC_ARROW );
    wc.hbrBackground = GetStockObject( WHITE_BRUSH );
    wc.lpszMenuName = "GenericMenu";
    wc.lpszClassName = GenericClass;
    rc = RegisterClass( &wc );
    return( rc );

} /* FirstInstance */

/*
 * AnyInstance - do work required for every instance of the application:
 *		  create the window, initialize data
 */
static BOOL AnyInstance( HANDLE this_inst, int cmdshow, LPSTR cmdline )
{
    HWND 	hwnd;
    extra_data	*edata_ptr;
    
    /*
     * create main window
     */
    hwnd = CreateWindow(
	GenericClass,		/* class */
	"WATCOM Generic Kind Of Application",	/* caption */
	WS_OVERLAPPEDWINDOW,	/* style */
	CW_USEDEFAULT,		/* init. x pos */
	CW_USEDEFAULT,		/* init. y pos */
	CW_USEDEFAULT,		/* init. x size */
	CW_USEDEFAULT,		/* init. y size */
	NULL,			/* parent window */
	NULL,			/* menu handle */
	this_inst,		/* program handle */
	NULL			/* create parms */
	);
		    
    if( !hwnd ) return( FALSE );

    /*
     * set up data associated with this window
     */
    edata_ptr = malloc( sizeof( extra_data ) );
    if( edata_ptr == NULL ) return( FALSE );
    edata_ptr->cmdline = cmdline;
    SetWindowLong( hwnd, EXTRA_DATA_OFFSET, (DWORD) edata_ptr );

    /*
     * display window
     */
    ShowWindow( hwnd, cmdshow );
    UpdateWindow( hwnd );
    
    return( TRUE );
                        
} /* AnyInstance */

/*
 * AboutDlgProc - processes messages for the about dialog.
 */
BOOL _EXPORT FAR PASCAL AboutDlgProc( HWND hwnd, unsigned msg,
				WORD wparam, LONG lparam )
{
    lparam = lparam;			/* turn off warning */

    switch( msg ) {
    case WM_INITDIALOG:
	return( TRUE );

    case WM_COMMAND:
    	if( wparam == IDOK ) {
	    EndDialog( hwnd, TRUE );
	    return( TRUE );
	}
	break;
    }
    return( FALSE );

} /* AboutDlgProc */

/*
 * WindowProc - handle messages for the main application window
 */
LONG _EXPORT FAR PASCAL WindowProc( HWND hwnd, unsigned msg,
				     WORD wparam, LONG lparam )
{
    FARPROC 	proc;
    HANDLE	inst_handle;
    extra_data	*edata_ptr;
    char	buff[128];

    switch( msg ) {
    case WM_COMMAND:
    	switch( wparam ) {
	case MENU_ABOUT:
	    inst_handle = GetWindowWord( hwnd, GWW_HINSTANCE );
	    proc = MakeProcInstance( AboutDlgProc, inst_handle );
	    DialogBox( inst_handle,"AboutBox", hwnd, proc );
	    FreeProcInstance( proc );
	    break;

	case MENU_CMDSTR:
	    edata_ptr = (extra_data *) GetWindowLong( hwnd,
	    					EXTRA_DATA_OFFSET );
	    sprintf( buff, "Command string was %Fs", edata_ptr->cmdline );
	    MessageBox( NULL, buff, "Program Information", MB_OK );
	    break;
	}
	break;

    case WM_DESTROY:
	PostQuitMessage( 0 );
	break;

    default:
	return( DefWindowProc( hwnd, msg, wparam, lparam ) );
    }
    return( 0L );

} /* WindowProc */
