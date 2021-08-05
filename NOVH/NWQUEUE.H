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

#ifndef _QUESERV_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define NWMAX_QENTRIES      250

/* the following manifest constant applies to server versions BELOW 3.X */
#define NWMAX_JOB_SERVERS    25

/* the following manifest constant applies to server versions ABOVE 2.X */
#define NWQ_MAX_JOB_SERVERS  50

#define  QF_AUTO_START        0x08
#define  QF_SERVICE_RESTART   0x10
#define  QF_ENTRY_OPEN        0x20
#define  QF_USER_HOLD         0x40
#define  QF_OPERATOR_HOLD     0x80

   /* Queue Status Flags */

   #define QS_CANT_ADD_JOBS        0x01
   #define QS_SERVERS_CANT_ATTACH  0x02
   #define QS_CANT_SERVICE_JOBS    0x04

#pragma pack (1);
typedef struct
   {
   BYTE clientStation;
   BYTE clientTaskNumber;
   long clientIDNumber;
   long targetServerIDNumber;
   BYTE targetExecutionTime[6];
   BYTE jobEntryTime[6];
   WORD jobNumber;
   WORD jobType;
   BYTE jobPosition;
   BYTE jobControlFlags;
   BYTE jobFileName[14];
   BYTE jobFileHandle[6];
   BYTE serverStation;
   BYTE serverTaskNumber;
   long serverIDNumber;
   BYTE textJobDescription[50];
   BYTE clientRecordArea[152];
   } JobStruct;

    typedef struct
        {
        BYTE    year;           /*--  (19)80 - (20)79                --*/
        BYTE    month;          /*--  1 - January, 2 = February, ... --*/
        BYTE    day;            /*--  1 - 31                         --*/
        BYTE    hour;           /*--  0 - 23                         --*/
        BYTE    minute;         /*--  0 - 59                         --*/
        BYTE    second;         /*--  0 - 59                         --*/
        } NWStandardChronRec_t;

    typedef NWStandardChronRec_t  NWQChronRec_t;
    typedef BYTE                  NWFileHandle_t[6];

    /* Queue manager subtype definitions */
    typedef struct
        { 
        LONG    clientConnNum; 
        LONG    taskNum; 
        LONG    id;
        } NWQEntityInfo_t;

    typedef struct
        {
        LONG            id;
        NWQChronRec_t   executionTime;
        } NWQJobServerInfo_t;

    typedef struct
        {
        NWQChronRec_t   entryTime;
        LONG            num;
        WORD            type;
        WORD            position;
        WORD            controlFlags;
        char            assocFileName[14];
        NWFileHandle_t  fileHandle;
        } NWQJobInfo_t;

    typedef struct
        {
        NWQChronRec_t   entryTime;
        LONG            num;
        WORD            formType;
        WORD            position;
        WORD            controlFlags;
        char            assocFileName[14];
        NWFileHandle_t  fileHandle;
        } NWQPrintJobInfo_t;

    typedef struct                 /* job server record for printing   */
        {
        BYTE    versionNumber;
        BYTE    tabSize;
        WORD    numberOfCopies;
        WORD    printControlFlags;
        WORD    maxLinesPerPage;
        WORD    maxCharsPerLine;
        char    formName[13];
        BYTE    reserve[9];
        char    bannerNameField[13];
        char    bannerFileField[13];
        char    bannerFileName[14];
        char    directoryPath[80];
        } NWQPrintServerRec_t;

    /* Queue manager type definitions */
    typedef struct
        {                                   /* information supplied for:        */
        BYTE                reserved[10];
        NWQEntityInfo_t     client;           /* the job client                   */
        NWQJobServerInfo_t  target;           /* the target job server            */
        NWQJobInfo_t        job;              /* the job itself                   */
        NWQEntityInfo_t     jobServer;        /* the actual job server            */
        BYTE                textJobDescription[50];
        BYTE                jobServerRecord[152];
        } NWQJobRec_t;

int   AbortServicingQueueJobAndFile(
         long __queueID,
         WORD __jobNumber,
         int __fileHandle );

int   AttachQueueServerToQueue(
         long __queueID );

int   ChangeQueueJobEntry(
         long __queueID,
         JobStruct *__job );

int   ChangeQueueJobPosition(
         long __queueID,
         WORD __jobNumber,
         BYTE __newPosition);

int   ChangeToClientRights(
         long __queueID,
         WORD __jobNumber );

int   CloseFileAndAbortQueueJob(
         long __queueID,
         WORD __jobNumber,
         int __fileHandle );

int   CloseFileAndStartQueueJob(
         long __queueID,
         WORD __jobNumber,
         int __fileHandle );

int   CreateAQueue(
         char *__queueName,
         int __queueType,
         char *__pathName,
         long *__queueID );

int   CreateQueueJobAndFile(
         long __queueID,
         JobStruct *__job,
         int *__fileHandle);

int   DestroyQueue(
         long __queueID );

int   DetachQueueServerFromQueue(
         long __queueID );

int   FinishServicingQueueJobAndFile(
         long __queueID,
         WORD __jobNumber,
         long __charge,
         int __fileHandle );

int   GetQueueJobList(
         long __queueID,
         WORD *__jobCount,
         WORD *__jobNumberList,
         WORD __maxJobNumbers );

int   GetQueueJobsFileSize(
         long __queueID,
         int __jobNumber,
         long *__fileSize );

int   ReadQueueCurrentStatus(
         long __queueID,
         BYTE *__queueStatus,
         BYTE *__numberOfJobs,
         BYTE *__numberOfServers,
         long *__serverIDList,
         WORD *__serverStationList,
         WORD __maxNumberOfServers );

int   ReadQueueJobEntry(
         long __queueID,
         WORD __jobNumber,
         JobStruct *__job );

int   ReadQueueServerCurrentStatus(
         long __queueID,
         long __serverID,
         char __serverStation,
         char *__serverStatusRecord );

int   RemoveJobFromQueue(
         long __queueID,
         WORD __jobNumber );

int   RestoreQueueServerRights(
         void );

int   ServiceQueueJobAndOpenFile(
         long __queueID,
         WORD __targetJobType,
         JobStruct *__job,
         int *__fileHandle );

int   SetQueueCurrentStatus(
         long __queueID,
         BYTE __queueStatus );

int   SetQueueServerCurrentStatus(
         long __queueID,
         BYTE *__serverStatusRecord );

extern int NWQAbortJob( LONG queueID,
    LONG jobNum, int fileHandle );

extern int NWQAbortJobService( LONG queueID,
    LONG jobNum, int fileHandle );

extern int NWQAttachServer( LONG queueID );

extern int NWQBeginJobService( LONG queueID,
    WORD targetJobType, NWQJobRec_t *jobInfo, int *fileHandle );

extern int NWQChangeJobQueue( LONG srcQueueID, LONG srcJobNum,
    LONG dstQueueID, LONG *dstJobNum);

extern int NWQChangeJobEntry( LONG queueID,
    NWQJobRec_t *jobInfo );

extern int NWQChangeJobPosition( LONG queueID,
    LONG jobNum, LONG newPosition );

extern int NWQChangeToClientRights( LONG queueID,
    LONG jobNum );

extern int NWQCreate( char *queueName,
    WORD queueType, char *pathName, LONG *queueID );

extern int NWQCreateJob( LONG queueID,
    NWQJobRec_t *jobInfo, int *fileHandle );

extern int NWQDestroy( LONG queueID );

extern int NWQDetachServer( LONG queueID );

extern int NWQEndJobService( LONG queueID,
    LONG jobNum, LONG chargeInfo, int fileHandle );

extern int NWQGetJobEntry( LONG queueID,
    LONG jobNum, NWQJobRec_t *jobInfo );

extern int NWQGetJobFileSize( LONG queueID,
    LONG jobNum, LONG *fileSize );

extern int NWQGetServers( LONG queueID,
    LONG *currentServers, LONG *qServerIDs, LONG *qServerConnNums );

extern int NWQGetServerStatus( LONG queueID,
    LONG jobServerID, LONG jobServerConnNum, void *jobServerRecord );

extern int NWQGetStatus( LONG queueID,
    LONG *queueStatus, LONG *currentEntries, LONG *currentServers );

extern int NWQMarkJobForService( LONG queueID,
    LONG jobNum, int fileHandle );

extern int NWQRemoveJob( LONG queueID,
    LONG jobNum );

extern int NWQRestoreServerRights( void );

extern int NWQScanJobNums( LONG queueID,
    LONG *queueSequence, LONG *totalJobs, LONG *jobCount,
    LONG *jobNumList );

extern int NWQServiceJob( LONG queueID, LONG targetJobTypesCount, WORD
    *targetJobTypes, NWQJobRec_t *jobInfo, int *fileHandle);

extern int NWQSetServerStatus( LONG queueID,
    void *serverStatusRecord );

extern int NWQSetStatus( LONG queueID,
    LONG queueStatus );

#define _QUESERV_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _QUESERV_H_INCLUDED  */
