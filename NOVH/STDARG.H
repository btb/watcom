/****************************************************************************
*
* (C) Unpublished Copyright Novell, Inc. All Rights Reserved.
* (c) Copyright WATCOM Systems Inc. 1989. All rights reserved.
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*****************************************************************************/

#ifndef _STDARG_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

typedef char   *va_list[1];

#define va_start(ap,parm_n) ((ap)[0]=(char *)&parm_n+\
         ((sizeof(parm_n)+sizeof(int)-1)&~(sizeof(int)-1)))

#define va_arg(ap,type)     ((ap)[0]+=\
         ((sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1)),\
         (*(type *)((ap)[0]-((sizeof(type)+sizeof(int)-1)&~(sizeof(int)-1)))))

#define va_end(ap)          ((ap)[0]=0,(void)0)

#define _STDARG_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
