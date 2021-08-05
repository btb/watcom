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

 COMBOMOD.C

    This file defines ctl_combo_modified, used to determine if a list
    box field has been modified.

*/

#include <windows.h>
#include "ctltype.h"
#include <string.h>

BOOL ctl_combo_modified( ctl_elt *elt, int parm1, LONG parm2 )
/************************************************************/

{
    if( parm1 == elt->control && ( HIWORD( parm2 ) == CBN_SELCHANGE ||
				    HIWORD( parm2 ) == LBN_SELCHANGE ) ) {
	return( TRUE );
    }
    
    return( FALSE );
}

static BOOL is_listbox( HWND dlg, int ctl )
/*****************************************/

{
    char		buf[100];
    
    GetClassName( GetDlgItem( dlg, ctl ), buf, 100 );
    if( 0 == stricmp( buf, "listbox" ) ) {
	return( TRUE );
    }
    
    return( FALSE );
}

WORD ctl_combo_add_msg( HWND dlg, int ctl )
/*****************************************/

{
    if( is_listbox( dlg, ctl ) ) {
	return( LB_ADDSTRING );
    } else {
	return( CB_ADDSTRING );
    }
}

WORD ctl_combo_sel_msg( HWND dlg, int ctl )
/*****************************************/

{
    if( is_listbox( dlg, ctl ) ) {
	return( LB_SETCURSEL );
    } else {
	return( CB_SETCURSEL );
    }
}

WORD ctl_combo_get_msg( HWND dlg, int ctl )
/*****************************************/

{
    if( is_listbox( dlg, ctl ) ) {
	return( LB_GETCURSEL );
    } else {
	return( CB_GETCURSEL );
    }
}

