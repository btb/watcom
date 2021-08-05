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

#ifndef _STRING_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED_
typedef unsigned size_t;
#endif

#define NULL   0

#ifdef   __INLINE_FUNCTIONS__

#pragma intrinsic(memchr,memcmp,memcpy,strcat,strcpy,strlen,strchr)
#pragma intrinsic(memset,strcmp)

#endif /* __INLINE_FUNCTIONS__ */

void *memchr( 
         const void *__s, 
         int         __c, 
         size_t      __n );

int   memcmp( 
         const void *__s1, 
         const void *__s2, 
         size_t      __n );

void *memcpy( 
         void       *__s1, 
         const void *__s2, 
         size_t      __n );

void *memmove( 
         void       *__s1, 
         const void *__s2, 
         size_t      __n );

void *memset( 
         void       *__s, 
         int         __c, 
         size_t      __n );

char *strcat( 
         char       *__s1, 
         const char *__s2 );

char *strchr( 
         const char *__s, 
         int         __c );

int   strcmp( 
         const char *__s1, 
         const char *__s2 );

int   strcoll( 
         const char *__s1, 
         const char *__s2 );

char *strcpy( 
         char       *__s1, 
         const char *__s2 );

size_t strcspn( 
         const char *__s1, 
         const char *__s2 );

char *strncat( 
         char       *__s1, 
         const char *__s2, 
         size_t      __n );

char *strerror( 
         int         __errnum );

size_t strlen( 
         const char *__s );

int   strncmp( 
         const char *__s1, 
         const char *__s2, 
         size_t      __n );

char *strncpy( 
         char       *__s1, 
         const char *__s2, 
         size_t      __n );

char *strpbrk( 
         const char *__s1, 
         const char *__s2 );

char *strrchr( 
         const char *__s, 
         int         __c );

size_t strspn( 
         const char *__s1, 
         const char *__s2 );

char *strstr( 
         const char *__s1, 
         const char *__s2 );

char *strtok( 
         char       *__s1, 
         const char *__s2 );

size_t strxfrm( 
         char       *__s1, 
         const char *__s2, 
         size_t      __n );

/* non-ANSI */
#ifndef NO_EXT_KEYS /* extensions enabled */

void *memccpy(
         void *__s1,
 	 const void *__s2,
	 int __c,
	 size_t __n );

int   memicmp( 
         const void *__s1, 
         const void *__s2, 
         size_t __n );

int   strcmpi( 
         const char *__s1, 
         const char *__s2 );

char *strdup( 
         const char *__string );

int   stricmp( 
         const char *__s1, 
         const char *__s2 );

char *strlwr( 
         char       *__string );

int   strnicmp( 
         const char *__s1, 
         const char *__s2, 
         size_t      __n );

char *strnset( 
         char       *__string, 
         int         __c, 
         size_t      __len );

char *strrev( 
         char       *__string );

char *strset( 
         char       *__string, 
         int         __c );

char *strupr( 
         char       *__string );

#endif

#define _STRING_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
