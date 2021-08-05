/*************************************************************************
*
* (C) Copyright Novell, Inc. 1992 All Rights Reserved.
*
*
* No part of this file may be duplicated, revised, translated,
* localized or modified in any manner or compiled, linked or 
* uploaded or downloaded to or from any computer system without
* the prior written consent of Novell, Inc.
*
* NetWare C NLM Runtime Library source code
*
*************************************************************************/

#ifndef  _SERVSTAT_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/************************************************************************/

#define SS_DEFAULT_BUFFER_SIZE 538

/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
/*      User Interface Structures        */
/* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/

typedef struct SSDefaultBuffer
{
   BYTE  data[SS_DEFAULT_BUFFER_SIZE];
}SSDefaultBuffer;

/************************************************************************/

typedef struct CacheMemoryCounters
{
   LONG OriginalNumberOfCacheBuffers;
   LONG CurrentNumberOfCacheBuffers;
   LONG CacheDirtyBlockThreshold;
   LONG debugCounters[7];
}CacheMemoryCounters;

typedef struct CacheTrendCounters
{
   LONG NumOfCacheChecks;
   LONG NumOfCacheHits;
   LONG debugCounters[7];
   LONG LRUSittingTime;
}CacheTrendCounters;

typedef struct CacheInformation
{
   LONG MaximumByteCount;
   LONG MinimumNumberOfCacheBuffers;
   LONG MinimumCacheReportThreshold;
   LONG AllocateWaitingCount;
   LONG NDirtyBlocks;
   LONG CacheDirtyWaitTime;
   LONG CacheMaximumConcurrentWrites;
   LONG MaximumDirtyTime;
   LONG NumberOfDirectoryCacheBuffers;
   LONG CacheByteToBlockShiftFactor;
}CacheInformation;

typedef  struct GetCacheInfoStructure
{
   LONG  currentServerTime;
   BYTE  VConsoleVersion;
   BYTE  VConsoleRevision;
   WORD  reserved;
   LONG  CacheCntrs[26];
   CacheMemoryCounters  MemoryCntrs;
   CacheTrendCounters   TrendCntrs;
   CacheInformation     CacheInfo;
}GetCacheInfoStructure;

/************************************************************************/

typedef struct ServerInformation
{
   LONG ReplyCanceledCount;
   LONG WriteHeldOffCount;
   LONG reserved1;
   LONG InvalidRequestTypeCount;
   LONG BeingAbortedCount;
   LONG AlreadyDoingReAllocateCount;
   LONG reserved2[3];
   LONG DeAllocateStillTransmittingCount;
   LONG StartStationErrorCount;
   LONG InvalidSlotCount;
   LONG BeingProcessedCount;
   LONG ForgedPacketCount;
   LONG StillTransmittingCount;
   LONG ReExecuteRequestCount;
   LONG InvalidSequenceNumberCount;
   LONG DuplicateIsBeingSentAlreadyCount;
   LONG SentPositiveAcknowledgeCount;
   LONG SentADuplicateReplyCount;
   LONG NoMemoryForStationControlCount;
   LONG NoAvailableConnectionsCount;
   LONG ReAllocateSlotCount;
   LONG ReAllocateSlotCameTooSoonCount;
}ServerInformation;

typedef struct FSCounters
{
   WORD  TooManyHops;
   WORD  UnknownNetwork;
   WORD  NoSpaceForService;
   WORD  NoRecieveBuffers;
   WORD  NotMyNetwork;
   LONG  NetBIOSProgatedCount;
   LONG  TotalPacketsServiced;
   LONG  TotalPacketsRouted;
}FSCounters;

typedef struct GetFileServerInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  NCPStaInUseCnt;
   LONG  NCPPeakStaInUse;
   LONG  numOfNCPReqs;
   LONG  serverUtilization;
   ServerInformation serverInfo;
   FSCounters  fileServerCounters;
}GetFileServerInfoStructure;

/************************************************************************/

typedef struct GetFileSystemInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  debugCounters[13];
}GetFileSystemInfoStructure;

/************************************************************************/

typedef struct UserInformation
{
   LONG  connectionNumber;
   LONG  useCount;
   BYTE  connectionServiceType;
   BYTE  loginTime[7];
   LONG  status;
   LONG  expirationTime;
   LONG  objectType;
   BYTE  transactionFlag;
   BYTE  logicalLockThreshold;
   BYTE  recordLockThreshold;
   BYTE  fileWriteFlags;   /* Includes active and stop bits */
   BYTE  fileWriteState;
   BYTE  filler;
   WORD fileLockCount;
   WORD recordLockCount;
   BYTE totalBytesRead[6];
   BYTE totalBytesWritten[6];
   LONG totalRequests;
   LONG heldRequests;
   BYTE heldBytesRead[6];
   BYTE heldBytesWritten[6];
}UserInformation;

typedef struct GetUserInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   UserInformation   userInfo;
   BYTE  userNameLen;
   BYTE  username;  /* 1st byte - more follows*/
}GetUserInfoStructure;

/************************************************************************/

typedef struct PacketBurstInformation
{
   LONG  BigInvalidSlotCount;
   LONG  BigForgedPacketCount;
   LONG  BigInvalidPacketCount;
   LONG  BigStillTransmittingCount;
   LONG  StillDoingTheLastRequestCount;
   LONG  InvalidControlRequestCount;
   LONG  ControlInvalidMessageNumberCount;
   LONG  ControlBeingTornDownCount;
   LONG  BigRepeatTheFileReadCount;
   LONG  BigSendExtraCCCount;
   LONG  BigReturnAbortMessageCount;
   LONG  BigReadInvalidMessageNumberCount;
   LONG  BigReadDoItOverCount;
   LONG  BigReadBeingTornDownCount;
   LONG  PreviousControlPacketCount;
   LONG  SendHoldOffMessageCount;
   LONG  BigReadNoDataAvailableCount;
   LONG  BigReadTryingToReadTooMuchCount;
   LONG  ASyncReadErrorCount;
   LONG  BigReadPhysicalReadErrorCount;
   LONG  ControlBadACKFragmentListCount;
   LONG  ControlNoDataReadCount;
   LONG  WriteDuplicateRequestCount;
   LONG  ShouldntBeACKingHereCount;
   LONG  WriteInconsistentPacketLengthsCount;
   LONG  FirstPacketIsntAWriteCount;
   LONG  WriteTrashedDuplicateRequestCount;
   LONG  BigWriteInvalidMessageNumberCount;
   LONG  BigWriteBeingTornDownCount;
   LONG  BigWriteBeingAbortedCount;
   LONG  ZeroACKFragmentCountCount;
   LONG  WriteCurrentlyTransmittingCount;
   LONG  TryingToWriteTooMuchCount;
   LONG  WriteOutOfMemoryForControlNodesCount;
   LONG  WriteDidntNeedThisFragmentCount;
   LONG  WriteTooManyBuffersCheckedOutCount;
   LONG  WriteTimeOutCount;
   LONG  WriteGotAnACKCount;
   LONG  WriteGotAnACKCount1;
   LONG  PollerAbortedTheConnectionCount;
   LONG  MaybeHadOutOfOrderWritesCount;
   LONG  HadAnOutOfOrderWriteCount;
   LONG  MovedTheACKBitDownCount;
   LONG  BumpedOutOfOrderWriteCount;
   LONG  PollerRemovedOldOutOfOrderCount;
   LONG  WriteDidntNeedButRequestedACKCount;
   LONG  WriteTrashedPacketCount;
   LONG  TooManyACKFragmentsCount;
   LONG  SavedAnOutOfOrderPacketCount;
   LONG  ConnectionBeingAbortedCount;
}PacketBurstInformation;

typedef struct GetPacketBurstInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   PacketBurstInformation  packetBurstInfo;
}GetPacketBurstInfoStructure;

/************************************************************************/

typedef struct IPXInformation
{
   LONG IpxSendPacketCount;
   WORD IpxMalformPacketCount;
   LONG IpxGetECBRequestCount;
   LONG IpxGetECBFailCount;
   LONG IpxAESEventCount;
   WORD IpxPostponedAESCount;
   WORD IpxMaxConfiguredSocketCount;
   WORD IpxMaxOpenSocketCount;
   WORD IpxOpensocketFailCount;
   LONG IpxListenECBCount;
   WORD IpxECBCancelFailCount;
   WORD IpxGetLocalTargetFailCount;
}IPXInformation;

typedef struct SPXInformation
{
   WORD SpxMaxConnectionsCount;
   WORD SpxMaxUsedConnections;
   WORD SpxEstConnectionReq;
   WORD SpxEstConnectionFail;
   WORD SpxListenConnectReq;
   WORD SpxListenConnectFail;
   LONG SpxSendCount;
   LONG SpxWindowChokeCount;
   WORD SpxBadSendCount;
   WORD SpxSendFailCount;
   WORD SpxAbortedConnection;
   LONG SpxListenPacketCount;
   WORD SpxBadListenCount;
   LONG SpxIncomingPacketCount;
   WORD SpxBadInPacketCnt;
   WORD SpxSuppressedPackCnt;
   WORD SpxNoSesListenECBCnt;
   WORD SpxWatchDogDestSesCnt;
}SPXInformation;

typedef struct GetIPXSPXInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   IPXInformation IPXInfo;
   SPXInformation SPXInfo;
}GetIPXSPXInfoStructure;

/************************************************************************/

typedef struct GetGarbageCollInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  failedAllocReqCount;
   LONG  numberOfAllocs;
   LONG  noMoreMemAvlCnt;
   LONG  numOfGarbageColl;
   LONG  foundSomeMem;
   LONG  numOfChecks;
}GetGarbageCollInfoStruc;

typedef struct CPUInformation
{
   LONG  PageTableOwnerFlag;
   LONG  CPUType;
   LONG  CoProcessorFlag;
   LONG  BusType;
   LONG  IOEngineFlag;
   LONG  FSEngineFlag;
   LONG  NonDedFlag;
}CPUInformation;

typedef struct GetCPUInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  numberOfCPUs;
   CPUInformation CPUInfo;
   BYTE  variableStringsStart;  /* CPU String, NPX present string, Bus string*/
}GetCPUInfoStructure;

/************************************************************************/

/* ************************************ */
/* The LFSCountersStructure is provided */
/* so that you can see field names.  It */
/* isn't referenced and developers will */
/* probably want to define their own    */
/* structure.  This structure may grow  */
/* beyond what one call can return at   */
/* some future date.*/
/* ************************************ */


typedef struct LFSCountersStructure
{
   LONG  ReadFile;
   LONG  WriteFile;
   LONG  DeleteFile;
   LONG  RenMove;
   LONG  OpenFile;
   LONG  CreateFile;
   LONG  CreateAndOpenFile;
   LONG  CloseFile;
   LONG  ScanDeleteFile;
   LONG  SalvageFile;
   LONG  PurgeFile;
   LONG  MigrateFile;
   LONG  DeMigrateFile;
   LONG  CreateDir;
   LONG  DeleteDir;
   LONG  DirectoryScans;
   LONG  MapPathToDirNum;
   LONG  ModifyDirEntry;
   LONG  GetAccessRights;
   LONG  GetAccessRightsFromIDs;
   LONG  MapDirNumToPath;
   LONG  GetEntryFromPathStrBase;
   LONG  GetOtherNSEntry;
   LONG  GetExtDirInfo;
   LONG  GetParentDirNum;
   LONG  AddTrusteeR;
   LONG  ScanTrusteeR;
   LONG  DelTrusteeR;
   LONG  PurgeTrust;
   LONG  FindNextTrustRef;
   LONG  ScanUserRestNodes;
   LONG  AddUserRest;
   LONG  DeleteUserRest;
   LONG  RtnDirSpaceRest;
   LONG  GetActualAvailDskSp;
   LONG  CntOwnedFilesAndDirs;
   LONG  MigFileInfo;
   LONG  VolMigInfo;
   LONG  ReadMigFileData;
   LONG  GetVolusageStats;
   LONG  GetActualVolUsageStats;
   LONG  GetDirUsageStats;
   LONG  NMFileReadsCount;
   LONG  NMFileWritesCount;
   LONG  MapPathToDirectoryNumberOrPhantom;
   LONG  StationHasAccessRightsGrantedBelow;
   LONG  GetDataStreamLengthsFromPathStringBase;
   LONG  CheckAndGetDirectoryEntry;
   LONG  GetDeletedEntry;
   LONG  GetOriginalNameSpace;
   LONG  GetActualFileSize;
   LONG  VerifyNameSpaceNumber;
   LONG  VerifyDataStreamNumber;
   LONG  CheckVolumeNumber;
   LONG  CommitFile;
   LONG  VMGetDirectoryEntry;
   LONG  CreateDMFileEntry;
   LONG  RenameNameSpaceEntry;
   LONG  LogFile;
   LONG  ReleaseFile;
   LONG  ClearFile;
   LONG  SetVolumeFlag;
   LONG  ClearVolumeFlag;
   LONG  GetOriginalInfo;
   LONG  CreateMigratedDir;
   LONG  F3OpenCreate;
   LONG  F3InitFileSearch;
   LONG  F3ContinueFileSearch;
   LONG  F3RenameFile;
   LONG  F3ScanForTrustees;
   LONG  F3ObtainFileInfo;
   LONG  F3ModifyInfo;
   LONG  F3EraseFile;
   LONG  F3SetDirHandle;
   LONG  F3AddTrustees;
   LONG  F3DeleteTrustees;
   LONG  F3AllocDirHandle;
   LONG  F3ScanSalvagedFiles;
   LONG  F3RecoverSalvagedFiles;
   LONG  F3PurgeSalvageableFile;
   LONG  F3GetNSSpecificInfo;
   LONG  F3ModifyNSSpecificInfo;
   LONG  F3SearchSet;
   LONG  F3GetDirBase;
   LONG  F3QueryNameSpaceInfo;
   LONG  F3GetNameSpaceList;
   LONG  F3GetHugeInfo;
   LONG  F3SetHugeInfo;
   LONG  F3GetFullPathString;
   LONG  F3GetEffectiveDirectoryRights;
   LONG  ParseTree;
}LFSCountersStructure;

typedef struct GetVolumeSwitchInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  totalLFSCounters;
   LONG  currentLFSCounters;
   LONG  counters;            /* 1st counter - LFSCounters Start here*/
}GetVolumeSwitchInfoStructure;

/************************************************************************/

typedef struct GetNLMLoadedListStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  moreFlag;
   LONG  NLMCount;
   LONG  NLMNumbers;          /* 1st number - more follow*/
}GetNLMLoadedListStructure;

/************************************************************************/

typedef struct NLMInformation
{
   LONG nlmIdentificationNumber;
   LONG nlmFlags;
   LONG nlmType;
   LONG nlmParentID;
   LONG nlmMajorVersion;
   LONG nlmMinorVersion;
   LONG nlmRevision;
   LONG nlmYear;
   LONG nlmMonth;
   LONG nlmDay;
   LONG nlmAllocAvailBytes;
   LONG nlmAllocFreeCount;
   LONG nlmLastGarbCollect;
   LONG nlmMessageLanguage;
   LONG nlmNumberOfReferencedPublics;
}NLMInformation;

/* ************************************** */
/* In GetNLMInfoStructure:                */
/* At startOFLStrings there will be three */
/* length preceeded strings -- they may be*/
/* zero bytes long!  The strings are:     */
/* the file name, the NLM name, and the   */
/* copyright.                             */
/* Each string consists of one byte which */
/* contains the length of the string      */
/* followed by zero to 255 bytes of data, */
/* depending upon the value of the length */
/* byte.  When the length byte is zero, no*/
/* data is present for that string.       */
/* ************************************** */

typedef struct GetNLMInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   NLMInformation NLMInfo;
   BYTE  startOfLStrings;     /* 3 Len preceeded strings: filename, name, copyright*/
}GetNLMInfoStructure;

/************************************************************************/

typedef struct DirectoryCacheInformation
{
   LONG MinimumTimeSinceFileDelete;
   LONG AbsMinimumTimeSinceFileDelete;
   LONG MinimumNumberOfDirCacheBuffers;
   LONG MaximumNumberOfDirCacheBuffers;
   LONG NumberOfDirectoryCacheBuffers;
   LONG DCMinimumNonReferencedTime;
   LONG DCWaitTimeBeforeNewBuffer;
   LONG DCMaximumConcurrentWrites;
   LONG DCDirtyWaitTime;
   LONG debugCounters[4];
   LONG PercentOfVolumeUsedByDirs;
}DirectoryCacheInformation;

typedef struct GetDirCacheInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   DirectoryCacheInformation dirCacheInfo;
}GetDirCacheInfoStructure;

/************************************************************************/

typedef struct GetOSVersionInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   BYTE  OSMajorVersion;
   BYTE  OSMinorVersion;
   BYTE  OSRevision;
   BYTE  accountVersion;
   BYTE  VAPVersion;
   BYTE  queueingVersion;
   BYTE  securityRestLvl;
   BYTE  bridgingSupport;
   LONG  maxNumOfVol;
   LONG  maxNumOfConn;
   LONG  maxNumOfUsers;
   LONG  maxNumOfnameSpaces;
   LONG  maxNumOfLANS;
   LONG  maxNumOfMedias;
   LONG  maxNumOfStacks;
   LONG  maxDirDepth;
   LONG  maxDataStreams;
   LONG  maxNumOfSpoolPr;
   LONG  serverSerialNumber;
   WORD  serverApplicationNumber;
}GetOSVersionInfoStructure;

/************************************************************************/

typedef struct GetActiveConnListByTypeStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   BYTE  ActiveConnBitList[512];
}GetActiveConnListByTypeStructure;

/************************************************************************/

typedef struct RTagStructure
{
   LONG  rTagNumber;
   LONG  signature;
   LONG  count;
   BYTE  name;  /* null terminated string of unknown size */
}RTagStructure;

typedef struct GetNLMResourceTagList
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  totalNumOfRTags;
   LONG  currentNumOfRTags;
   RTagStructure RTagStart;   /* 1st structure - more follow - unknown size!*/
}GetNLMResourceTagList;

/************************************************************************/

typedef struct GetActiveLANBoardListStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  maxNumOfLANs;
   LONG  itemsCount;
   LONG  boardNumbers;    /* 1st number - more follow */
}GetActiveLANBoardListStructure;

/************************************************************************/

typedef struct DriverConfigStructure
{
   BYTE  DriverCFG_MajorVersion;
   BYTE  DriverCFG_MinorVersion;
   BYTE  DriverNodeAddress[6];
   WORD  DriverModeFlags;
   WORD  DriverBoardNumber;
   WORD  DriverBoardInstance;
   LONG  DriverMaximumSize;
   LONG  DriverMaxRecvSize;
   LONG  DriverRecvSize;
   LONG  DriverCardName;
   LONG  DriverShortName;
   LONG  DriverMediaType;
   WORD  DriverCardID;
   WORD  DriverMediaID;
   WORD  DriverTransportTime;
   BYTE  DriverReserved[16];
   BYTE  DriverMajorVersion;
   BYTE  DriverMinorVersion;
   WORD  DriverFlags;
   WORD  DriverSendRetries;
   LONG  DriverLink;
   WORD  DriverSharingFlags;
   WORD  DriverSlot;
   WORD  DriverIOPortsAndLengths[4];
   LONG  DriverMemoryDecode0;
   WORD  DriverLength0;
   LONG  DriverMemoryDecode1;
   WORD  DriverLength1;
   BYTE  DriverInterrupt[2];
   BYTE  DriverDMAUsage[2];
   LONG  DriverResourceTag;
   LONG  DriverConfig;
   LONG  DriverCommandString;
   BYTE  DriverLogicalName[18];
   LONG  DriverLinearMemory[2];
   WORD  DriverChannelNumber;
   BYTE  DriverIOReserved[6];
}DriverConfigStructure;

typedef struct GetLANConfigInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   DriverConfigStructure LANConfig;
}GetLANConfigInfoStructure;

/************************************************************************/

typedef struct CommonLANStructure
{
   LONG  notSupportedMask[2];
   LONG  TotalTxPacketCount;
   LONG  TotalRxPacketCount;
   LONG  NoECBAvailableCount;
   LONG  PacketTxTooBigCount;
   LONG  PacketTxTooSmallCount;
   LONG  PacketRxOverflowCount;
   LONG  PacketRxTooBigCount;
   LONG  PacketRxTooSmallCount;
   LONG  PacketTxMiscErrorCount;
   LONG  PacketRxMiscErrorCount;
   LONG  RetryTxCount;
   LONG  ChecksumErrorCount;
   LONG  HardwareRxMismatchCount;
}CommonLANStructure;

typedef struct GetLANCommonCountersStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   BYTE  statMajorVersion;
   BYTE  statMinorVersion;
   LONG  totalCommonCnts;
   LONG  totalCntBlocks;
   LONG  customCounters;
   LONG  nextCntBlock;
   CommonLANStructure   info;
}GetLANCommonCountersStructure;

/************************************************************************/

typedef struct CustomCountersInfo
{
   LONG  value;
   BYTE  stringLength;
   BYTE  stringStart;   /* string starts here if length is not zero*/
}CustomCountersInfo;

typedef struct GetCustomCountersInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  moreflag;
   LONG  numberOfCustomCounters;
   BYTE  startOfCustomCounters;     /* if number of custom counters != 0*/
}GetCustomCountersInfoStructure;

/************************************************************************/

typedef struct LSLInformation
{
   LONG  RxBufs;
   LONG  RxBufs75PerCent;
   LONG  RxBufsCheckedOut;
   LONG  RxBufMaxSize;
   LONG  MaxPhysicalSize;
   LONG  LastTimeRxBufAllocated;
   LONG  MaxNumbersOfProtocols;
   LONG  MaxNumbersOfMediaTypes;
   LONG  TotalTXPackets;
   LONG  GetECBBfrs;
   LONG  GetECBFails;
   LONG  AESEventCounts;
   LONG  PostpondedEvents;
   LONG  ECBCxlFails;
   LONG  ValidBfrsReused;
   LONG  EnqueuedSendCnt;
   LONG  TotalRXPackets;
   LONG  UnclaimedPackets;
   BYTE  StatisticsTableMajorVersion;
   BYTE  StatisticsTableMinorVersion;
}LSLInformation;

typedef struct GetLSLInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LSLInformation LSLInfo;
}GetLSLInfoStructure;

/************************************************************************/

typedef struct LogicalBoard
{
   LONG  LogTtlTxPackets;
   LONG  LogTtlRxPackets;
   LONG  LogUnclaimedPackets;
   LONG  reserved;
}LogicalBoard;

typedef  struct GetLSLBoardStatsStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LogicalBoard   boardStats;
}GetLSLBoardStatsStructure;

/************************************************************************/

/*********************************************************************/
/* The definition for the CopyOfPMStructure and CopyOfGenericInfoDef */
/* come from the media manager documentation.  The media manager is  */
/* not distributed as part of CLIB.                                  */
/*********************************************************************/

typedef struct CopyOfPMStructure
{
   BYTE  f1[64];
   LONG  f2;
   LONG  f3;
}CopyOfPMStructure;

typedef struct CopyOfGenericInfoDef
{
   CopyOfPMStructure mediaInfo;
   LONG  mediatype;
   LONG  cartridgetype;

   LONG  unitsize;
   LONG  blocksize;
   LONG  capacity;
   LONG  preferredunitsize;

   BYTE  name[64];
         
   LONG  type;
   LONG  status;
   LONG  functionmask;
   LONG  controlmask;

   LONG  parentcount;
   LONG  siblingcount;
   LONG  childcount;
   LONG  specificinfosize;

   LONG  objectuniqueid;
   LONG  mediaslot;
}CopyOfGenericInfoDef;


typedef struct GetMManagerObjInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   struct CopyOfGenericInfoDef info;
}GetMManagerObjInfoStructure;

/************************************************************************/

typedef struct GetMMObjectListsStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  nextStartNum;
   LONG  objectCount;
   LONG  ojects;     /* 1st object - more follow */
}GetMMObjectListsStructure;

/************************************************************************/

typedef struct GetMMObjectChildListStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  nextStartNum;
   LONG  objectCount;
   LONG  ojects;     /* 1st object - more follow */
}GetMMObjectChildListStructure;

/************************************************************************/

typedef struct VolumeSegmentStructure
{
   LONG  segmentDevice;
   LONG  segmentOffset;
   LONG  segmentSize;
}VolumeSegmentStructure;

typedef struct GetVolumeSegmentListStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  numberOfSegments;
   VolumeSegmentStructure  segment; /* 1st structure - more follow*/
}GetVolumeSegmentListStructure;

/************************************************************************/

typedef struct ProtocolStackInfo
{
   LONG  stackNumber;
   BYTE  stackName[16];
}ProtocolStackInfo;

typedef struct GetActiveProtocolStackStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  maxNumberOfStacks;
   LONG  stackCount;
   LONG  nextStartNumber;
   ProtocolStackInfo stackInfo; /* 1st structure - more follow*/
}GetActiveProtocolStackStructure;

/************************************************************************/

typedef struct GetProtocolConfigStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   BYTE  configMajorVersion;
   BYTE  configMinorVerstion;
   BYTE  stackMajorVersion;
   BYTE  stackMinorVersion;
   BYTE  shortName[16];
   BYTE  fullNameLength;
   BYTE  fullName;      /* 1st byte - more follow*/
}GetProtocolConfigStructure;

/************************************************************************/

typedef struct GetProtocolStatsStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   BYTE  StatMajorVersion;
   BYTE  StatMinorVersion;
   WORD  GenericCounters;  /* always set to a 3 */
   LONG  ValidCntsMask;
   LONG  TotalTxPackets;
   LONG  TotalRxPackets;
   LONG  IgnoredRxPackets;
   WORD  NumberOfCustomCounters;
}GetProtocolStatsStructure;

/************************************************************************/

typedef struct ProtocolCustomInfo
{
   LONG  value;
   BYTE  length;
   BYTE  customData; /* 1st byte - more follows*/
}ProtocolCustomInfo;

typedef struct GetProtocolCustomInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  customCount;
   ProtocolCustomInfo   info;    /* 1st structure - more follow */
}GetProtocolCustomInfoStructure;

/************************************************************************/

typedef struct GetProtocolByMediaStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  stackIDCount;
   LONG  stackID;    /* 1st ID - more follow */
}GetProtocolByMediaStructure;

/************************************************************************/

typedef struct GetProtocolByBoardStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  stackIDCount;
   LONG  stackID;    /* 1st ID - more follow */
}GetProtocolByBoardStructure;

/************************************************************************/

typedef struct GetMediaNameByNumberStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   BYTE  mediaNameLength;
   BYTE  mediaName;        /* 1st byte - more follow */
}GetMediaNameByNumberStructure;

/************************************************************************/

typedef struct GetMediaNumberListStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  maxNumberOfMedai;
   LONG  mediaListCount;
   LONG  mediaList; /* 1st number - more follow */
}GetMediaNumberListStructure;


/************************************************************************/

typedef struct GetRouterAndSAPInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  RIPSocketNumber;
   LONG  routerDownFlag;
   LONG  trackOnFlag;
   LONG  extRouterActiveFlag;
   LONG  SAPSocketNumber;
   LONG  rpyNearestServerFlag;
}GetRouterAndSAPInfoStructure;

/************************************************************************/

typedef struct GetNetRouterInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  netIDNumber;
   WORD  hopsToNet;
   WORD  netStatus;
   WORD  timeToNet;
}GetNetRouterInfoStructure;

/************************************************************************/

typedef struct RoutersInfoStructure
{
   BYTE  node[6];
   LONG  connectedLAN;
   WORD  hopsToNetCount;
   WORD  timeToNet;
}RoutersInfoStructure;

typedef struct GetNetworkRoutersInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  numberOfEntries;
   RoutersInfoStructure info; /* 1st entry - more follow */
}GetNetworkRoutersInfoStructure;

/************************************************************************/

typedef struct KnownNetworksStructure
{
   LONG  netIDNumber;
   WORD  hopsToNet;
   WORD  netStatus;
   WORD  timeToNet;
}KnownNetworksStructure;

typedef struct GetKnownNetworksStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  numberOfEntries;
   KnownNetworksStructure  info; /* 1st entry - more follow */
}GetKnownNetworksStructure;

/************************************************************************/

typedef struct GetServerInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   BYTE  serverAddress[12];
   WORD  hopsToServer;
}GetServerInfoStructure;

/************************************************************************/

typedef struct ServerSourceInfoStructure
{
   BYTE  serverNode[6];
   LONG  connectLAN;
   WORD  hopCount;
}ServerSourceInfoStructure;

typedef struct GetServerSourcesStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  numberOfEntries;
   ServerSourceInfoStructure  info; /* 1st entry - more follow */
}GetServerSourcesStructure;

/************************************************************************/

typedef struct KnownServerStructure
{
   BYTE  serverAddress[12];
   WORD  hopCount;
   BYTE  serverNameLength;
   BYTE  name;             /* 1st byte - more follow */
}KnownServerStructure;

typedef struct GetKnownServersInfoStructure
{
   LONG  currentServerTime;
   BYTE  vConsoleVersion;
   BYTE  vConsoleRevision;
   WORD  reserved;
   LONG  numberOfEntries;
   KnownServerStructure info; /* 1st entry - more follow */
}GetKnownServersInfoStructure;

/************************************************************************/

/************************************************************************/
/* Function Prototypes for Statistical Services                         */
/************************************************************************/


extern LONG SSGetCacheInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetFileServerInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetFileSystemInfo(
               LONG  fileSystemID,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetUserInfo(
               LONG connectionNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetPacketBurstInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetIPXSPXInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetGarbageCollectionInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetCPUInfo(
               LONG  CPUNumber,
               BYTE *buffer,        
               WORD bufferLen);

extern LONG SSGetVolumeSwitchInfo(
               LONG  startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetNLMLoadedList(
               LONG  startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetNLMInfo(
               LONG NLMNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetDirCacheInfo(
               BYTE *buffer,
               WORD bufferLen);
            
extern LONG SSGetOSVersionInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetActiveConnListByType(
               LONG startConnNumber,
               LONG connType,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetNLMResourceTagList(
               LONG NLMNumber,
               LONG startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetActiveLANBoardList(
               LONG startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetLANConfiguration(
               LONG boardNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetLANCommonCounters(
               LONG boardNumber,
               LONG blockNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetLANCustomCounters(
               LONG boardNumber,
               LONG startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetLSLInfo(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetLSLLogicalBoardStats(
               LONG boardNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetMediaManagerObjInfo(
               LONG objNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetMediaManagerObjList(
               LONG startNumber,
               LONG objType,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetMediaManagerObjChildList(
               LONG startNumber,
               LONG objType,
               LONG parentObjNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetVolumeSegmentList(
               LONG volumeNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetActiveProtocolStacks(
               LONG startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetProtocolConfiguration(
               LONG startNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetProtocolStatistics(
               LONG stackNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetProtocolCustomInfo(
               LONG stackNumber,
               LONG customStartNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetProtocolNumbersByMedia(
               LONG mediaNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetProtocolNumbersByLANBoard(
               LONG LANBoardNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetMediaNameByNumber(
               LONG mediaNumber,
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetLoadedMediaNumberList(
               BYTE *buffer,
               WORD bufferLen);

extern LONG SSGetRouterAndSAPInfo(
               BYTE *buffer,
               WORD  bufferLen);

extern LONG SSGetNetRouterInfo(
               LONG  networkNumber,
               BYTE *buffer,
               WORD  bufferLen);

extern LONG SSGetNetworkRoutersInfo(
               LONG  networkNumber,
               LONG  startNumber,
               BYTE *buffer,
               WORD  bufferLen);


extern LONG SSGetKnownNetworksInfo(
               LONG  startNumber,
               BYTE *buffer,
               WORD  bufferLen);

extern LONG SSGetServerInfo(
               LONG  serverType,
               BYTE  nameLength,
               BYTE  *name,
               BYTE *buffer,
               WORD  bufferLen);

extern LONG SSGetServerSourcesInfo(
               LONG  serverType,
               BYTE  nameLength,
               BYTE  *name,
               BYTE *buffer,
               WORD  bufferLen);

extern LONG SSGetKnownServersInfo(
               LONG  serverType,
               BYTE *buffer,
               WORD  bufferLen);

/************************************************************************/
/************************************************************************/

#define  _SERVSTAT_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
