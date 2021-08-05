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
 * WFONT.C
 *
 *  Miscellaneous font functions for WATZEE
 *
 */

#include <stdlib.h>
#include <windows.h>
#include "watzee.h"



/*
 * CreateFonts -- set up two logical font structures
 */

extern void CreateFonts( void )
/*****************************/
{
    SmallNormalFont.lfHeight = 9 * CharHeight / 10;
    SmallNormalFont.lfWidth = 2 * CharWidth / 5;
    SmallNormalFont.lfWeight = FW_NORMAL;
    SmallBoldFont.lfHeight = 9 * CharHeight / 10;
    SmallBoldFont.lfWidth = 2 * CharWidth / 5;
    SmallBoldFont.lfWeight = FW_BOLD;
}



/*
 * GetFontInfo -- determine the height and width of the system font
 */

extern void GetFontInfo( void )
/*****************************/
{
    HDC             hdc;
    TEXTMETRIC      tm;
    int		    sc_height;

    hdc = CreateIC( "DISPLAY", NULL, NULL, NULL );
    SelectObject( hdc, GetStockObject( SYSTEM_FONT ) );
    GetTextMetrics( hdc, &tm );
    sc_height = GetSystemMetrics( SM_CYSCREEN );
    CharHeight = min( tm.tmHeight, sc_height/28 );
    SysHeight = tm.tmHeight;
    CharWidth = tm.tmMaxCharWidth;
    DeleteDC( hdc );
}
