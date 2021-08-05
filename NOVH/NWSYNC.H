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

#ifndef _SYNCSERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define _MAX_LOGREC_NAME 128
#define _MAX_SEMAPHORE_NAME 128

int   ClearFile(
         char * __fileName);

void  ClearFileSet(
         void);

int   ClearLogicalRecord(
         char * __logicalRecordName );

void  ClearLogicalRecordSet(
         void );

int   ClearPhysicalRecord(
         int __fileHandle,
         long __recordStartOffset,
         long __recordLength );

void  ClearPhysicalRecordSet(
         void );

int   CloseSemaphore(
         long __semaphoreHandle );

int   ExamineSemaphore(
         long __semaphoreHandle,
         int * __semaphoreValue,
         WORD * __openCount );

int   LockFileSet(
         WORD __timeoutLimit );

int   LockLogicalRecordSet(
         WORD __timeoutLimit );

int   LockPhysicalRecordSet(
         BYTE __lockDirective,
         WORD __timeoutLimit );

int   LogFile(
         char * __fileName,
         BYTE __lockDirective,
         WORD __timeoutLimit );

int   LogLogicalRecord(
         char * __logicalRecordName,
         BYTE __lockDirective,
         WORD __timeoutLimit );

int   LogPhysicalRecord(
         int __fileHandle,
         long __recordStartOffset,
         long __recordLength,
         BYTE __lockDirective,
         WORD __timeoutLimit );

int   OpenSemaphore(
         char * __semaphoreName,
         int __initialValue,
         long * __semaphoreHandle,
         WORD * __openCount );

int   ReleaseFile(
         char * __fileName );

void  ReleaseFileSet(
         void );

int   ReleaseLogicalRecord(
         char * __logicalRecordName );

void  ReleaseLogicalRecordSet(
         void );

int   ReleasePhysicalRecord(
         int __fileHandle,
         long __recordStartOffset,
         long __recordLength );

void  ReleasePhysicalRecordSet(
         void );

int   SignalSemaphore(
         long __semaphoreHandle );

int   WaitOnSemaphore(
         long __semaphoreHandle,
         WORD __timeoutLimit );

#define _NWSYNC_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWSYNC_H_INCLUDED  */
