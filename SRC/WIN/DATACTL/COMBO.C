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

 COMBO.C

    This file defines the process routines for Combo fields.
*/

#include <windows.h>
#include <string.h>
#include "ctltype.h"

extern WORD ctl_combo_add_msg( HWND, int );
extern WORD ctl_combo_sel_msg( HWND, int );
extern WORD ctl_combo_get_msg( HWND, int );

BOOL ctl_combo_start( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/********************************************************************/
/* start a combo list box */

{
    char		value[50];
    WORD		id;
    int			choose;
    int			max;
    
    choose = _value_int( ptr, elt ) - elt->info.combo.origin;
    
    if( choose < 0 ) {
	choose = 0;
    } else {
	max = elt->info.combo.end_id - elt->info.combo.start_id;
	if( choose > max ) {
	    choose = max;
	}
    }
    
    for( id = elt->info.combo.start_id; id <= elt->info.combo.end_id; ++id ) {
	
	LoadString( inst, id, value, 50 );
	value[49] = '\0';
	SendDlgItemMessage( dlg, elt->control, 
			ctl_combo_add_msg( dlg, elt->control ) , NULL, 
						    (DWORD)(LPSTR) value );
    }
    SendDlgItemMessage( dlg, elt->control, ctl_combo_sel_msg( dlg,
					    elt->control ), choose, NULL );
    
    return( TRUE );
}
	
BOOL ctl_combo_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/*********************************************************************/
/* finish a combo list box */

{
    inst = inst;
    
    _value_int( ptr, elt ) = elt->info.combo.origin +
	    SendDlgItemMessage( dlg, elt->control, 
			ctl_combo_get_msg( dlg, elt->control ), NULL, NULL );
    
    return( TRUE );
}
