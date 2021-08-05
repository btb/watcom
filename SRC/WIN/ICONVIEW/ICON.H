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
 * ICON.H
 *
 * icon definitions
 *
 */
typedef struct an_icon_resource {
    BYTE	width;
    BYTE	height;
    BYTE	colour_count;
    BYTE	reserved[5];
    DWORD	DIB_size;
    DWORD	DIB_offset;
} an_icon_resource;

typedef struct an_icon {
    BITMAPINFO	*bm;
    BYTE	*xor_mask;
    WORD	xor_size;
    BYTE	*and_mask;
    WORD	and_size;
} an_icon;

typedef struct an_icon_file {
    WORD	reserved;
    WORD	type;
    WORD	count;
    an_icon_resource resources[1];
} an_icon_file;

extern an_icon_file *IconOpen(FILE *);
extern WORD IconCount(an_icon_file *);
extern void IconResInfo(an_icon_file *,an_icon_resource *,unsigned int );
extern an_icon *IconResourceToIcon(FILE *,an_icon_file *,unsigned int );
extern void IconFini(an_icon *);
extern HBITMAP IconToXorBitmap(HDC ,an_icon *);
extern HBITMAP IconToAndBitmap(HDC ,an_icon *);
extern void IconClose(an_icon_file *);
