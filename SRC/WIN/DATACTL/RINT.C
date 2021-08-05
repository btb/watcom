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

 RINIT.C

    This file defines the process routines for Range int fields.

*/

#include <windows.h>
#include <stdio.h>
#include "ctltype.h"

extern BOOL ctl_int_finish( ctl_elt *, HANDLE, HWND, void * );
    
BOOL ctl_rint_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/********************************************************************/
/* end an int field */

{
    int			value;
    char		str[100];
    BOOL		any_max;
    
    if( !ctl_int_finish( elt, inst, dlg, ptr ) ) {
	return( FALSE );
    }
    
    value = _value_int( ptr, elt );
    
    any_max = elt->info.rint.max >= elt->info.rint.min;
    if( value < elt->info.rint.min || ( any_max && 
					value > elt->info.rint.max ) ) {
	SetFocus( GetDlgItem( dlg, elt->control ) );
	if( any_max ) {
	    sprintf( str, "Integer must be in the range %d to %d",
				    elt->info.rint.min, elt->info.rint.max );
	} else {
	    sprintf( str, "Integer must be greater than or equal to %d",
							elt->info.rint.min );
	}
	
	MessageBox( dlg, str, NULL, MB_APPLMODAL | MB_ICONHAND | MB_OK );
	
	return( FALSE );
    }
    
    return( TRUE );
}
