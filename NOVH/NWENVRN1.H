/************************************************************************/
/* NetWare 386 Developer's C Runtime Library                            */
/*                                                                      */
/* This file contains header information for File Server Environment    */
/* Services functions.                                                  */
/*                                                                      */
/* (C) Coypright 1992, Novell Inc.                                      */
/* All rights reserved.                                                 */
/************************************************************************/
#ifdef __cplusplus
extern "C" {
#endif


/************************************************************************/

#define  ENVSERV_OVERHEAD_SIZE      (2*(signed int)sizeof(int))
#define  ENVSERV_BUFFER1_SIZE    (512 + ENVSERV_OVERHEAD_SIZE)
#define  ENVSERV_CONN_TYPE_286      (286)
#define  ENVSERV_CONN_TYPE_386      (386)

/************************************************************************/
/* Structures                                                           */
/************************************************************************/
typedef struct
 {
    LONG    systemElapsedTime;
    BYTE    bytesRead[6];
    BYTE    bytesWritten[6];
    long    totalRequestPackets;
 }CONN_USAGE;


typedef struct
 {
    LONG    systemElapsedTime;
    int     cacheBufferCount;
    int     cacheBufferSize;
    int     dirtyCacheBuffers;
    long    cacheReadRequests;
    long    cacheWriteRequests;
    long    cacheHits;
    long    cacheMisses;
    long    physicalReadRequests;
    long    physicalWriteRequests;
    WORD    physicalReadErrors;
    WORD    physicalWriteErrors;
    long    cacheGetRequests;
    long    cacheFullWriteRequests;
    long    cachePartialWriteRequests;
    long    backgroundDirtyWrites;
    long    backgroundAgedWrites;
    long    totalCacheWrites;
    long    cacheAllocations;
    WORD    thrashingCount;
    WORD    LRUBlockWasDirtyCount;
    WORD    readBeyondWriteCount;
    WORD    fragmentedWriteCount;
    WORD    cacheHitOnUnavailCount;
    WORD    cacheBlockScrappedCount;
 }DISK_CACHE_STATS;


typedef struct
 {
   LONG      systemElapsedTime;
   int       channelState;  /* DCS_RUNNING, DCS_BEINGSTOPPED,
                            DCS_STOPPED, DCS_NONFUNCTIONAL */
   int       channelSyncState;
   BYTE      driverType;
   BYTE      driverMajorVersion;
   BYTE      driverMinorVersion;
   char      driverDescription[65];
   WORD      IOAddr1;
   WORD      IOAddr1Size;
   WORD      IOAddr2;
   WORD      IOAddr2Size;
   BYTE      sharedMem1Seg[3];       /*hi-low-middle format*/
   WORD      sharedMem1Ofs;
   BYTE      sharedMem2Seg[3];       /*hi-low-middle format*/
   WORD      sharedMem2Ofs;
   BYTE      interrupt1Used;
   BYTE      interrupt1;
   BYTE      interrupt2Used;
   BYTE      interrupt2;
   BYTE      DMAChannel1Used;
   BYTE      DMAChannel1;
   BYTE      DMAChannel2Used;
   BYTE      DMAChannel2;
   int       reserved2;
   char      configDescription[80];
 }DISK_CHANNEL_STATS;


typedef struct
 {
   LONG      systemElapsedTime;
   BYTE      SFTLevel;
   BYTE      logicalDriveCount;
   BYTE      physicalDriveCount;
   BYTE      diskChannelTable[5];
   int       pendingIOCommands;
   BYTE      mappingTable[32];
   BYTE      driveMirrorTable[32];
   BYTE      deadMirrorTable[32];
   BYTE      remirroredDrive;
   BYTE      reserved;
   long      remirroredBlock;
   int       SFTErrorTable[60];
 }DRIVE_MAP_TABLE;


typedef struct
 {
   LONG      systemElapsedTime;
   int       maxRoutingBuffersAvail;
   int       maxRoutingBuffersUsed;
   int       routingBuffersInUse;
   long      totalFileServicePackets;
   int       fileServicePacketsBuffered;
   int       invalidConnPacketCount;
   int       badLogicalConnCount;
   int       packetsRcvdDuringProcCount;
   int       reprocessedRequestCount;
   int       badSequenceNumberPacketCount;
   int       duplicateReplyCount;
   int       acknowledgementsSent;
   int       badRequestTypeCount;
   int       attachDuringProcCount;
   int       attachWhileAttachingCount;
   int       forgedDetachRequestCount;
   int       badConnNumberOnDetachCount;
   int       detachDuringProcCount;
   int       repliesCanceledCount;
   int       hopCountDiscardCount;
   int       unknownNetDiscardCount;
   int       noDGroupBufferDiscardCount;
   int       outPacketNoBufferDiscardCount;
   int       IPXNotMyNetworkCount;
   long      NetBIOSPropagationCount;
   long      totalOtherPackets;
   long      totalRoutedPackets;
 }SERVER_LAN_IO;


typedef struct
 {
   LONG      systemElapsedTime;
   BYTE      processorType;
   BYTE      reserved;
   BYTE      serviceProcessCount;
   BYTE      serverUtilizationPercent;
   WORD      maxBinderyObjectsAvail;
   WORD      maxBinderyObjectsUsed;
   WORD      binderyObjectsInUse;
   int       serverMemoryInK;
   int       serverWastedMemoryInK;
   int       dynamicAreaCount;
   long      dynamicSpace1;
   long      maxUsedDynamicSpace1;
   long      dynamicSpaceInUse1;
   long      dynamicSpace2;
   long      maxUsedDynamicSpace2;
   long      dynamicSpaceInUse2;
   long      dynamicSpace3;
   long      maxUsedDynamicSpace3;
   long      dynamicSpaceInUse3;
 }SERVER_MISC_INFO;


typedef struct
 {
   LONG      systemElapsedTime;
   int       maxOpenFiles;
   int       maxFilesOpened;
   int       currOpenFiles;
   long      totalFilesOpened;
   long      totalReadRequests;
   long      totalWriteRequests;
   int       currChangedFATSectors;
   long      totalChangedFATSectors;
   int       FATWriteErrors;
   int       fatalFATWriteErrors;
   int       FATScanErrors;
   int       maxIndexFilesOpened;
   int       currOpenIndexedFiles;
   int       attachedIndexFiles;
   int       availableIndexFiles;
 }FILE_SYS_STATS;


typedef struct
 {
    BYTE    networkAddress[4];
    BYTE    hostAddress[6];
    BYTE    LANDriverInstalled;
    BYTE    optionNumber;
    char    configurationText1[80];
    char    configurationText2[80];
 }LAN_CONFIG;


typedef struct
 {
   LONG      systemElapsedTime;
   BYTE      diskChannel;
   BYTE      diskRemovable;
   BYTE      driveType;
   BYTE      controllerDriveNumber;
   BYTE      controllerNumber;
   BYTE      controllerType;
   long      driveSize;          /* in 4096 byte blocks */
   int       driveCylinders;
   BYTE      driveHeads;
   BYTE      sectorsPerTrack;
   char      driveDefinition;
   int       IOErrorCount;
   long      hotFixStart;        /* only meaningful with SFT I or greater */
   int       hotFixSize;         /* only meaningful with SFT I or greater */
   int       hotFixBlockAvailable;/* only meaningful with SFT I or greater */
   BYTE      hotFixDisabled;     /* only meaningful with SFT I or greater */
 }PHYS_DISK_STATS;


typedef struct
 {
    LONG    systemElapsedTime;
    BYTE    TTS_Supported;
    BYTE    TTS_Enabled;
    int     TTS_VolumeNumber;
    int     TTS_MaxOpenTransactions;
    int     TTS_MaxTransactionsOpened;
    int     TTS_CurrTransactionsOpen;
    long    TTS_TotalTransactions;
    long    TTS_TotalWrites;
    long    TTS_TotalBackouts;
    int     TTS_UnfilledBackouts;
    int     TTS_DiskBlocksInUse;
    long    TTS_FATAllocations;
    long    TTS_FileSizeChanges;
    long    TTS_FilesTruncated;
    BYTE    numberOfTransactions;
 }TTS_STATS;

typedef struct
{
    BYTE    connectionNumber;
    BYTE    taskNumber;
}TTS_CONNECTIONS;

/************************************************************************/

typedef struct CONN_OPEN_FILES_286
{
   BYTE  taskNumber;
   BYTE  lockType;
   BYTE  accessControl;
   BYTE  lockFlag;
   BYTE  volumeNumber;
   BYTE  reserved;
   WORD  dirEntry;
   char  fileName[14];
}CONN_OPEN_FILES_286;

typedef struct CONN_OPEN_FILES_386
{
   WORD  taskNumber;
   BYTE  lockType;
   BYTE  accessControl;
   BYTE  lockFlag;
   BYTE  volumeNumber;
   LONG  parentDirEntry;
   LONG  dirEntry;
   BYTE  forkCount;
   BYTE  nameSpace;
   BYTE  nameLength;
   BYTE  fileName[256];
}CONN_OPEN_FILES_386;

typedef struct CONN_OPEN_FILES
{
   WORD  unionType;
   union
   {
      CONN_OPEN_FILES_286 con286;
      CONN_OPEN_FILES_386 con386;
   }u;
} CONN_OPEN_FILES;


/************************************************************************/

typedef  struct   CONN_SEMAPHORE_286
{
   WORD  openCount;
   BYTE  semahoreValue;
   BYTE  taskNumber;
   BYTE  nameLength;
   BYTE  semaphoreName[255];  /* Length preceeded name.*/
} CONN_SEMAPHORE_286;

typedef  struct   CONN_SEMAPHORE_386
{
   WORD  openCount;
   WORD  semahoreValue;
   WORD  taskNumber;
   BYTE  nameLength;
   BYTE  semaphoreName[255];  /* Length preceeded name.*/
} CONN_SEMAPHORE_386;

typedef struct CONN_SEMAPHORE
{
   WORD  unionType;
   union
   {
      CONN_SEMAPHORE_286 con286;
      CONN_SEMAPHORE_386 con386;
   }u;
}CONN_SEMAPHORE;

/************************************************************************/

typedef struct CONN_TASK_INFO_286
{
   WORD  unionType;
   BYTE  lockStatus;
   union
   {
      struct
      {
         BYTE  taskNumber;
         WORD  beginAddress;
         WORD  endAddress;
         BYTE  volumeNumber;
         WORD  directoryEntry;
         BYTE  nameLength;
         BYTE  name;       /* 1st byte - more follow*/
      }LockStatus1;

      struct
      {
         BYTE  taskNumber;
         BYTE  volumeNumber;
         WORD  directoryEntry;
         BYTE  nameLength;
         BYTE  name;       /* 1st byte - more follow*/
      }LockStatus2;
   
      struct
      {
         BYTE  taskNumber;
         BYTE  nameLength;
         BYTE  name;       /* 1st byte - more follow*/
      }LockStatus3Or4;
   }waitRecord;            /* BYTE NumberOfActiveTasks - follows waitRecord*/
}CONN_TASK_INFO_286;

typedef struct CONN_TASK_INFO_386
{
   WORD  unionType;
   BYTE  lockStatus;
   union
   {
      struct
      {
         WORD  taskNumber;
         LONG  beginAddress;
         LONG  endAddress;
         WORD  volumeNumber;
         LONG  parentID;
         LONG  directoryEntry;
         BYTE  forkCount;
         BYTE  nameSpace;
         BYTE  nameLength;
         BYTE  name;       /* 1st byte - more follow*/
      }LockStatus1;

      struct
      {
         WORD  taskNumber;
         WORD  volumeNumber;
         LONG  parentID;
         LONG  directoryEntry;
         BYTE  forkCount;
         BYTE  nameSpace;
         BYTE  nameLength;
         BYTE  name;       /* 1st byte - more follow*/
      }LockStatus2;

   
      struct
      {
         WORD  taskNumber;
         BYTE  nameLength;
         BYTE  name;       /* 1st byte - more follow*/
      }LockStatus3Or4;

   }waitRecord;            /* BYTE NumberOfActiveTasks - follows waitRecord*/

}CONN_TASK_INFO_386;

typedef struct CONN_TASK_PAIRS_286
{
   BYTE  task;
   BYTE  taskStatus;
}CONN_TASK_PAIRS_286;

typedef struct CONN_TASK_PAIRS_386
{
   WORD  task;
   BYTE  taskStatus;
}CONN_TASK_PAIRS_386;

/************************************************************************/

typedef  struct CONN_USING_FILE_REQ_286
{
   WORD  lastRecordSeen;
   BYTE  directoryHandle;
   BYTE  pathLength;
   BYTE  path[255];
}CONN_USING_FILE_REQ_286;

typedef  struct CONN_USING_FILE_REQ_386
{
   BYTE  forkType;
   BYTE  volume;
   LONG  directoryID;
   WORD  nextRecord;
}CONN_USING_FILE_REQ_386;

typedef  struct CONN_USING_FILE_REQUEST
{
   WORD  unionType;
   WORD  reserved1;
   BYTE  reserved2;
   union
   {
      CONN_USING_FILE_REQ_286 req286;
      CONN_USING_FILE_REQ_386 req386;
   };
}CONN_USING_FILE_REQUEST;

typedef struct CONN_USING_FILE_REPLY_286
{
   WORD  useCount;
   WORD  openCount;
   WORD  openForReadCount;
   WORD  openForWriteCount;
   WORD  denyReadCount;
   WORD  denyWriteCount;
   WORD  nextRequestRecord;
   BYTE  locked;
   BYTE  numberOfRecords;  /* Connection records follow */
}CONN_USING_FILE_REPLY_286;

typedef struct CONN_USING_FILE_REPLY_386
{
   WORD  nextRequestRecord;
   WORD  useCount;
   WORD  openCount;
   WORD  openForReadCount;
   WORD  openForWriteCount;
   WORD  denyReadCount;
   WORD  denyWriteCount;
   BYTE  locked;
   BYTE  forkCount;
   BYTE  numberOfRecords;  /* connection records follow */
}CONN_USING_FILE_REPLY_386;

typedef  struct CONN_USING_FILE_RECORD_286
{
   WORD  connectionNumber;
   BYTE  taskNumber;
   BYTE  lockType;
   BYTE  accessFlags;
   BYTE  lockStatus;
}CONN_USING_FILE_RECORD_286;

typedef  struct CONN_USING_FILE_RECORD_386
{
   WORD  connectionNumber;
   WORD  taskNumber;
   BYTE  lockType;
   BYTE  accessFlags;
   BYTE  lockStatus;
}CONN_USING_FILE_RECORD_386;

typedef struct CONN_USING_FILE_REPLY
{
   WORD  unionType;
   union
   {
      struct CONN_USING_FILE_REPLY_286 rep286;
      struct CONN_USING_FILE_REPLY_386 rep386;
   };
}CONN_USING_FILE_REPLY;

/************************************************************************/

typedef struct LOGICAL_RECORD_INFO_286
{
   WORD  useCount;
   WORD  shareableLockCount;
   WORD  nextRequestRecord;
   BYTE  locked;
   BYTE  numberOfRecords;
}LOGICAL_RECORD_INFO_286;


typedef struct LOGICAL_RECORD_INFO_386
{
   WORD  useCount;
   WORD  shareableLockCount;
   BYTE  locked;
   WORD  nextRequestRecord;
   WORD  numberOfRecords;
}LOGICAL_RECORD_INFO_386;

typedef struct LOGICAL_RECORD_286
{
   WORD  connectionNumber;
   BYTE  taskNumber;
   BYTE  lockStatus;
}LOGICAL_RECORD_286;

typedef struct LOGICAL_RECORD_386
{
   WORD  connectionNumber;
   WORD  taskNumber;
   BYTE  lockStatus;
}LOGICAL_RECORD_386;

typedef struct LOGICAL_RECORD_INFO
{
   WORD  unionType;
   union
   {
      LOGICAL_RECORD_INFO_286 lr286;
      LOGICAL_RECORD_INFO_386 lr386;
   }u;
}LOGICAL_RECORD_INFO;

typedef struct LOGICAL_RECORD_REQUEST
{
   WORD  reserved1;
   BYTE  reserved2;
   WORD  nextRecord;
   BYTE  nameLength;
   BYTE  name[255];
}LOGICAL_RECORD_REQUEST;

/************************************************************************/

typedef struct CONN_LOGICAL_RECORD_286
{
   WORD  nextRequest;
   BYTE  numberOfRecords;
}CONN_LOGICAL_RECORD_286;

typedef struct CONN_LOGICAL_RECORD_386
{
   WORD  nextRequest;
   WORD  numberOfRecords;
}CONN_LOGICAL_RECORD_386;

typedef struct CONN_LOGICAL_RECORD
{
   WORD  unionType;
   union
   {
      CONN_LOGICAL_RECORD_286 lr286;
      CONN_LOGICAL_RECORD_386 lr386;
   }u;
}CONN_LOGICAL_RECORD;

typedef struct CONN_LOGICAL_RECORD_BLOCK_286
{
   BYTE  taskNumber;
   BYTE  lockStatus;
   BYTE  lockNameLength;
   BYTE  lockName;      /* 1st byte - more follow */
}CONN_LOGICAL_RECORD_BLOCK_286;

typedef struct CONN_LOGICAL_RECORD_BLOCK_386
{
   WORD  taskNumber;
   BYTE  lockStatus;
   BYTE  lockNameLength;
   BYTE  lockName;      /* 1st byte - more follow */
}CONN_LOGICAL_RECORD_BLOCK_386;

/************************************************************************/

typedef struct FILE_PHYSICAL_RECORD_LOCK_286
{
   WORD  nextRequest;
   BYTE  numberOfLocks;
   BYTE  reserved;
}FILE_PHYSICAL_RECORD_LOCK_286;

typedef struct FILE_PHYSICAL_RECORD_LOCK_386
{
   WORD  nextRequest;
   WORD  numberOfLocks;
}FILE_PHYSICAL_RECORD_LOCK_386;

typedef struct FILE_PHYSICAL_RECORD_LOCK
{
   WORD unionType;
   union
   {
      FILE_PHYSICAL_RECORD_LOCK_286 pr286;
      FILE_PHYSICAL_RECORD_LOCK_286 pr386;
   }u;
}FILE_PHYSICAL_RECORD_LOCK;

typedef struct FILE_PHYSICAL_RECORD_286
{
   WORD  loggedCount;
   WORD  shareLockCount;
   LONG  recordStart;
   LONG  recordEnd;
   WORD  connectionNumber;
   BYTE  taskNumber;
   BYTE  lockType;
}FILE_PHYSICAL_RECORD_286;

typedef struct FILE_PHYSICAL_RECORD_386
{
   WORD  loggedCount;
   WORD  shareLockCount;
   LONG  recordStart;
   LONG  recordEnd;
   WORD  connectionNumber;
   WORD  taskNumber;
   BYTE  lockType;
}FILE_PHYSICAL_RECORD_386;

typedef struct FILE_PHYSICAL_REQUEST_286
{
   WORD  lastRecord;
   BYTE  directoryHandle;
   BYTE  pathLength;
   BYTE  name[255];
}FILE_PHYSICAL_REQUEST_286;

typedef struct FILE_PHYSICAL_REQUEST_386
{
   BYTE  forkType;
   BYTE  volume;
   LONG  directoryID;
   WORD  next;
}FILE_PHYSICAL_REQUEST_386;

typedef struct FILE_PHYSICAL_RECORD_REQUEST
{
   WORD  unionType;
   WORD  reserved1;
   BYTE  reserved2;
   union
   {
      FILE_PHYSICAL_REQUEST_286 pr286;
      FILE_PHYSICAL_REQUEST_386 pr386;
   }u;
}  FILE_PHYSICAL_RECORD_REQUEST;

/************************************************************************/

typedef struct CONN_RECORD_LOCKS_286
{
   WORD  nextRecord;
   BYTE  numberOfLocks;
   BYTE  reserved;       /* record locks follow */
}CONN_RECORD_LOCKS_286;

typedef struct CONN_RECORD_LOCKS_386
{
   WORD  nextRecord;
   WORD  numberOfLocks;  /* record locks follow */
}CONN_RECORD_LOCKS_386;

typedef struct CONN_RECORD_LOCKS
{
   WORD  unionType;
   union
   {
      CONN_RECORD_LOCKS_286 rl286;
      CONN_RECORD_LOCKS_386 rl386;
   }u;
}CONN_RECORD_LOCKS;

typedef struct CONN_LOCK_RECORD_286
{
   BYTE  taskNumber;
   BYTE  lockFlag;
   LONG  recordStart;
   LONG  recordEnd;
}CONN_LOCK_RECORD_286;

typedef struct CONN_LOCK_RECORD_386
{
   WORD  taskNumber;
   BYTE  lockFlag;
   LONG  recordStart;
   LONG  recordEnd;
}CONN_LOCK_RECORD_386;

typedef struct CONN_LOCK_REQUEST_286
{
   WORD  connectionNumber;
   WORD  lastRecord;
   BYTE  volume;
   WORD  directoryID;
   BYTE  pathLength;
   BYTE  fileName[14];
}CONN_LOCK_REQUEST_286;

typedef struct CONN_LOCK_REQUEST_386
{
   WORD  connectionNumber;
   BYTE  forkType;
   BYTE  volume;
   LONG  directoryID;
   WORD  next;
}CONN_LOCK_REQUEST_386;

typedef struct CONN_LOCK_REQUEST
{
   WORD  unionType;
   WORD  reserved1;
   BYTE  reserved2;
   union
   {
      CONN_LOCK_REQUEST_286 lr286;
      CONN_LOCK_REQUEST_386 lr386;
   }u;
}CONN_LOCK_REQUEST;

/************************************************************************/

typedef struct SEMAPHORE_INFO_286
{
   WORD  nextRequest;
   WORD  openCount;
   BYTE  semaphoreValue;
   BYTE  numberOfRecords;
}SEMAPHORE_INFO_286;

typedef struct SEMAPHORE_INFO_386
{
   WORD  nextRequest;
   WORD  openCount;
   WORD  semaphoreValue;
   WORD  numberOfRecords;
}SEMAPHORE_INFO_386;

typedef struct SEMAPHORE_INFO
{
   WORD  unionType;
   union
   {
      SEMAPHORE_INFO_286 si286;
      SEMAPHORE_INFO_386 si386;
   }u;
}SEMAPHORE_INFO;

typedef struct SEMAPHORE_INFO_RECORD_286
{
   WORD  connectionNumber;
   BYTE  taskNumber;
}SEMAPHORE_INFO_RECORD_286;

typedef struct SEMAPHORE_INFO_RECORD_386
{
   WORD  connectionNumber;
   WORD  taskNumber;
}SEMAPHORE_INFO_RECORD_386;

typedef struct SEMAPHORE_INFO_REQUEST
{
   WORD  reserved1;
   BYTE  reserved2;
   WORD  nextRecord;
   BYTE  nameLength;
   BYTE  name[255];
}SEMAPHORE_INFO_REQUEST;

/************************************************************************/
/* Function Prototypes                                                  */
/************************************************************************/

extern int  GetConnectionsOpenFiles(
   WORD  connectionNumber,
   int   *lastRecord,
   int   *lastTask,
   int   structSize,
   CONN_OPEN_FILES   *openFiles,
   void  *buffer,
   int   bufferSize);

extern int  GetConnectionSemaphores(
   WORD  connectionNumber,
   int   *lastRecord,
   int   *lastTask,
   int   structSize,
   CONN_SEMAPHORE *connectionSemaphore,
   void  *buffer,
   int   bufferSize);

extern int GetConnectionsTaskInformation(
   WORD  connectionNumber,
   void  **connectionTaskInfo,
   void  *buffer,
   int   bufferSize);

extern int GetConnectionsUsingFile(
   int   requestSize,
   void  *request,
   void  *buffer,
   int   bufferSize);

extern int  GetLogicalRecordInformation(
   int   requestSize,
   void  *request,
   void  *buffer,
   int   bufferSize);

extern int  GetLogicalRecordsByConnection(
   WORD  connectionNumber,
   WORD  nextRecord,
   void  *buffer,
   int   bufferSize);

extern int  GetPhysicalRecordLocksByFile(
   int   requestSize,
   void  *request,
   void  *buffer,
   int   bufferSize);

extern int  GetPhysRecLockByConnectAndFile(
   int   requestSize,
   void  *request,
   void  *buffer,
   int   bufferSize);


extern int  GetSemaphoreInformation(
   int   requestSize,
   void  *request,
   void  *buffer,
   int   bufferSize);

/************************************************************************/
/************************************************************************/

extern int GetConnectionsUsageStats(
   int   connectionNumber,
   CONN_USAGE *connectionUsage);

extern int GetDiskCacheStats(
   DISK_CACHE_STATS  *cacheStats);

extern int GetDiskChannelStats(
   int   channelNumber,
   DISK_CHANNEL_STATS  *diskChannelStats);

extern int GetDriveMappingTable(
   DRIVE_MAP_TABLE   *driveMappingTable);

extern int GetFileServerLANIOStats(
   SERVER_LAN_IO *serverLANIOStats);

extern int GetFileServerMiscInformation(
   SERVER_MISC_INFO *miscInformation);

extern int GetFileSystemStats(
   FILE_SYS_STATS *fileSysStats);

extern int GetLANDriverConfigInfo(
   BYTE  LANBoardNumber,
   LAN_CONFIG *LANConfiguration);

extern int GetPhysicalDiskStats(
   BYTE  physicalDiskNumber,
   PHYS_DISK_STATS *physicalDiskStats);

extern int TTSGetStats(
   TTS_STATS *TTSStats,
   int   bufferLen,
   BYTE  *buffer);


extern int GetPathFromDirectoryEntry(
   BYTE  volumeNumber,
   WORD  directoryEntry,
   BYTE  *pathLength,
   char  *path);

/************************************************************************/
/************************************************************************/

#ifdef __cplusplus
};
#endif
