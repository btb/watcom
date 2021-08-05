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

#ifndef _AFPSERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#pragma pack(1);
typedef struct
   {
   long entryID;
   long parentID;
   WORD attributes;
   long dataForkLength;
   long resourceForkLength;
   WORD numOffspring;
   WORD creationDate;
   WORD accessDate;
   WORD modifyDate;
   WORD modifyTime;
   WORD backupDate;
   WORD backupTime;
   BYTE finderInfo[32];
   char longName[33];
   char pad1;
   long ownerID;
   char shortName[13];
   char pad2;
   WORD accessPrivileges;
   BYTE proDosInfo[6];
   } AFPFILEINFO;

typedef struct
   {
   WORD attributes;
   WORD creationDate;
   WORD accessDate;
   WORD modifyDate;
   WORD modifyTime;
   WORD backupDate;
   WORD backupTime;
   BYTE finderInfo[32];
   BYTE proDosInfo[6];
   } AFPSETINFO;

int   AFPAllocTemporaryDirHandle(
           WORD __connectionID,
           BYTE __volumeNum,
           long __AFPEntryID,
           char *__AFPPathString,
           BYTE *__NetWareDirectoryHandle,
           BYTE *__AccessRights );

int   AFPCreateDirectory(
           WORD __connectionID,
           BYTE __volumeNum,
           long __AFPEntryID,
           BYTE *__finderInfo,
           char *__AFPPathString,
           long *__newAFPEntryID );

int   AFPCreateFile(
           WORD __connectionID,
           BYTE __volumeNum,
           long __AFPEntryID,
           BYTE __deleteExistingFile,
           BYTE *__finderInfo,
           char *__AFPPathString,
           long *__newAFPEntryID );

int   AFPDelete(
           WORD __connectionID,
           BYTE __volumeNum,
           long __AFPEntryID,
           char *AFPPathString );

int   AFPDirectoryEntry(
           WORD __connectionID,
           BYTE __directoryHandle,
           char *__pathName );

int   AFPGetEntryIDFromName(
           WORD __connectionID,
           BYTE __volumeNum,
           long __AFPEntryID,
           char *__AFPPathString,
           long *__newAFPEntryID );

int   AFPGetEntryIDFromNetWareHandle(
           WORD __connectionID,
           BYTE *__NetWareHandle,
           BYTE *__volumeID,
           long *__AFPEntryID,
           BYTE *__forkIndicator );

int   AFPGetEntryIDFromPathName(
           WORD __connectionID,
           BYTE __directoryHandle,
           char *__pathName,
           long *__AFPEntryID );

int   AFPGetFileInformation(
           WORD __connectionID,
           BYTE __volumeNum,
           long __AFPEntryID,
           WORD __requestBitMap,
           char *__AFPPathString,
           WORD __strucSize,
           AFPFILEINFO *__AFPFileInfo );

#ifndef _AFPSERV_PROTOTYPES
int   AFPOpenFileFork(
          WORD __connectionID,
          BYTE __volumeNum,
          long __AFPEntryID,
          BYTE __forkIndicator,
          BYTE __accessMode,
          char *__AFPPathString,
          long *__fileID,
          long *__forkLength,
          BYTE *__NetWareHandle,
          int *__fileHandle );
#endif

int   AFPRename(
          WORD __connectionID,
          BYTE __volumeNum,
          long __AFPSourceEntryID,
          long __AFPDestEntryID,
          char *__AFPSourcePath,
          char *__AFPDestPath );

int   AFPScanFileInformation(
          WORD __connectionID,
          BYTE __volumeNum,
          long __AFPEntryID,
          long *__AFPLastSeenID,
          WORD __searchBitMap,
          WORD __requestBitMap,
          char *__AFPPathString,
          WORD __strucSize,
          AFPFILEINFO *__AFPScanFileInfo );

int   AFPSetFileInformation(
          WORD __connectionID,
          BYTE __volumeNum,
          long __AFPEntryID,
          WORD __requestBitMap,
          char *__AFPPathString,
          WORD __strucSize,
          AFPSETINFO *__AFPSetInfo );

int   AFPSupported(
          WORD __connectionID );

#define _AFPSERV_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _AFPSERV_H_INCLUDED  */
