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
 * BITMAP.H
 *
 */
#define BITMAP_TYPE	( (((WORD)'M')<<8)+'B' )

/* this macros determines the number of bytes of storage needed by a bitmap */
#define BITS_TO_BYTES( x, y )	( ( ( ( x ) + 31 ) / 32 ) * 4 * ( y ) )

#define BITMAP_INFO_SIZE( bm )  ( sizeof(BITMAPINFO) + \
				    sizeof(RGBQUAD) * ((1<<(bm)->biBitCount)-1))


/* this function is only for use inside the resource library */

extern HBITMAP ReadBitmapFile( HWND, char *);
extern HBITMAP RequestBitmapFile( void );
