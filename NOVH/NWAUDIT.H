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

#ifndef _AUDIT_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>


/*...defined network address types...*/
#define ASCIIZ_STRING_NET_ADDRESS_TYPE   0x00
#define ETHERNET_NET_ADDRESS_TYPE        0x02
#define NO_IDENTITY_HAS_BEEN_SET         0xFF


int NWAddRecordToAuditingFile(
         LONG  volumeNumber,
         LONG  recordType,
         LONG  stationNumber,
         LONG  statusCode,
         BYTE  *data,
         LONG  dataSize);

int NWGetAuditingIdentity(
         LONG  *addressType,
         BYTE  *networkAddress,
         char  *identityName);

int NWSetAuditingIdentity(
         LONG  addressType,
         BYTE  *networkAddress,
         char  *identityName);

#define _AUDIT_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _AUDIT_H_INCLUDED  */
