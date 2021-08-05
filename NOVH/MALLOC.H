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

#ifndef _MALLOC_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _STDDEF_H_INCLUDED
#include <stddef.h>
#endif

void  *alloca(
         size_t __size );
void  *__alloca(
         size_t __size );
void   __push_eax(
         int __value );

#define __ALLOCA_ALIGN( s )	 (((s)+(sizeof(int)-1))&~(sizeof(int)-1))

#define alloca(size) (__push_eax(stackavail()),__alloca(__ALLOCA_ALIGN(size)))

#pragma aux     __push_eax = 0x50      /* push eax */\
                             parm caller [eax];

#pragma aux     __alloca =   \
                             0x59           /*          pop  ecx          */\
                             0x85 0xC0      /*          test eax, eax     */\
                             0x74 0x0F      /*          jz   short err    */\
                             0x8D 0x40 0x03 /*          lea  eax, [eax+3] */\
                             0x24 0xFC      /*          and  al, 0FCh     */\
                             0x3B 0xC1      /*          cmp  eax, ecx     */\
                             0x7F 0x06      /*          jg   short err    */\
                             0x2B 0xE0      /*          sub  esp, eax     */\
                             0x8B 0xC4      /*          mov  eax, esp     */\
                             0xEB 0x02      /*          jmp  done         */\
                                            /* err:                       */\
                             0x33 0xC0      /*          xor  eax, eax     */\
                                            /* done:                      */\
                             parm caller [eax] value[eax] modify [esp ecx];

void  *calloc(
         size_t __n,
         size_t __size );

void  free(
         void *__ptr );

void  *malloc(
         size_t __size );

size_t _msize(
         void *__buffer );

void *__qcalloc(
         size_t __n, size_t __el_size );

void  *__qmalloc(
         size_t __size );

void *__qrealloc(
         void *__old, size_t __size );

void  *realloc(
         void *__oldMem,
         size_t __size );

size_t stackavail(
         void );

#define _MALLOC_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _MALLOC_H_INCLUDED  */
