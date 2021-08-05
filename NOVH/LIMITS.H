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

#ifndef _LIMITS_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#define CHAR_BIT   8
#ifdef __CHAR_SIGNED__
 #define CHAR_MIN   (-128)	/*  minimum value of a char	    */
 #define CHAR_MAX   127 	/*  maximum value of a char	    */
#else
 #define CHAR_MIN   0
 #define CHAR_MAX   255
#endif
#define MB_LEN_MAX 1
#define SCHAR_MAX  127
#define SCHAR_MIN  (-128)
#define UCHAR_MAX  255U
#define SHRT_MAX   32767
#define SHRT_MIN   (-32767-1)
#define USHRT_MAX  65535U
#define INT_MAX    2147483647
#define INT_MIN    (-2147483647-1)
#define UINT_MAX   4294967295U
#define LONG_MAX   2147483647
#define LONG_MIN   (-2147483647-1)
#define ULONG_MAX  4294967295U
#define _LIMITS_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
