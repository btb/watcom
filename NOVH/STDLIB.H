
#ifndef _STDLIB_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/*----------------------------------------------------------------------------*
 *                                                                            *
 *      NetWare 386 Developer's C Runtime library                             *
 *                                                                            *
 *      Standard Library Functions                                            *
 *                                                                            *
 *      (c) Copyright WATCOM Systems Inc. 1988,1989,1990. All rights reserved.*
 *                                                                            *
 *      (c) Copyright.  1989-1990 Novell, Inc.  All rights reserved.          *
 *                                                                            *
 *----------------------------------------------------------------------------*/


#ifndef _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED_
typedef unsigned size_t;
#endif

#ifndef _WCHAR_T_DEFINED_
#define _WCHAR_T_DEFINED_
typedef unsigned short wchar_t;
#endif

#define NULL    0

#define RAND_MAX        32767u
#define EXIT_SUCCESS    0
#define EXIT_FAILURE    0xff
#define MB_CUR_MAX      1

typedef struct  {
        int     quot;
        int     rem;
} div_t;

typedef struct  {
        long    quot;
        long    rem;
} ldiv_t;


/*
 * The following sizes are the maximum sizes of buffers used by the _makepath()
 * and _splitpath() functions. They include space for the '\0' terminator.
 */

#define _MAX_PATH    255 /* maximum length of full pathname */
#define _MAX_SERVER  48  /* maximum length of server name */
#define _MAX_VOLUME  16  /* maximum length of volume component */
#define _MAX_DRIVE   3   /* maximum length of drive component */
#define _MAX_DIR     255 /* maximum length of path component */
#define _MAX_FNAME   9   /* maximum length of file name component */
#define _MAX_EXT     5   /* maximum length of extension component */
#define _MAX_NAME    13  /* maximum length of file name (with extension) */

#ifdef  __INLINE_FUNCTIONS__

#pragma intrinsic(abs,div,labs,ldiv,_lrotl,_lrotr,_rotl,_rotr)

#pragma aux	abort	aborts;
#pragma aux	exit	aborts;

#endif

extern void abort(
         void );

extern int abs(
         int         __j );

extern int atexit(
         void      (*__func)(void) );

extern double atof(
         const char *__nptr );

extern int atoi(
         const char *__nptr );

extern long int atol(
         const char *__nptr );

extern void *bsearch(
         const void *__key,
         const void *__base,
         size_t      __nmemb,
         size_t      __size,
         int       (*__compar)(const void *__pkey,const void *__pbase) );

extern void *calloc(
         size_t      __n,
         size_t      __size );

extern div_t div(
         int         __numer,
         int         __denom );

extern char *ecvt(
         double      __val,
         int         __ndig,
         int        *__dec,
         int        *__sign );

extern void exit(
         int         __status );

extern void _exit(
         int         __status );

extern char *fcvt(
         double      __val,
         int         __ndig,
         int        *__dec,
         int        *__sign );

extern void free(
         void       *__ptr );

extern char *gcvt(
         double      __val,
         int         __ndig,
         char       *__buf );

extern char *getenv(
         const char *__name );

extern char *itoa(
         int         __value,
         char       *__buf,
         int         __radix );

extern long int labs(
         long int    __j );

extern ldiv_t ldiv(
         long int    __numer,
         long int    __denom );

extern unsigned long _lrotl(
         unsigned long __value,
         unsigned int __shift );

extern unsigned long _lrotr(
         unsigned long __value,
         unsigned int __shift );

extern char *ltoa(
         long int    __value,
         char       *__buf,
         int         __radix );

extern void _makepath(
         char       *__path,
         const char *__drive,
         const char *__dir,
         const char *__fname,
         const char *__ext );

extern void *malloc(
         size_t      __size );

extern int max(
         int         __a, 
         int         __b );

extern int min(
         int         __a, 
         int         __b );

extern int mblen(
         const char *__s,
         size_t      __n );

extern size_t mbstowcs(
         wchar_t    *__pwcs,
         const char *__s,
         size_t      __n );

extern int mbtowc(
         wchar_t    *__pwc,
         const char *__s,
         size_t      __n );

extern int putenv(
         const char *__string );

extern void qsort(
         void       *__base,
         size_t      __nmemb,
         size_t      __size,
         int       (*__compar)(const void *,const void *) );

extern int rand(
         void );

extern void *realloc(
         void       *__ptr,
         size_t      __size );

extern unsigned int _rotl(
         unsigned int __value,
         unsigned int __shift );

extern unsigned int _rotr(
         unsigned int __value,
         unsigned int __shift );

extern void _splitpath(
         const char *__path,
         char       *__drive,
         char       *__dir,
         char       *__fname,
         char       *__ext );

extern void srand(
         unsigned int __seed );

extern double strtod(
         const char *__nptr,
         char      **__endptr );

extern long int strtol(
         const char *__nptr,
         char      **__endptr,
         int         __base );

extern unsigned long int strtoul(
         const char *__nptr,
         char      **__endptr,
         int         __base );

extern void swab( 
         char       *__src, 
         char       *__dest, 
         int         __num  );

extern int system(
         const char *__string );

extern char *utoa(
         unsigned int __value,
         char       *__buf,
         int         __radix );

extern char *ultoa(
         unsigned long int __value,
         char       *__buf,
         int         __radix );

extern size_t wcstombs(
         char       *__s,
         const wchar_t *__pwcs,
         size_t      __n );

extern int wctomb(
         char       *__s,
         wchar_t     __wchar );


#define atof(p) strtod(p,(char **)NULL)

#define _STDLIB_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
