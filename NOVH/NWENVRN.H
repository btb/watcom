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

#ifndef _ENVSERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define DOSNameSpace       0
#define MACNameSpace       1

#define RSUPER             0x03

#pragma pack (1);
typedef struct
 {
    char    serverName[48];
    BYTE    netwareVersion;
    BYTE    netwareSubVersion;
    WORD    maxConnectionsSupported;
    WORD    connectionsInUse;
    WORD    maxVolumesSupported;
    BYTE    revisionLevel;
    BYTE    SFTLevel;
    BYTE    TTSLevel;
    WORD    peakConnectionsUsed;
    BYTE    accountingVersion;
    BYTE    VAPversion;
    BYTE    queingVersion;
    BYTE    printServerVersion;
    BYTE    virtualConsoleVersion;
    BYTE    securityRestrictionLevel;
    BYTE    internetBridgeSupport;
    BYTE    reserved[60];
    BYTE    CLibMajorVersion;
    BYTE    CLibMinorVersion;
    BYTE    CLibRevision;
  }FILE_SERV_INFO;


int   CheckConsolePrivileges( 
         void );

int   CheckNetWareVersion( 
         WORD __majorVersion,  
         WORD __minorVersion,
         WORD __revisionNumber,  
         WORD __minimumSFTLevel,
         WORD __minimumTTSLevel );

int   ClearConnectionNumber( 
         WORD __connectionNumber );

int   DisableFileServerLogin( 
         void );

int   DisableTransactionTracking( 
         void );

int   DownFileServer( 
         int __forceFlag );

int   EnableFileServerLogin( 
         void );

int   EnableTransactionTracking( 
         void );

int   GetBinderyObjectDiskSpaceLeft( 
         WORD  __connectionID,
         long  __binderyObjectID,
         long *__systemElapsedTime,
         long *__unusedDiskBlocks,
         BYTE *__restrictionEnforced );

int   GetDiskUtilization( 
         long  __objectID, 
         char  __volumeNumber,
         LONG *__usedDirectories, 
         LONG *__usedFiles,
         LONG *__usedBlocks );

void  GetFileServerConnectionID( 
         char *__fileServerName,
         WORD *__connectionID );

void  GetFileServerDateAndTime( 
         BYTE *__dateAndTime );

int   GetFileServerDescriptionStrings( 
         char *__company_Name, 
         char *__revision,
         char *__revisionDate,
         char *__copyrightNotice );

int   GetFileServerLoginStatus( 
         int *__loginEnabledFlag );

void  GetFileServerName( 
         WORD  __connectionID, 
         char *__fileServerName );

int   GetServerInformation( 
         int             __returnSize, 
         FILE_SERV_INFO *__serverInfo );

int   SendConsoleBroadcast( 
         char  *__message, 
         WORD   __connectionCount,
         WORD  *__connectionList );

BYTE  SetCurrentNameSpace( 
         BYTE __newNameSpace );

int   SetFileServerDateAndTime( 
         WORD __year, 
         WORD __month, 
         WORD __day,
         WORD __hour, 
         WORD __minute, 
         WORD __second );

#define _ENVSERV_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _ENVSERV_H_INCLUDED  */
