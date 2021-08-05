/****************************************************************************
 *
 * (C) Unpublished Copyright of Novell, Inc.  All Rights Reserved.
 *
 * No part of this file may be duplicated, revised, translated, localized
 * or modified in any manner or compiled, linked or uploaded or downloaded
 * to or from any computer system without the prior written permission of
 * Novell, Inc.
 *
 ****************************************************************************/

#ifndef __NWDSTYPE_H
#ifdef __cplusplus
extern "C" {
#endif
#define __NWDSTYPE_H

#ifndef MACINTOSH
	typedef unsigned long uint32;
	typedef signed long int32;
	typedef unsigned short uint16;
	typedef signed short int16;
	typedef unsigned char uint8;
	typedef signed char int8;
	#define NWUNSIGNED unsigned

#if !defined( __WINDOWS_H)
#  if !defined(BYTE) && !defined(OS2DEF_INCLUDED)
#    define BYTE unsigned char
#  endif

#  ifndef WORD
#    define WORD unsigned short
#  endif

#  ifndef DWORD
#    define DWORD unsigned long
#  endif

#  ifndef LONG
#    define LONG unsigned long
#  endif
#endif			/* if !defined( __WINDOWS_H) */

#ifndef NULL
#  if defined(__TINY__) || defined(__SMALL__) || defined(__MEDIUM__)
#    define  NULL 0
#  elif defined(M_I86TM) || defined(M_I86SM) || defined(M_I86MM)
#    define  NULL 0
#  elif NWNLM					/* remain the same as CLib headers... */
#    define NULL 0
#  else							/* all others than defined above... */
#    define  NULL 0L
#  endif
#endif

#ifndef TRUE
#  define TRUE     1
#endif

#ifndef FALSE
#  define FALSE    0
#endif

#ifndef NWCONN_ID
#  define NWCONN_ID unsigned int
#endif
										 
#ifndef NWCONN_NUM
#  define NWCONN_NUM unsigned int  
#endif

#ifndef NWCONN_NUM_BYTE
#  define NWCONN_NUM_BYTE unsigned char 
#endif

#ifndef NWCCODE
#  define NWCCODE unsigned int
#endif

#ifndef NWDIR_HANDLE
#  define NWDIR_HANDLE unsigned char
#endif

#ifndef NWFILE_HANDLE
#  define NWFILE_HANDLE unsigned int
#endif

/* Scope specifiers */
#define GLOBAL       0
#define PRIVATE      1
#define MY_SESSION   2
#define ALL_SESSIONS 3


#else		/* for the Macintosh... */
#define NWUNSIGNED unsigned long
#ifndef uchar
# define uchar	unsigned char
#endif
#ifndef ushort
# define ushort	unsigned short
#endif
#ifndef ulong
# define ulong	unsigned long
#endif

#ifndef uint8
# define uint8	unsigned char
#endif
#ifndef uint16
# define uint16	unsigned short
#endif
#ifndef uint32
# define uint32	unsigned long
#endif

#ifndef int8
# define int8	char
#endif
#ifndef int16
# define int16	short
#endif
#ifndef int32
# define int32	long
#endif

#include "NWMacTypes.h"
#endif

#ifdef __cplusplus
};
#endif
#endif
