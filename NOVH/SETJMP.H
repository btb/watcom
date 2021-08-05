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

#ifndef _SETJMP_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

typedef unsigned int    jmp_buf[13];

#define setjmp(__env)   _setjmp(__env)

#if defined(__386__)
#  pragma aux _setjmp   parm caller [eax];
#endif

int   _setjmp( 
         jmp_buf  __env );

void  longjmp( 
         jmp_buf  __env, 
         int      __val );

#pragma aux longjmp     aborts;

#define _SETJMP_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _SETJMP_H_INCLUDED */
