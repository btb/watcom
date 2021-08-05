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
 * TESTCTL.H
 *
 * definitions for the Data Control windows program
 *
 */
#define MENU_ABOUT		1
#define MENU_DIALOG		2


#define STR_LIST_1_START	1
#define STR_LIST_1_2		2
#define STR_LIST_1_3		3
#define STR_LIST_1_END		4
#define STR_LIST_2_START	5
#define STR_LIST_2_1		6
#define STR_LIST_2_END		7

#ifdef __WINDOWS_386__
#define _EXPORT
#else
#define _EXPORT __export
#endif
