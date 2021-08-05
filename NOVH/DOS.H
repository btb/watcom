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

#ifndef _DOS_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>
#include <time.h>

struct _DOSTime
   {
   WORD bisecond : 5;          /* two second increments (0 - 29)             */
   WORD minute   : 6;          /* 0 - 59                                     */
   WORD hour     : 5;          /* 0 - 23                                     */
   };

struct _DOSDate
   {
   WORD day          : 5;      /* 1 - 31                                     */
   WORD month        : 4;      /* 1 - 12                                     */
   WORD yearsSince80 : 7;      /* years since 1980 (0 - 119)                 */
   };

#pragma pack(1);
struct find_t
   {
   char           reserved[21];
   char           attrib;
   unsigned short wr_time;
   unsigned short wr_date;
   long           size;
   char           name[13];
   };

extern int DOSClose( 
         int __handle );

extern int DOSCopy( 
         char *__NetWareFileName, 
         char *__DOSFileName );

extern int DOSCreate( 
         char *__fileName, 
         int  *__handle);

extern int DOSsopen( 
         const char *filename, 
         int         access, 
         int         share, 
         int         permission );

extern int DOSFindFirstFile( 
         char          *__fileName, 
         WORD           __searchAttributes,
         struct find_t *__diskTransferAddress );

extern int DOSFindNextFile( 
         struct find_t *__diskTransferAddress );

extern int DOSOpen( 
         char *__fileName, 
         int  *__handle );

extern int DOSPresent( 
         void );

extern int DOSRead( 
         int   __handle, 
         LONG  __fileOffset, 
         char *__buffer,
         LONG  __numberOfBytesToRead, 
         LONG *__numberOfBytesRead );

extern int DOSWrite( 
         int   __handle, 
         LONG  __fileOffset, 
         char *__buffer,
         LONG  __numberOfBytesToWrite, 
         LONG *__numberOfBytesWritten );

extern void _ConvertTimeToDOS( 
         LONG             __calendarTime, 
         struct _DOSDate *__filDatP,
         struct _DOSTime *__filTimP);

extern time_t _ConvertDOSTimeToCalendar( 
         LONG __dateTime );


#define _DOS_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _DOS_H_INCLUDED  */
