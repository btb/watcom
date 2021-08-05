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

 TEXT.C

    This file defines the process routines for Text fields.

*/

#include <windows.h>
#include "ctltype.h"

BOOL ctl_text_start( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/*******************************************************************/
/* start a text field */

{
    inst = inst;
    
    SetDlgItemText( dlg, elt->control, _str_ptr( ptr, elt ) );
    
    return( TRUE );
}

BOOL ctl_text_finish( ctl_elt *elt, HANDLE inst, HWND dlg, void *ptr )
/********************************************************************/
/* end a text field */

{
    char		*str;
    
    inst = inst;
    
    str = _str_ptr( ptr, elt );
    
    GetDlgItemText( dlg, elt->control, str, elt->info.text.text_size );
    
    str[elt->info.text.text_size - 1]= '\0'; // in case of overflow
    
    return( TRUE );
}
