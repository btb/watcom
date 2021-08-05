/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
* (c) Copyright WATCOM Systems Inc. 1988. All rights reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _LOCALE_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1);

#define LC_CTYPE	0
#define LC_NUMERIC	1
#define LC_TIME 	2
#define LC_COLLATE	3
#define LC_MONETARY	4
#define LC_MESSAGES	5
#define LC_ALL		6

struct   lconv {
   char *decimal_point;
   char *thousands_sep;
   char *grouping;
   char *int_curr_symbol;
   char *currency_symbol;
   char *mon_decimal_point;
   char *mon_thousands_sep;
   char *mon_grouping;
   char *positive_sign;
   char *negative_sign;
   char int_frac_digits;
   char frac_digits;
   char p_cs_precedes;
   char p_sep_by_space;
   char n_cs_precedes;
   char n_sep_by_space;
   char p_sign_posn;
   char n_sign_posn;
};


extern char *setlocale(
                int        __category,
                const char *__locale);

extern struct lconv *localeconv(
                          void);
#pragma pack();

#define _LOCALE_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
