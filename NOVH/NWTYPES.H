/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _NWTYPES_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#if __WATCOMC__ < 900
#pragma aux cdecl "*" parm caller []\
         modify [eax ecx edx fs gs 8087];
#else
#pragma aux cdecl "*" parm caller []\
         modify [eax ecx edx 8087];
#endif

#define LONG unsigned long
#define WORD unsigned short
#define BYTE unsigned char
#define TRUE   1
#define FALSE  0

#define _NWTYPES_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWTYPES_H_INCLUDED  */
