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


#ifndef __NWLOCALE_H__
#ifdef __cplusplus
extern "C" {
#endif
#include <stdio.h>
#include <locale.h>
#include <stdarg.h>
#include <stddef.h>       /* has 'size_t' */

#define _SIZE_T_DEFINED
#define _SIZE_T

#ifdef NXT_GEN
#define NUMBER_TYPE LONG
#else
#define NUMBER_TYPE double
#endif

#if !defined(_SIZE_T_DEFINED) && !defined (_SIZE_T) && !defined(_SIZE_T_DEFINED_)
typedef unsigned int size_t;
# define _SIZE_T
#endif

/* (in imitation of stdlib.h) */

#define L_MB_LEN_MAX       2   /* (in imitation of limits.h) */
#define MERIDLEN           5
#define NWSINGLE_BYTE      1
#define NWDOUBLE_BYTE      2
#define _UCHAR             (unsigned char)


/*============================================================================
   typedef Llconv
============================================================================*/
typedef struct Llconv
   {
   char decimal_point[4];                     /* non-monetary decimal point */
   char thousands_sep[4];   /* non-monetary separator for digits left of the
                               decimal-point */
   char grouping[4];           /* String indicating size of groups of digits*/
   /*
    The international currency symbol applicable to the current locale.
    The first three characters contain the alphabetic international currency
    symbol in accordance with those specified in ISO 4217 "codes for the
    representation of currency and funds." The fourth character is the
    character used to separate the international currency symbol from the
    monetary quantity.
   */
   char int_curr_symbol[8];
   char currency_symbol[4];       /* Currency symbol for the current locale.*/
   char mon_decimal_point[4];                     /* monetary decimal point */
   char mon_thousands_sep[4];     /* monetary separator for digits left of the
                                     decimal-point */
   char mon_grouping[8];       /* String indicating size of groups of digits*/
   char positive_sign[4];        /* Sign indicating positive monetary value */
   char negative_sign[4];        /* Sign indicating negative monetary value */
   char int_frac_digits;     /* Num of fractional digits in monetary display*/
   char frac_digits;     /* Num of fractional digits in non-monetary display*/
   char p_cs_precedes;      /* 1=precede or 0=succeeds (pos currency symbol)*/
   char p_sep_by_space;    /* 1=space sep or 0=no space sep (currency symbol*/
   char n_cs_precedes; /* location of currency_symbol for neg monetary quant*/
   char n_sep_by_space;  /* separation of currency sym in neg monetary quant*/
   char p_sign_posn;         /* value indicating position of positive_sign for
                                 nonnegative monetary quantity.*/
   char n_sign_posn;         /* value indicating position of negative_sign for
                                negative formatted monetary quantity.*/
   /* Novell Additions to the ANSI definition:*/
   unsigned short code_page;
   unsigned short country_id;
   char data_list_separator[2];
   char date_separator[2];
   char time_separator[2];
   char time_format;
   unsigned short date_format;
   char reserved[50];
} LCONV;


/*============================================================================
   macros
============================================================================*/

#define NWNextChar(s) s + ( (NWCharType(*s) == NWSINGLE_BYTE) ? 1 : 2 )

#define _NWIncrement(s,x) (_DBCSVector[0].lowValue == 0) \
             ? (s + x) : NWIncrement(s,x)


/*============================================================================
   function prototypes
============================================================================*/

int      NWLatoi( 
         char *string );

int      NWLisalnum( 
         unsigned int ch );

int      NWLisalpha( 
         unsigned int ch );

int      NWLisdigit( 
         unsigned int ch );

LCONV    *NWLlocaleconv(
         LCONV  *lconvPtr);

int      NWLmblen(
         char  *string,
         size_t maxBytes);

char     *NWLsetlocale(
         int category,
         const char  *locale);

char     *NWLstrchr(
         char  *string,
         int find);

int      NWLstrcoll( 
         char  *string1, 
         char  *string2);

size_t   NWLstrcspn(
         const char  *string1,
         const char  *string2);

size_t   NWLstrftime(
         char  *string,
         size_t maxSize,
         char  *format,
         struct tm  *timePtr);

char     *NWLstrpbrk(
         char  *string1,
         const char  *string2);

char     *NWLstrrchr(
         char  *string,
         int find);

char     *NWLstrrev(
         char  *string1,
         char  *string2);

size_t   NWLstrspn(
         const char  *string1,
         const char  *string2);

char     *NWLstrstr(
         char  *string,
         char  *searchString);

char     *NWLstrupr ( 
         char  *string );

size_t   NWLstrxfrm(
         char  *string1,
         char  *string2,
         size_t numChars);
                
char     *NWIncrement(
         char  *string,
         size_t numChars);

char     *NWstrImoney(
         char  *buffer,
         NUMBER_TYPE Value);

char     *NWstrmoney(
         char  *buffer,
         NUMBER_TYPE Value);

int      NWstrncoll(
         char  *string1,
         char  *string2,
         size_t maxBytes);

char     *NWstrncpy(
         char  *target_string,
         char  *source_string,
         int numChars);

int      NWCharType(
         unsigned int ch);

int      NWCharVal(
         char  *);

int      NWCharUpr ( 
         int chr );

char     *NWPrevChar(
         const char  *string,
         char  *position);

char     *NWstrnum(
         char  *buffer,
         NUMBER_TYPE Value);


/*============================================================================
   printf family
============================================================================*/

int      NWcprintf(
         char *__format,
         ...);

int      NWfprintf(
         FILE *fp,
         char *__format,
         ...);

int      NWprintf(
         char *__format,
         ...);

int      NWsprintf(
         char       *__s,
         char *__format,
         ...);

int      NWvcprintf(
         char *__format,
         va_list arg);

int      NWvfprintf(
         FILE *fp,
         char *__format,
         va_list arg);

int      NWvprintf(
         char *__format,
         va_list arg);

int      NWvsprintf(
         char       *__s,
         char *__format,
         va_list arg);


#define __NWLOCALE_H__
#ifdef __cplusplus
};
#endif
#endif
