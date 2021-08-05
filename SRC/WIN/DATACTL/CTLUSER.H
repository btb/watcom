#ifndef CTLUSER_H
#define CTLUSER_H
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
 
 CTLUSER.H
 
    This file defines the default 'ctl_info' structure, and is included
    by 'ctltype.h'. Modify this file to define your own field types.
    
*/

/*  Define the control IDs of your field types here. Define an ENUM
    list as follows:
	enum {
	    CTL_YOUR_FIELD_1		= CTL_USER,
	    CTL_YOUR_FIELD_2,
	    ...
	};
*/

/*  Add your field data structures to this union.
    **** NOTE: make the enum names above and the ctl_... typedef names below 
               the same, except in upper case. This is necessary since
	       PARSECTL.EXE assumes this when building the data control
	       file */
typedef union {
    ctl_radio		radio;
    ctl_text		text;
    ctl_combo		combo;
    ctl_dcombo		dcombo;
    ctl_rint		rint;
    ctl_rfloat		rfloat;
} ctl_info;


#endif

