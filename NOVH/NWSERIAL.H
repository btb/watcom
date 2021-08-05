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

#ifndef _SERIAL_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

int   GetNetworkSerialNumber(
         LONG *__networkSerialNumber,
         WORD *__applicationNumber );

int   VerifyNetworkSerialNumber(
         LONG __networkSerialNumber,
         WORD *__applicationNumber );

#define _SERIAL_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _SERIAL_H_INCLUDED  */
