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

 CTLTYPE.C

    This file defines the control data library of functions.
    
*/

#include <windows.h>
#include "ctltype.h"

extern ctl_action Ctl_user_actions[];	// from ctluser.c
extern ctl_action Ctl_int_actions[];	// from ctluser.c

BOOL ctl_dlg_init( HANDLE inst, HWND dlg, void *ptr, void *ctl_ptr )
/******************************************************************/
/* initialize a data control. Returns TRUE if it gets up OK. Could return
   FALSE if a data error occurs */

{
    int			num;
    ctl_elt		*elt;
    clt_def		*ctl;
    
    ctl = ctl_ptr;	// so app doesn't have to do type cast
    
    for( num = ctl->num_ctls, elt = ctl->elts; num > 0; --num, ++elt ) {
	if( elt->type < CTL_USER ) {
	    if( !(Ctl_int_actions[elt->type].setup)( elt, inst, dlg, ptr ) ) {
		return( FALSE );
	    }
	} else {
	    if( !(Ctl_user_actions[elt->type - CTL_USER].setup)
	    					( elt, inst, dlg, ptr ) ) {
		return( FALSE );
	    }
	}
	elt->modified = FALSE;
    }
    
    return( TRUE );
}

BOOL ctl_dlg_done( HANDLE inst, HWND dlg, void *ptr, void *ctl_ptr )
/******************************************************************/
/* finalize a data control. Returns TRUE if all field verification is ok,
   FALSE otherwise */

{
    int			num;
    ctl_elt		*elt;
    clt_def		*ctl;
    
    ctl = ctl_ptr;	// so app doesn't have to do type cast
    
    for( num = ctl->num_ctls, elt = ctl->elts; num > 0; --num, ++elt ) {
	if( elt->modified ) {
	    if( elt->type < CTL_USER ) {
		if( !(Ctl_int_actions[elt->type].finish)( elt, inst, 
								dlg, ptr ) ) {
		    return( FALSE );
		}
	    } else {
		if( !(Ctl_user_actions[elt->type - CTL_USER].finish)
						    ( elt, inst, dlg, ptr ) ) {
		    return( FALSE );
		}
	    }
	}
    }
    
    return( TRUE );
}

void ctl_dlg_process( void *ctl_ptr, WORD parm1, LONG parm2 )
/***********************************************************/
/* this routine must be called for all WM_COMMAND events sent to the
   dialog. */

{
    clt_def		*ctl;
    ctl_elt		*elt;
    int			num;
    BOOL		mod;
    
    ctl = ctl_ptr;	// so app doesn't have to do type cast
    
    for( num = ctl->num_ctls, elt = ctl->elts; num > 0; --num, ++elt ) {
	if( elt->type < CTL_USER ) {
	    mod = (Ctl_int_actions[elt->type].modified)( elt, parm1, parm2 );
	    elt->modified |= mod;
	    if( mod ) {
		break;
	    }
	} else {
	    mod = (Ctl_user_actions[elt->type - CTL_USER].modified)
							( elt, parm1, parm2 );
	    elt->modified |= mod;
	    if( mod ) {
		break;
	    }
	}
    }
}
