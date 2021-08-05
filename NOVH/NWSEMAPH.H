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

#ifndef _SEMAPHORE_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

int   CloseLocalSemaphore(
         LONG __semaphoreHandle );

int   ExamineLocalSemaphore(
         LONG __semaphoreHandle );

LONG  OpenLocalSemaphore(
         long __initialValue );

int   SignalLocalSemaphore(
         LONG __semaphoreHandle );

int   TimedWaitOnLocalSemaphore(
         LONG __semaphoreHandle,
         LONG __timeOut );

int   WaitOnLocalSemaphore(
         LONG __semaphoreHandle );

#define _SEMAPHORE_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _SEMAPHORE_H_INCLUDED  */
