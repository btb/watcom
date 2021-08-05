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

#ifndef _DFS_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/****************************************************************************
*
*  DFS Defines
*
****************************************************************************/

#define LONG unsigned long
#define WORD unsigned short
#define BYTE unsigned char
#define NULL 0

#define TRUE   1
#define FALSE  0

/* completion codes */

#define DFSFailedCompletion            -1
#define DFSNormalCompletion            0
#define DFSInsufficientSpace           1
#define DFSVolumeSegmentDeactivated    4   
#define DFSTruncationFailure           16
#define DFSHoleInFileError             17
#define DFSParameterError              18
#define DFSOverlapError                19
#define DFSSegmentError                20
#define DFSBoundryError                21
#define DFSInsufficientLimboFileSpace  22
#define DFSNotInDirectFileMode         23
#define DFSOperationBeyondEndOfFile    24
#define DFSOutOfHandles                129
#define DFSHardIOError                 131
#define DFSInvalidFileHandle           136
#define DFSNoReadPrivilege             147
#define DFSNoWritePrivilege            148
#define DFSFileDetached                149
#define DFSInsufficientMemory          150
#define DFSInvalidVolume               152
#define DFSIOLockError                 162

/****************************************************************************
*
*  DFS Structures
*
****************************************************************************/

struct FileMapStructure
{
   LONG fileBlock;
   LONG volumeBlock;
   LONG numberOfBlocks;
};

struct VolumeInformationStructure
{
   LONG VolumeAllocationUnitSizeInBytes;
   LONG VolumeSizeInAllocationUnits;
   LONG VolumeSectorSize;
   LONG AllocationUnitsUsed;
   LONG AllocationUnitsFreelyAvailable;
   LONG AllocationUnitsInDeletedFilesNotAvailable;
   LONG AllocationUnitsInAvailableDeletedFiles;
   LONG NumberOfPhysicalSegmentsInVolume;
   LONG PhysicalSegmentSizeInAllocationUnits[64];
};

struct DFSCallBackParameters
{
   LONG localSemaphoreHandle;
   LONG completionCode;
};

/****************************************************************************
*             
*  DFS CLIB Prototypes
*
****************************************************************************/

extern LONG DFSclose(
      LONG fileHandle);

extern LONG DFScreat (
      BYTE *fileName,
      LONG permission,
      LONG flagBits);

extern LONG DFSExpandFile(
      LONG fileHandle,
      LONG fileBlockNumber,
      LONG numberOfBlocks,
      LONG volumeBlockNumber,
      LONG segmentNumber);

extern LONG DFSFreeLimboVolumeSpace(
      LONG volumeNumber,
      LONG numberOfBlocks);

extern LONG DFSsopen(
      BYTE *fileName,
      LONG access,
      LONG share,
      LONG permission,
      LONG flagBits,
      LONG dataStream);

extern LONG DFSRead(
      LONG fileHandle,
      LONG startingSector,
      LONG sectorCount,
      BYTE *buffer);

extern LONG DFSReadNoWait(
      LONG fileHandle,
      LONG startingSector,
      LONG sectorCount,
      BYTE *buffer,
      struct DFSCallBackParameters *callBackNode);

extern LONG DFSReturnFileMappingInformation(
      LONG fileHandle,
      LONG startingBlockNumber,
      LONG *numberOfEntries,
      LONG tableSize,
      struct FileMapStructure *table);

extern LONG DFSReturnVolumeBlockInformation(
      LONG volumeNumber,
      LONG startingBlockNumber,
      LONG numberOfBlocks,
      BYTE *buffer);

extern LONG DFSReturnVolumeMappingInformation(
      LONG volumeNumber,
      struct VolumeInformationStructure *volumeInformation);

extern LONG DFSWrite(
      LONG fileHandle,
      LONG startingSector,
      LONG sectorCount,
      BYTE *buffer);

extern LONG DFSWriteNoWait(
      LONG fileHandle,
      LONG startingSector,
      LONG sectorCount,
      BYTE *buffer,
      struct DFSCallBackParameters *callBackNode);

extern LONG DFSSetEndOfFile(
      LONG handle,
      LONG newFileSize,
      LONG returnTruncatedBlocksFlag);


#define _DFS_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif /* _DFS_H_INCLUDED  */
