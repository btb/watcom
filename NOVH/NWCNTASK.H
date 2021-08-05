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

#ifndef _CONNTASK_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
                                                              
#include <nwtypes.h>

#define LOGIN_WITHOUT_PASSWORD ((char *)TRUE)

LONG  AllocateBlockOfTasks(
         LONG __numberWanted );

BYTE  CheckIfConnectionActive(
         LONG __connection );

int   DisableConnection(
         LONG __connection);

int   EnableConnection(
         LONG __connection);

LONG  GetCurrentConnection(
         void);

WORD  GetCurrentFileServerID(
         void );

LONG  GetCurrentTask(
         void);

int   LoginObject(
         LONG __connection,
         char *__objectName,
         WORD __objectType,
         char *__password );

int   LogoutObject(
         LONG connection );

int   ReturnBlockOfTasks(
         LONG __startingTask,
         LONG __numberOfTasks);

int   ReturnConnection(
         LONG connection );

LONG  SetCurrentConnection(
         LONG __connectionNumber);

WORD  SetCurrentFileServerID(
         WORD __connectionID );

LONG  SetCurrentTask(
         LONG __taskNumber);

#define _CONNTASK_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _CONNTASK_H_INCLUDED  */
