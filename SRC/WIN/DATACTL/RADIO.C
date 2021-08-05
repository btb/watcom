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

 RADIO.C

    This file defines the process routines for Radio button fields.

*/

#include <windows.h>
#include "ctltype.h"

BOOL ctl_radio_start( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/********************************************************************/
/* start a radio button */

{
    int			value;
    
    inst = inst;
    
    value = _value_int( ptr, elt );
    
    if( value != 0 ) {
	CheckRadioButton( dlg, elt->control, elt->info.radio.end_control,
				elt->control + _value_int( ptr, elt ) - 1 );
    }
    
    return( TRUE );
}
    
BOOL ctl_radio_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/*********************************************************************/
/* finish a radio button */

{
    int			control;
    
    inst = inst;
    
    for( control = elt->info.radio.end_control; control >= elt->control;
							    --control ) {
	if( IsDlgButtonChecked( dlg, control ) ) {
	    _value_int( ptr, elt ) = control - elt->control + 1;
	    
	    break;
	}
    }
    
    return( TRUE );
}

BOOL ctl_radio_modified( ctl_elt *elt, int parm1, LONG parm2 )
/************************************************************/

{
    if( parm1 >= elt->control && parm1 <= elt->info.radio.end_control &&
				    ( HIWORD( parm2 ) == BN_CLICKED ||
				    HIWORD( parm2 ) == BN_DOUBLECLICKED ) ) {
	return( TRUE );
    }
    
    return( FALSE );
}
