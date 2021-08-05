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
 * PALETTE.C
 *
 */
#include <windows.h>
#include <stdlib.h>

HPALETTE CreateDIBPalette( BITMAPINFO *info )
{
    unsigned		num_colours, i;
    LOGPALETTE		*palette;
    HPALETTE		palette_handle;
    RGBQUAD		*quads;

    num_colours = info->bmiHeader.biClrUsed;
    if( num_colours == 0 && info->bmiHeader.biBitCount != 24 ) {
	num_colours = 1 << info->bmiHeader.biBitCount;
    }

    palette_handle = (HPALETTE)0;

    if( num_colours ) {
	palette = malloc( sizeof( LOGPALETTE ) + 
		num_colours * sizeof( PALETTEENTRY ) );
	if( palette == NULL ) return( (HPALETTE)0 );
	palette->palNumEntries = num_colours;
	palette->palVersion = 0x300;

	quads = &info->bmiColors[0];
	for( i = 0; i < num_colours; i++ ) {
	    palette->palPalEntry[i].peRed = quads[i].rgbRed;
	    palette->palPalEntry[i].peGreen = quads[i].rgbGreen;
	    palette->palPalEntry[i].peBlue = quads[i].rgbBlue;
	    palette->palPalEntry[i].peFlags = 0;
	}
	palette_handle = CreatePalette( palette );
	free( palette );
    }
    return( palette_handle );
}
