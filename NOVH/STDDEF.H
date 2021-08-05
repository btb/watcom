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

#ifndef _STDDEF_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef NO_EXT_KEYS
#include <nwtypes.h>
#endif

#ifndef _SIZE_T_DEFINED_
typedef unsigned int size_t;
#define _SIZE_T_DEFINED_
#endif

#ifndef _WCHAR_T_DEFINED_
#define _WCHAR_T_DEFINED_
typedef unsigned short wchar_t;
#endif

typedef int ptrdiff_t;

#define NULL 0

#define offsetof(typ,id) (size_t)&(((typ*)0)->id)

#define _STDDEF_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _STDDEF_H_INCLUDED  */


