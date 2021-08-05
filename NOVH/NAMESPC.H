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

#ifndef _NAMESPC_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define MAX_NAMESPACES 6


typedef struct NWNSINFO
{
   LONG nsInfoBitMask;
   LONG fixedBitMask;
   LONG reservedBitMask;
   LONG extendedBitMask;
   WORD fixedBitsDefined;
   WORD reservedBitsDefined;
   WORD extendedBitsDefined;
   LONG fieldsLenTable[32];
   BYTE hugeStateInfo[16];
   LONG hugeDataLength;
} NW_NS_INFO;


int NWGetHugeNSInfo(BYTE volNum,
                BYTE nameSpace,
                LONG dirBase,
                LONG hugeInfoMask,
                BYTE *hugeStateInfo,
                BYTE *hugeData,
                LONG *hugeDataLen,
                BYTE *nextHugeStateInfo);

int NWGetNameSpaceEntryName(BYTE *path,
               LONG  nameSpace,
               LONG  maxNameBufferLength,
               BYTE  *nameSpaceEntryName);

int NWGetNSInfo(BYTE volNum,
                BYTE srcNameSpace,
                BYTE dstNameSpace,
                LONG dirBase,
                LONG nsInfoMask,
                BYTE *nsSpecificInfo);

int NWGetNSLoadedList(BYTE volNum,
                      WORD loadListSize,
                      BYTE *NSLoadedList,
                      WORD *returnListSize);

int NWQueryNSInfoFormat(BYTE       nameSpace,
                        BYTE       volNum,
                        NW_NS_INFO *nsInfo);

int NWSetHugeNSInfo(BYTE volNum,
                BYTE nameSpace,
                LONG dirBase,
                LONG hugeInfoMask,
                BYTE *hugeStateInfo,
                LONG hugeDataLen,
                BYTE *hugeData,
                BYTE *nextHugeStateInfo,
                LONG *hugeDataUsed);

int NWSetNameSpaceEntryName(BYTE *path,
               LONG  nameSpace,
               BYTE  *nameSpaceEntryName);

int NWSetNSInfo(BYTE volNum,
                BYTE srcNameSpace,
                BYTE dstNameSpace,
                LONG dirBase,
                LONG nsInfoMask,
                LONG nsSpecificInfoLen,
                BYTE *nsSpecificInfo);

#define _NAMESPC_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NAMESPC_H_INCLUDED  */
