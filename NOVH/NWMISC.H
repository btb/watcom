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

#ifndef _NWMISC_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

int   ASCIIZToLenStr(
         char *__lenString,
         char *__ASCIIZstring );

int   ASCIIZToMaxLenStr(
         char *__lenString,
         char *__ASCIIZstring,
         int __maximumLength );

int   ConvertNameToFullPath(
         char *__partialPath,
         char *__fullPath );

int   ConvertNameToVolumePath(
         char *__fileName,
         char *__volumePath );

void  _disable(
         void );

void  _enable(
         void );

LONG  GetCurrentTicks(
         void );

WORD  IntSwap(
         WORD __wordToSwap );

char *LenStrCat(
         char *__destStr,
         char *__srcStr );

int   LenStrCmp(
         char *__string1,
         char *__string2 );

char *LenStrCpy(
         char *__destStr,
         char *__srcStr );

int   LenToASCIIZStr(
         char *__ASCIIZstring,
         char *__lenString );

long  LongSwap(
         long __longToBeSwapped );

int   ParsePath(
         char *__path,
         char *__server,
         char *__volume, 
         char *__directories );

char *RemovePVCSKeyword(
         char *__outBuf,
         char *__inBuf,
         char *__replacement,
         char *__keyword );

void  SecondsToTicks(
         LONG __Seconds,
         LONG __TenthsOfSeconds,
         LONG *__Ticks);

BYTE  SetWildcardTranslationMode(
         BYTE __newMode );

char  *StripFileServerFromPath(
         char *__path,
         char *__server );

int   strtoi(
         const char * __p,
         int __base );

void  TicksToSeconds(
         LONG __Ticks,
         LONG *__Seconds,
         LONG *__TenthsOfSeconds );

#define _NWMISC_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWMISC_H_INCLUDED  */
