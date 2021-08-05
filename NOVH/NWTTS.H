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

#ifndef _TTSSERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

int   TTSAbortTransaction(
         void );
int   TTSBeginTransaction(
         void );
int   TTSEndTransaction(
         long *__transactionNumber );

int   TTSGetApplicationThresholds(
         BYTE *__logicalRecordLockThreshold,
         BYTE *__physicalRecordLockThreshold );

int   TTSGetWorkstationThresholds(
         BYTE *__logicalRecordLockThreshold,
         BYTE *__physicalRecordLockThreshold );

int   TTSIsAvailable(
         void );

int   TTSSetApplicationThresholds(
         BYTE __logicalRecordLockThreshold,
         BYTE __physicalRecordLockThreshold );

int   TTSSetWorkstationThresholds(
         BYTE __logicalRecordLockThreshold,
         BYTE __physicalRecordLockThreshold );

int   TTSTransactionStatus(
         long __transactionNumber );


#define _TTSSERV_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _TTSSERV_H_INCLUDED  */
