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
 * SWITCH.C
 *
 */
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"
#include "mdi.h"
#include "icon.h"
#include "switch.h"

static an_MDI_icon *MDI_Icon;

#define MAX_ICON_STRING		80

/*
 * FillListBox - fills the listbox control of the given dialog,
 * (identified by child_id) with strings which represent the display modes
 * of the various icons found in the fill which contains the MDI icon
 * pointed at by MDI_Icon.
 */

static void FillListBox( HWND dialog, unsigned child_id )
{
    HWND	list_box;
    FILE	*fp;
    an_icon_file *icon_file;
    an_icon_resource res;
    char	buffer[ MAX_ICON_STRING ];
    int		max_icons, i;

    list_box = GetDlgItem( dialog, child_id );
    fp = fopen( MDI_Icon->file_name, "rb" );
    if( !fp ) return;
    icon_file = IconOpen( fp );
    fclose( fp );
    max_icons = IconCount( icon_file );
    for( i = 0; i < max_icons; i++ ) {
	IconResInfo( icon_file, &res, i );
	wsprintf( buffer, "%d x %d - %d colour", 
		res.width, res.height, res.colour_count );
	SendMessage( list_box, LB_ADDSTRING, 0, (LONG) (LPSTR) &buffer );
    }
    SendMessage( list_box, LB_SETCURSEL, MDI_Icon->current_icon, 0L );
    IconClose( icon_file );
} /* FillListBox */

/*
 * SwitchDialogProc - window proc for the dialog which handles the loading
 * of a different icon from the current file.
 */

int FAR _EXPORT PASCAL SwitchDialogProc( HWND dialog,
		    unsigned msg, WORD wparam, LONG lparam )
{
    int		select;

    lparam = lparam;
    switch( msg ) {
    case WM_INITDIALOG:
	/* fill list box with strings representing the various icons */
	FillListBox( dialog, IDLISTBOX );
	break;
    case WM_COMMAND:
	switch( wparam ) {
	case IDLISTBOX:
	    if( HIWORD( lparam ) != LBN_DBLCLK ) break;
	    /* fall through */
	case IDOK:
	    select = (int) SendMessage( GetDlgItem( dialog, IDLISTBOX ), 
		    LB_GETCURSEL, 0, 0L );
	    if( select != LB_ERR ) MDI_Icon->current_icon = select;
	    /* Fall through */
	case IDCANCEL:
	    EndDialog( dialog, wparam != IDCANCEL );
	    break;
	default:
	    return( FALSE );
	}
    default:
	return( FALSE );
    }
    return( TRUE );
} /* SwitchDialogProc */

/*
 * SwitchIcon - switches the icon which is displayed (chosen from
 * all icons available within the file associated with the icon).
 * Returns TRUE if the user chooses an icon type from the file,
 * otherwise returns FALSE. icon->current_icon will be set to the
 * user's choice if they selected a new icon.
 */

int SwitchIcon( an_MDI_icon *icon )
{
    FARPROC	func;
    int		ret_val;

    MDI_Icon = icon;
    func = MakeProcInstance( SwitchDialogProc, Instance );
    ret_val = DialogBox( Instance, "SwitchBox", FrameWindow, func );
    FreeProcInstance( func );
    return( ret_val );
} /* SwitchIcon */
