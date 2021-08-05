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

#ifndef _NWMSG_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define MAX_MESSAGE_LENGTH 58
#define MAX_CONSOLE_MESSAGE_LENGTH 80

int   BroadcastToConsole(
         char *__message );

int   DisableStationBroadcasts(
         void );

int   EnableStationBroadcasts(
         void );

int   GetBroadcastMessage(
         char *__messageBuffer );

int   SendBroadcastMessage(
         char *__message,
         WORD *__connectionList,
         BYTE *__resultList,
         WORD __connectionCount );

#define _NWMSG_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWMSG_H_INCLUDED  */
