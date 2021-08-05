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

 DCOMBO.C

    This file defines the process routines for Dynamic Combo field.

*/

#include <windows.h>
#include <string.h>
#include "ctltype.h"

extern WORD ctl_combo_add_msg( HWND, int );
extern WORD ctl_combo_sel_msg( HWND, int );
extern WORD ctl_combo_get_msg( HWND, int );

BOOL ctl_dcombo_start( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/*********************************************************************/
/* start a dynamic combo list box */

{
    char		*str;
    int			i;
    int			value;
    
    inst = inst;
    
    value = _value_int( ptr, elt ) - elt->info.dcombo.origin;
    
    for( i = 0;; ++i ) {
	str = (elt->info.dcombo.fetch)( i );
	if( str == NULL ) {
	    break;
	}
	
	SendDlgItemMessage( dlg, elt->control, 
			ctl_combo_add_msg( dlg, elt->control ) , NULL, 
						    (DWORD)(LPSTR) str );
    }
    
    if( value >= i ) {
	value = i - 1;
    }
    
    SendDlgItemMessage( dlg, elt->control, ctl_combo_sel_msg( dlg,
					    elt->control ), value, NULL );
    
    return( TRUE );
}
	
BOOL ctl_dcombo_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/**********************************************************************/
/* finish a dynamic combo list box */

{
    inst = inst;
    
    _value_int( ptr, elt ) = elt->info.dcombo.origin +
	    SendDlgItemMessage( dlg, elt->control, 
			ctl_combo_get_msg( dlg, elt->control ), NULL, NULL );
    
    return( TRUE );
}
