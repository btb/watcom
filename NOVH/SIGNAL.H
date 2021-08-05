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

#ifndef _SIGNAL_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef NO_EXT_KEYS

#define CHAIN_SHARE_BIT               1
#define ILLEGIAL_INSTRUCTION          6
#define CLIB_SEGMENTATION_VIOLATION   11
#define CLIB_GENERAL_PROTECTION_FAULT 13
#define CLIB_PAGE_FAULT               14

#endif

typedef int sig_atomic_t;

#define SIG_IGN (void (*)(int)) 1
#define SIG_DFL (void (*)(int)) 2
#define SIG_ERR (void (*)(int)) 3

#define SIGABRT   1
#define SIGFPE    2
#define SIGILL    3
#define SIGINT    4
#define SIGSEGV   5
#define SIGTERM   6
#define SIGPOLL   7
#define _SIGMAX     SIGPOLL
#define _SIGMIN     1

#define _SIGLAST  SIGPOLL

void  (*signal( 
         int      __sig, 
         void   (*__func)(int) ) )(int);

int   raise(
         int      __sig );

void __SigIllError();
void __SigSVError();
void __SigPFError();

#define _SIGNAL_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
