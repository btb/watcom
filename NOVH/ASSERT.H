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

#ifndef _ASSERT_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#undef  assert

#ifdef  NDEBUG

   #define assert(__ignore) ((void)0)

#else

   extern void __assert(
            int   _expr,
            char *_exprString, 
            char *_fileName,
            int   _lineNumber );

   #define assert(expr)    __assert( expr,#expr,__FILE__,__LINE__)

#endif

#define _ASSERT_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _ASSERT_H_INCLUDED  */

