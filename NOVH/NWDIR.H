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

#ifndef _NWDIR_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <direct.h>
#include <nwtypes.h>

/* Trustee Access Rights in a network directory */

#ifndef TA_NONE
   #define TA_NONE             0x0000
   #define TA_READ             0x0001
   #define TA_WRITE            0x0002
   #define TA_CREATE           0x0008
   #define TA_DELETE           0x0010
   #define TA_ACCESSCONTROL    0x0020
   #define TA_SEEFILES         0x0040
   #define TA_MODIFY           0x0080
   #define TA_SUPERVISOR       0x0100
   #define TA_ALL              0x01FB
   /* Old names for rights */
   #define TA_OPEN             0x0004
   #define TA_OWNERSHIP        0x0020
   #define TA_SEARCH           0x0040
#endif

#pragma pack(1);
struct AnswerStructure
   {
   BYTE ALevelNumber;
   LONG AMaximumAmount;
   LONG ACurrentAmount;
   };

#define  BYTES_PER_SECTOR  512

typedef struct    // copied from page Glossary-19 of 286 NetWare C Interface
   {
   long    systemElapsedTime;
   BYTE    volumeNumber;
   BYTE    logicalDriveNumber;
   WORD    sectorsPerBlock;
   long    startingBlock;
   WORD    totalBlocks;
   WORD    availableBlocks;
   WORD    totalDirectorySlots;
   WORD    availableDirectorySlots;
   WORD    maxDirectorySlotsUsed;
   BYTE    isHashing;
   BYTE    isRemovable;
   BYTE    isMounted;
   char    volumeName[17];
   LONG    purgableBlocks;
   LONG    notYetPurgableBlocks;
   } VOLUME_STATS;

typedef struct    // copied from page Glossary-19 of 286 NetWare C Interface
   {
   long    systemElapsedTime;
   BYTE    volumeNumber;
   BYTE    logicalDriveNumber;
   WORD    sectorsPerBlock;
   short   startingBlock;
   LONG    totalBlocks;
   LONG    availableBlocks;
   LONG    totalDirectorySlots;
   LONG    availableDirectorySlots;
   BYTE    isHashing;
   BYTE    isRemovable;
   BYTE    isMounted;
   char    volumeName[17];
   LONG    purgableBlocks;
   LONG    notYetPurgableBlocks;
   } VOLUME_INFO;


/*    define volume types   // cribbed from NWCALLS 7/7/92 */

#define VINetWare386    0
#define VINetWare286    1
#define VINetWare386v30 2
#define VINetWare386v31 3

/*    define the extended volume information status flag bits  */

#define NWSubAllocEnabledBit    0x01
#define NWCompressionEnabledBit 0x02
#define NWMigrationEnabledBit   0x04
#define NWAuditingEnabledBit    0x08
#define NWReadOnlyEnabledBit    0x10

typedef struct ExtendedVolInfo_tag // cribbed from NWCALLS 7/7/92
{
   LONG volType;
   LONG statusFlag;
   LONG sectorSize;
   LONG sectorsPerCluster;
   LONG volSizeInClusters;
   LONG freeClusters;
   LONG subAllocFreeableClusters;
   LONG freeableLimboSectors;
   LONG nonfreeableLimboSectors;
   LONG availSubAllocSectors;
   LONG nonuseableSubAllocSectors;
   LONG subAllocClusters;
   LONG numDataStreams;
   LONG numLimboDataStreams;
   LONG oldestDelFileAgeInTicks;
   LONG numCompressedDataStreams;
   LONG numCompressedLimboDataStreams;
   LONG numNoncompressibleDataStreams;
   LONG precompressedSectors;
   LONG compressedSectors;
   LONG numMigratedDataStreams;
   LONG migratedSectors;
   LONG clustersUsedByFAT;
   LONG clustersUsedByDirs;
   LONG clustersUsedByExtDirs;
   LONG totalDirEntries;
   LONG unusedDirEntries;
   LONG totalExtDirExtants;
   LONG unusedExtDirExtants;
   LONG extAttrsDefined;
   LONG extAttrExtantsUsed;
   LONG directoryServicesObjectID;
   LONG lastModifiedDateAndTime;
} NWVolExtendedInfo;


struct    ModifyStructure
{
    BYTE *MModifyName;
    LONG MFileAttributes;
    LONG MFileAttributesMask;
    WORD MCreateDate;
    WORD MCreateTime;
    LONG MOwnerID;
    WORD MLastArchivedDate;
    WORD MLastArchivedTime;
    LONG MLastArchivedID;
    WORD MLastUpdatedDate;    /* also last modified date and time. */
    WORD MLastUpdatedTime;
    LONG MLastUpdatedID;
    WORD MLastAccessedDate;
    WORD MInheritanceGrantMask;
    WORD MInheritanceRevokeMask;
    int MMaximumSpace;
	 LONG MLastUpdatedInSeconds;
};

#define    MModifyNameBit                   0x1
#define    MFileAttributesBit               0x2
#define    MCreateDateBit                   0x4
#define    MCreateTimeBit                   0x8
#define    MOwnerIDBit                      0x10
#define    MLastArchivedDateBit             0x20
#define    MLastArchivedTimeBit             0x40
#define    MLastArchivedIDBit               0x80
#define    MLastUpdatedDateBit              0x100
#define    MLastUpdatedTimeBit              0x200
#define    MLastUpdatedIDBit                0x400
#define    MLastAccessedDateBit             0x800
#define    MInheritanceRestrictionMaskBit   0x1000
#define    MMaximumSpaceBit                 0x2000
#define    MLastUpdatedInSecondsBit         0x4000

int   AddSpaceRestrictionForDirectory(
         char *__pathName,
         int __value,
         LONG __allowWildCardsFlag );

int   AddTrustee(
         char *__pathName,
         LONG __trusteeID,
         WORD __newRights );

int   AddUserSpaceRestriction(
         int __volume,
         LONG __trusteeID,
         LONG __value );

int   ChangeDirectoryEntry(
         char                   *__pathName,
         struct ModifyStructure *__modifyVector,
         LONG                   __modifyBits,
         LONG                   __allowWildCardsFlag );

int   DeleteTrustee(
         char *__pathName,
         LONG __trusteeID );

int   DeleteUserSpaceRestriction(
         int  __volume,
         LONG __trusteeID );

int   GetAvailableUserDiskSpace(
         char *__pathName,
         LONG *__availableSpace );

int   GetDiskSpaceUsedByObject(
         long __trusteeID,
         int  __volume,
         LONG *__usedSpace );

int   GetEffectiveRights(
         char *__pathName,
         WORD *__accessRights );

int   GetMaximumUserSpaceRestriction(
         long __trusteeID,
         int  __volume,
         LONG *__maxRestriction );

LONG  GetNumberOfVolumes(
         void );

int   GetVolumeInformation(
         WORD         __connectionID,
         BYTE         __volumeNumber,
         int          __structSize,
         VOLUME_STATS *__volumeStatistics);

int   GetVolumeInfoWithNumber(
         BYTE volumeNumber,
         char *volumeName,
         WORD *totalBlocks,
         WORD *sectorsPerBlock,
         WORD *availableBlocks,
         WORD *totalDirectorySlots,
         WORD *availableDirectorySlots, 
         WORD *volumeIsRemovable );

int   GetVolumeName(
         int  __volumeNumber,
         char *__volumeName );

int   GetVolumeNumber(
         char *__volumeName, 
         int  *__volumeNumber );

int   GetVolumeStatistics(
         WORD        __connectionID,
         BYTE        __volumeNumber,
         int         __structSize,
         VOLUME_INFO *__volumeStatistics);

int   ModifyInheritedRightsMask(
         char *path,
         WORD revokeRightsMask, 
         WORD grantRightsMask );

int   NWGetExtendedVolumeInfo(
         int volNumber,
         char *volName,
         NWVolExtendedInfo *volInfo);

int   PurgeTrusteeFromVolume(
         int __volume, 
         LONG __trusteeID );

int   ReturnSpaceRestrictionForDirectory(
         char *__pathName,
         LONG __numberOfStructuresToReturn,
         BYTE *__answerBuffer,
         LONG *__numberOfStructuresReturned);

int   ScanBinderyObjectTrusteePaths(
         LONG  __objectID,
         BYTE  __volumeNumber,
         int   *__sequenceNumber,
         WORD *__trusteeAccessMask,
         char *__trusteePathName );

int   ScanTrustees(
         char *__pathName,
         LONG __startingOffset,
         LONG __vectorSize,
         LONG *__trusteeVector,
         WORD *__maskVector,
         LONG *__actualVectorSize );

int   ScanUserSpaceRestrictions(
         int  __volume,
         LONG *__sequenceNumber,
         LONG __numberOfTrusteesToReturn, 
         LONG *__answerArea, 
         LONG *__numberOfTrusteesReturned );

int   SetDirectoryInfo(
         char *__pathName,
         BYTE *__newCreationDateAndTime,
         LONG __newOwnerObjectID,
         WORD __inheritedRightsMask );

int   UpdateDirectoryEntry(
         int __handle );

#define _NWDIR_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWDIR_H_INCLUDED  */
