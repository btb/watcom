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

#ifndef _TIME_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(1);

#ifndef _SIZE_T_DEFINED_
 #define _SIZE_T_DEFINED_
 typedef unsigned size_t;
#endif

#define NULL 0

#ifndef _TIME_T_DEFINED_
 #define _TIME_T_DEFINED_
 typedef unsigned long time_t;    /* time value */
#endif

#define CLOCKS_PER_SEC  100
typedef unsigned long   clock_t;

struct   tm {
   int  tm_sec;   /* seconds after the minute -- [0,61] */
   int  tm_min;   /* minutes after the hour   -- [0,59] */
   int  tm_hour;  /* hours after midnight     -- [0,23] */
   int  tm_mday;  /* day of the month         -- [1,31] */
   int  tm_mon;   /* months since January     -- [0,11] */
   int  tm_year;  /* years since 1900                   */
   int  tm_wday;  /* days since Sunday        -- [0,6]  */
   int  tm_yday;  /* days since January 1     -- [0,365]*/
   int  tm_isdst; /* Daylight Savings Time flag         */
};

char *asctime( 
         const struct tm  *__timeptr );
clock_t clock( 
         void);
char *ctime( 
         const time_t *__timer );
double difftime( 
         time_t        __t1, 
         time_t        __t0 );
struct tm *gmtime( 
         const time_t *__timer );
struct tm *localtime( 
         const time_t *__timer );
time_t mktime( 
         struct tm    *__timeptr );
size_t strftime( 
         char         *__s,
         size_t        __maxsiz,
         const char   *__fmt,
         const struct tm *__tp );
time_t time( 
         time_t       *__timer );


#define difftime( t1, t0 ) ((double)(t1)-(double)(t0))

#ifndef NO_EXT_KEYS        /* extensions enabled    */

typedef unsigned long   clockAndStatus[3];

clock_t __get_CLK_TCK();

#define CLK_TCK __get_CLK_TCK()

void GetClockStatus(clockAndStatus _dataPtr);

void  tzset(void);

extern long  timezone;     /* # of seconds from UTC */
extern int   daylight;     /* subject to d.s.t. indicator      */
extern long  daylightOffset; /* Add this when going onto d. s. t.*/
extern int   daylightOnOff;     /* current d.s.t. status      */
extern char  *tzname[2];   /* time zone names */
#endif

#pragma pack();
#define _TIME_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
