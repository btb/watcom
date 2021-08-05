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

#ifndef _FILESERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>
#include <direct.h>


int   FileServerFileCopy(
         int __sourceFileHandle,
         int __destinationFileHandle,
         LONG __sourceFileOffset,
         LONG __destinationFileOffset,
         LONG __numberOfBytesToCopy,
         LONG *__numberOfBytesCopied );

int   GetExtendedFileAttributes(
         char *__pathName,
         BYTE *__extendedFileAttributes);

int   PurgeErasedFile(
         char *__pathName,
         long __sequenceNumber);

int   SalvageErasedFile(
         char *__pathName,
         long __sequenceNumber,
         char *__newFileName );

int   ScanErasedFiles(
         char *__pathName,
         long *__nextEntryNumber,
         DIR *__deletedFileInfo );

int   SetExtendedFileAttributes(
         char *__pathName,
         BYTE __extendedFileAttributes);

int   SetFileInfo(
         char *__pathName,
         BYTE __searchAttributes,
         LONG __fileAttributes,
         char *__creationDate,
         char *__lastAccessDate,
         char *__lastUpdateDateAndTime,
         char *__lastArchiveDateAndTime,
         LONG __fileOwnerID);

#define _FILESERV_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _FILESERV_H_INCLUDED  */
