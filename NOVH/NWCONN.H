#ifndef _CONNSERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
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
#include <nwtypes.h>

/*----------------------------------------------------
    Structures and typedefs for connection services
 ---------------------------------------------------*/
#define zNT_IPX            0      // 'NT_IPX' is often defined by others...
#define IPX_ADDRESS_LEN   12

struct UserNameStruct
{
   BYTE   UserName[48];
   LONG   ObjectID;
};

int   AttachByAddress
(
   BYTE   transType, 
   LONG   transLen,
   BYTE   *transBuf, 
   WORD   *fileServerID
);

int   AttachToFileServer
(
   char   *__fileServerName,
   WORD   *fileServerID 
);

int   GetConnectionInformation
(
   WORD   __connectionNumber,
   char   *__objectName,
   WORD   *__objectType,
   long   *__objectID,
   BYTE   *__loginTime 
);

int   GetConnectionList
(
   LONG   objectID, 
   LONG   lastConnection, 
   LONG   *numberOfConnections,
   LONG   *connectionList,
   LONG   connectionSize
);

WORD  GetConnectionNumber
(
   void 
);

int   GetFileServerID
(
   const char   *__fileServerName,
   WORD         *__connectionID 
);

int   GetDefaultConnectionID
( 
   void 
);

int   GetDefaultFileServerID
( 
   void 
);

int   GetInternetAddress
(
   WORD   __connectionNumber,
   char   *__networkNumber,
   char   *__physicalNodeAddress 
);

int   GetLANAddress
(
   LONG   __boardNumber,
   BYTE   *__nodeAddress 
);

int   GetMaximumNumberOfStations
(
   void 
);

int   GetObjectConnectionNumbers
(
   char   *__objectName,
   WORD   __objectType,
   WORD   * __numberOfConnections,
   WORD   * __connectionList,
   WORD   __maxConnections
);

void  GetStationAddress
(
   BYTE   *__physicalNodeAddress 
);

int   GetUserNameFromNetAddress
(
   BYTE   *__internetAddress,
   int  __sequenceNumber,
   struct UserNameStruct *__userNameP
);

int   LoginToFileServer
(
   char   *__objectName,
   WORD   __objectType,
   char   *__objectPassword 
);

void  Logout
(
   void 
);

void  LogoutFromFileServer
(
   WORD   __connectionID 
);

int   NWDSGetCurrentUser
(
   void
);

int   NWDSSetCurrentUser
(
   int   userHandle
);

int   NWDSGetNearestDirectoryService
(
   int   *connectionHandle
);

int    NWDSGetPreferredDSServer
(
   int   *serverHandle
);

int    NWDSSetPreferredDSTree
(
   int   length,
   char   *treeName
);

int   NWNCPSend
(
   BYTE   functionCode, 
   char   *sendPacket, 
   WORD   sendLen, 
   char   *replyBuf, 
   WORD   replyLen
);

int   SetConnectionCriticalErrorHandler
(
   int   (*func)(int fileServerID, int connection, int err)
);

#define _CONNSERV_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _CONNSERV_H_INCLUDED  */
