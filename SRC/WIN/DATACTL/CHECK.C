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

 CHECK.C

    This file defines the process routines for Check fields.

*/

#include <windows.h>
#include "ctltype.h"

BOOL ctl_check_start( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/********************************************************************/
/* start check field */

{
    inst = inst;
    
    CheckDlgButton( dlg, elt->control, _value_bool( ptr, elt ) );
    
    return( TRUE );
}

BOOL ctl_check_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/*********************************************************************/
/* end check field */

{
    inst = inst;
    
    _value_bool( ptr, elt ) = IsDlgButtonChecked( dlg, elt->control );
    
    return( TRUE );
}

BOOL ctl_check_modified( ctl_elt *elt, int parm1, LONG parm2 )
/************************************************************/

{
    if( parm1 == elt->control && ( HIWORD( parm2 ) == BN_CLICKED ||
				    HIWORD( parm2 ) == BN_DOUBLECLICKED ) ) {
	return( TRUE );
    }
    
    return( FALSE );
}
