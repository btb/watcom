/*
 *  string.h	String functions
 *
 *  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
 */
#ifndef _STRING_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED_
 typedef unsigned size_t;
#endif

#ifndef NULL
 #if defined(__SMALL__) || defined(__MEDIUM__) || defined(__386__)
  #define NULL   0
 #else
  #define NULL   0L
 #endif
#endif

void *memchr( const void *__s, int __c, size_t __n );
int   memcmp( const void *__s1, const void *__s2, size_t __n );
void *memcpy( void *__s1, const void *__s2, size_t __n );
void *memmove( void *__s1, const void *__s2, size_t __n );
void *memset( void *__s, int __c, size_t __n );
char *strcat( char *__s1, const char *__s2 );
char *strchr( const char *__s, int __c );
int strcmp( const char *__s1, const char *__s2 );
int strcoll( const char *__s1, const char *__s2 );
size_t strxfrm( char *__s1, const char *__s2, size_t __n );
char *strcpy( char *__s1, const char *__s2 );
size_t strcspn( const char *__s1, const char *__s2 );
char *strerror( int __errnum );
size_t strlen( const char *__s );
char *strncat( char *__s1, const char *__s2, size_t __n );
int strncmp( const char *__s1, const char *__s2, size_t __n );
char *strncpy( char *__s1, const char *__s2, size_t __n );
char *strpbrk( const char *__s1, const char *__s2 );
char *strrchr( const char *__s, int __c );
size_t strspn( const char *__s1, const char *__s2 );
char *strstr( const char *__s1, const char *__s2 );
char *strtok( char *__s1, const char *__s2 );

#if !defined(NO_EXT_KEYS) /* extensions enabled */

/* WATCOM's Additional Functions (non-ANSI, non-POSIX) */

void __far *_fmemccpy(void __far *__s1,const void __far *__s2,int __c,size_t __n);
void __far *_fmemchr( const void __far *__s, int __c, size_t __n );
void __far *_fmemcpy( void __far *__s1, const void __far *__s2, size_t __n );
void __far *_fmemmove( void __far *__s1, const void __far *__s2, size_t __n );
void __far *_fmemset( void __far *__s, int __c, size_t __n );
int  _fmemcmp( const void __far *__s1, const void __far *__s2, size_t __n );
int  _fmemicmp( const void __far *__s1, const void __far *__s2, size_t __n );
char __far *_fstrcat( char __far *__s1, const char __far *__s2 );
char __far *_fstrchr( const char __far *__s, int __c );
int  _fstrcmp( const char __far *__s1, const char __far *__s2 );
char __far *_fstrcpy( char __far *__s1, const char __far *__s2 );
size_t _fstrcspn( const char __far *__s1, const char __far *__s2 );
int  _fstricmp( const char __far *__s1, const char __far *__s2 );
char __far *_fstrncat( char __far *__s1, const char __far *__s2, size_t __n );
size_t _fstrlen( const char __far *__s );
char __far *_fstrlwr( char __far *__string );
int  _fstrncmp( const char __far *__s1, const char __far *__s2, size_t __n );
char __far *_fstrncpy( char __far *__s1, const char __far *__s2, size_t __n );
int  _fstrnicmp( const char __far *__s1, const char __far *__s2, size_t __n );
char __far *_fstrnset( char __far *__string, int __c, size_t __len );
char __far *_fstrpbrk( const char __far *__s1, const char __far *__s2 );
char __far *_fstrrchr( const char __far *__s, int __c );
char __far *_fstrrev( char __far *__string );
char __far *_fstrset( char __far *__string, int __c );
size_t _fstrspn( const char __far *__s1, const char __far *__s2 );
char __far *_fstrstr( const char __far *__s1, const char __far *__s2 );
char __far *_fstrtok( char __far *__s1, const char __far *__s2 );
char __far *_fstrupr( char __far *__string );
void movedata( unsigned __srcseg, unsigned __srcoff,
	       unsigned __tgtseg, unsigned __tgtoff, unsigned __len );
void *memccpy( void *__s1, const void *__s2, int __c, size_t __n );
int  memicmp( const void *__s1, const void *__s2, size_t __n );
int   strcmpi( const char *__s1, const char *__s2 );
char *strdup( const char *__string );
int   stricmp( const char *__s1, const char *__s2 );
char *strlwr( char *__string );
int   strnicmp( const char *__s1, const char *__s2, size_t __n );
char *strnset( char *__string, int __c, size_t __len );
char *strrev( char *__string );
char *strset( char *__string, int __c );
char *strupr( char *__string );

#endif	/* EXTENSIONS */

#ifdef	__INLINE_FUNCTIONS__
#if !defined(NO_EXT_KEYS) /* extensions enabled */
 #pragma intrinsic(movedata,_fmemchr,_fmemcmp,_fmemcpy,_fmemset)
 #pragma intrinsic(_fstrcat,_fstrcmp,_fstrcpy,_fstrlen)
#endif
 #pragma intrinsic(memchr,memcmp,memcpy,strcat,strcpy,strlen,strchr)
 #ifndef __386__
 #pragma intrinsic(memset,strcmp)
 #endif
#endif	/* __INLINE_FUNCTIONS__ */

#define _STRING_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
