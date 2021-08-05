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

 INT.C

    This file defines the process routines for Int fields.

*/

#include <windows.h>
#include "ctltype.h"

    
BOOL ctl_int_start( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/******************************************************************/
/* start an integer field */

{
    inst = inst;
    
    SetDlgItemInt( dlg, elt->control, _value_int( ptr, elt ), TRUE );
    
    return( TRUE );
}

BOOL ctl_int_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/*******************************************************************/
/* end an int field */

{
    BOOL		ok;
    
    inst = inst;
    
    _value_int( ptr, elt ) = GetDlgItemInt( dlg, elt->control, &ok, TRUE );
    
    if( !ok ) {
	SetFocus( GetDlgItem( dlg, elt->control ) );
	MessageBox( dlg, "Invalid integer: please re-enter it", NULL,
					MB_APPLMODAL | MB_ICONHAND | MB_OK );
	return( FALSE );
    }
    
    return( TRUE );
}
