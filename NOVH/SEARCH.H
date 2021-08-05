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

#ifndef _SEARCH_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

char  *lfind(
         void     *__key,
         void     *__base,
         unsigned *__num,
         unsigned  __width,
         int    (* __compare)(void *,void *));

char  *lsearch(
         void     *__key,
         void     *__base,
         unsigned *__num,
         unsigned __width,
         int   (* __compare)(void *,void *));

#define _SEARCH_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
