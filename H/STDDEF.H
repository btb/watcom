/*
 *  stddef.h	Standard definitions
 *
 *  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
 */
#ifndef _STDDEF_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED_
 typedef unsigned size_t;
#endif

#ifndef _WCHAR_T_DEFINED_
#define _WCHAR_T_DEFINED_
#ifdef __cplusplus
typedef long char wchar_t;
#else
typedef unsigned short wchar_t;
#endif
#endif

#ifndef NULL
 #if defined(__SMALL__) || defined(__MEDIUM__) || defined(__386__)
  #define NULL   0
 #else
  #define NULL   0L
 #endif
#endif

#ifndef _PTRDIFF_T_DEFINED_
#define _PTRDIFF_T_DEFINED_
 #if defined(__HUGE__)
  typedef long	ptrdiff_t;
 #else
  typedef int	ptrdiff_t;
 #endif
#endif

#ifdef __cplusplus
#define offsetof __offsetof
#else
#define offsetof(typ,id) (size_t)&(((typ*)0)->id)
#endif
/* define pragma for 'cdecl'  keyword to match Microsoft conventions */
/* define pragma for 'pascal' keyword to match Microsoft conventions */
#if defined( __WINDOWS_386__ )
 #pragma aux cdecl "_*" parm caller []\
   value struct float struct routine [eax]  modify [eax ebx ecx edx fs gs];
 #pragma aux pascal "^" parm routine reverse []\
   value struct float struct caller []  modify [eax ebx ecx edx fs gs];
 #pragma aux fortran "^";
#elif defined( __386__ )
 #pragma aux cdecl "_*" parm caller []\
   value struct float struct routine [eax]  modify [eax ebx ecx edx];
 #pragma aux pascal "^" parm routine reverse []\
   value struct float struct caller []  modify [eax ebx ecx edx];
 #pragma aux fortran "^";
#else
 #pragma aux cdecl "_*" parm caller loadds []\
   value struct float struct routine [ax]  modify [ax bx cx dx es];
 #pragma aux pascal "^" parm routine reverse []\
   value struct float struct caller []  modify [ax bx cx dx es];
 #pragma aux fortran "^";
#endif
#if !defined(NO_EXT_KEYS) /* extensions enabled */
#ifdef __386__
 extern int *__threadid(void);	/* pointer to thread id */
 #define _threadid (__threadid())
#else
 extern int __far *_threadid;			/* pointer to thread id */
#endif
#endif
#define _STDDEF_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
