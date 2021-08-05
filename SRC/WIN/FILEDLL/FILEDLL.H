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
 * FILEDLL.H
 *
 * file/io dialogues
 *
 */
#define FILE_SAVE		0
#define FILE_OPEN		1
#define FILE_SAVE_VERIFY	2

typedef struct fileopen {
BYTE	type;		/* kind of open (save/load) */
HWND	hwnd;		/* owner of dialog box */
LPSTR	name;		/* where to store name */
WORD	namelen;	/* length of name */
LPSTR	ext;		/* default extension */
LPSTR	title;		/* title of dialog box */
} FILEOPEN;

#ifdef __WINDOWS_386__
typedef struct fileopen *LPFILEOPEN;
#else
typedef struct fileopen __far *LPFILEOPEN;
#endif
