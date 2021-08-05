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

#ifndef _NEWIN400_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/*
** This header file is useful for creating NLMs which dynamically import
** functions which are new in version 4.0 (as compared to the previous
** CLIB version: 3.11).  By using the API ImportSymbol to dynamically import
** an API, an application can provide a base level of functionality when
** loaded on v3.11 and also take advantage of new CLIB APIs if loaded on
** v4.00.  The following function pointer typedefs are useful in declaring
** function pointers to call the APIs which are new as of CLIB v4.00.
*/


/*****************************************************************************/
/*    ADVANCED.H is the header associated with the following new functions   */
/*****************************************************************************/

#include <advanced.h>

typedef LONG (*T_GetSetableParameterValue)
   (LONG, BYTE *, void *);

typedef LONG (*T_ScanSetableParameters)
   (LONG, LONG *, BYTE *, LONG *, LONG *, LONG *, void *, void *, LONG *, LONG *);

typedef LONG (*T_SetSetableParameterValue)
   (LONG, BYTE *, void *);

typedef int (*T_UnimportSymbol)
   (int, char *);

/*****************************************************************************/
/*    CONIO.H is the header associated with the following new functions      */
/*****************************************************************************/

#include <conio.h>

typedef int (*T_GetScreenInfo)
   (int, char *, LONG *);

typedef LONG (*T_SetScreenAreaAttribute)
   (LONG, LONG, LONG, LONG, LONG);

typedef LONG (*T_SetScreenCharacterAttribute)
   (LONG, LONG, LONG);

/*****************************************************************************/
/*    DATAMIG.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <datamig.h>

typedef LONG (*T_NWDeRegisterDMSupportModule)
   (LONG, BYTE *, LONG);

typedef LONG (*T_NWDeRegisterRTDataMigrationNLM)
   (LONG, BYTE *, LONG);

typedef void (*T_NWGetDataMigratorInfo)
   (LONG *,LONG *,LONG *,LONG *);

typedef LONG (*T_NWGetDefaultSupportModule)
   (LONG *);

typedef LONG (*T_NWGetDMFileInfo)
   (char *, LONG, LONG *, LONG *, LONG *, LONG *);

typedef LONG (*T_NWGetDMVolumeInfo)
   (LONG, LONG, LONG *, LONG *, LONG *, LONG *, LONG *, LONG *);

typedef LONG (*T_NWGetSupportModuleInfo)
   (LONG, LONG, void *, LONG *);

typedef LONG (*T_NWIsDataMigrationAllowed)
   (LONG);

typedef LONG (*T_NWMoveFileFromDM)
   (char *, LONG);

typedef LONG (*T_NWMoveFileToDM)
   (char *, LONG, LONG, LONG);

typedef LONG (*T_NWPeekFileData)
   (char *, LONG, LONG, LONG, LONG, BYTE *, LONG *,LONG *, LONG *);

typedef LONG (*T_NWRegisterDMSupportModule)
   (LONG, LONG (*[])(), BYTE *SupportModuleName, LONG, LONG, LONG *);

typedef LONG (*T_NWRegisterRTDataMigrationNLM)
   (LONG, LONG (*[])(), BYTE *);

typedef LONG (*T_NWSetDefaultSupportModule)
   (LONG, LONG *);

/*****************************************************************************/
/*    DFS.H is the header associated with the following new functions        */
/*****************************************************************************/

#include <dfs.h>

typedef LONG (*T_DFSclose)
   (LONG);

typedef LONG (*T_DFScreat)
   (BYTE *, LONG, LONG);

typedef LONG (*T_DFSExpandFile)
   (LONG, LONG, LONG, LONG, LONG);

typedef LONG (*T_DFSFreeLimboVolumeSpace)
   (LONG, LONG);

typedef LONG (*T_DFSsopen)
   (BYTE *, LONG, LONG, LONG, LONG, LONG);

typedef LONG (*T_DFSRead)
   (LONG, LONG, LONG, BYTE *);

typedef LONG (*T_DFSReadNoWait)
   (LONG, LONG, LONG, BYTE *, struct DFSCallBackParameters *);

typedef LONG (*T_DFSReturnFileMappingInformation)
   (LONG, LONG, LONG *, LONG, struct FileMapStructure *);

typedef LONG (*T_DFSReturnVolumeBlockInformation)
   (LONG, LONG, LONG, BYTE *);

typedef LONG (*T_DFSReturnVolumeMappingInformation)
   (LONG, struct VolumeInformationStructure *);

typedef LONG (*T_DFSWrite)
   (LONG, LONG, LONG, BYTE *);

typedef LONG (*T_DFSWriteNoWait)
   (LONG, LONG, LONG, BYTE *, struct DFSCallBackParameters *);

typedef LONG (*T_DFSSetEndOfFile)
   (LONG, LONG, LONG);

/*****************************************************************************/
/*    EXTATTR.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <extattr.h>

typedef int (*T_CloseEA)
   (int);

/*****************************************************************************/
/*    FILEENGD.H is the header associated with the following new functions   */
/*****************************************************************************/

#include <fileengd.h>

typedef int (*T_FEGetEntryVersion)
   (int, LONG, BYTE *, LONG, WORD *);

typedef int (*T_FEMapConnsHandleToVolAndDir)
   (LONG, int, int *, LONG *);

typedef int (*T_NWGetDirBaseFromPath)
   (char *, BYTE, LONG *, LONG *, LONG *);

/*****************************************************************************/
/*    FSHOOKS.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <fshooks.h>

typedef LONG (*T_NWAddFSMonitorHook)
   (LONG, void *, LONG *);

typedef LONG (*T_NWRemoveFSMonitorHook)
   (LONG, LONG);

/*****************************************************************************/
/*    IO.H is the header associated with the following new functions         */
/*****************************************************************************/

#include <io.h>

typedef int (*T_dup)
   (int);
typedef int (*T_dup2)
   (int, int);

/*****************************************************************************/
/*    NAMESPC.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <namespc.h>

typedef int (*T_NWGetHugeNSInfo)
   (BYTE, BYTE, LONG, LONG, BYTE *, BYTE *, LONG *, BYTE *);

typedef int (*T_NWGetNameSpaceEntryName)
   (BYTE *, LONG, LONG, BYTE *);

typedef int (*T_NWGetNSInfo)
   (BYTE, BYTE, BYTE, LONG, LONG, BYTE *);

typedef int (*T_NWGetNSLoadedList)
   (BYTE, WORD, BYTE *, WORD *);

typedef int (*T_NWQueryNSInfoFormat)
   (BYTE, BYTE, NW_NS_INFO *);

typedef int (*T_NWSetHugeNSInfo)
   (BYTE, BYTE, LONG, LONG, BYTE *, LONG, BYTE *, BYTE *, LONG *);

typedef int (*T_NWSetNameSpaceEntryName)
   (BYTE *, LONG, BYTE *);

typedef int (*T_NWSetNSInfo)
   (BYTE, BYTE, BYTE, LONG, LONG, LONG, BYTE *);

/*****************************************************************************/
/*    NCPEXT.H is the header associated with the following new functions     */
/*****************************************************************************/

#include <ncpext.h>

typedef int (*T_NWGetNCPExtensionInfoByID)
   (LONG, char *, BYTE *, BYTE *, BYTE *, void *);

typedef int (*T_NWRegisterNCPExtensionByID)
   (LONG, const char *, BYTE (*)(struct NCPExtensionClient *, void *, LONG,
   void *, LONG *), void (*)(LONG, LONG), void (*)(struct NCPExtensionClient *,
   void *), BYTE, BYTE, BYTE, void **);

typedef int (*T_NWSendNCPExtensionFraggedRequest)
   (LONG, const struct NCPExtensionMessageFrag *, struct NCPExtensionMessageFrag *);

/*****************************************************************************/
/*    NWDSAPI.H is the header associated with the following new functions     */
/*****************************************************************************/

#include <nwdsapi.h>

// new functions in NWDSMISC.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSCloseIteration)
   (NWDSContextHandle, int32, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetBinderyContext)
   (NWDSContextHandle, int, uint8 NWFAR *);

typedef int NWFAR NWPASCAL (*T_NWGetFileServerUTCTime)
   (WORD, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetSyntaxID)
   (NWDSContextHandle, char NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWIsDSServer)
   (WORD, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSReadSyntaxes)
   (NWDSContextHandle, uint32, uint8, Buf_T NWFAR *, int32 NWFAR *,
   Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRepairTimeStamps)
   (NWDSContextHandle, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSReplaceAttrNameAbbrev)
   (NWDSContextHandle, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetObjectHostServerAddress)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, Buf_T NWFAR *);

// new functions in NWDSASA.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAuthenticate)
   (int, uint32, NWDS_Session_Key_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSChangeObjectPassword)
   (NWDSContextHandle, uint32, char NWFAR *, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGenerateObjectKeyPair)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSLogin)
   (NWDSContextHandle, uint32, char NWFAR *, char NWFAR *, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSLogout)
   (NWDSContextHandle);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSVerifyObjectPassword)
   (NWDSContextHandle, uint32, char NWFAR *, char NWFAR *);

// new functions in NWDSBUFT.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAllocBuf)
   (size_t, Buf_T NWFAR * NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSComputeAttrValSize)
   (NWDSContextHandle, Buf_T NWFAR *, uint32, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSFreeBuf)
   (Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetAttrCount)
   (NWDSContextHandle, Buf_T NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetAttrDef)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, Attr_Info_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetAttrName)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, uint32 NWFAR *,
   uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetAttrVal)
   (NWDSContextHandle, Buf_T NWFAR *, uint32, void NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetClassDef)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, Class_Info_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetClassDefCount)
   (NWDSContextHandle, Buf_T NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetClassItem)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetClassItemCount)
   (NWDSContextHandle, Buf_T NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetObjectCount)
   (NWDSContextHandle, Buf_T NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetObjectName)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, uint32 NWFAR *,
   Object_Info_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetPartitionInfo)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetServerName)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetSyntaxCount)
   (NWDSContextHandle, Buf_T NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetSyntaxDef)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *, Syntax_Info_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSInitBuf)
   (NWDSContextHandle, uint32, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutAttrName)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutAttrVal)
   (NWDSContextHandle, Buf_T NWFAR *, uint32, void NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutChange)
   (NWDSContextHandle, Buf_T NWFAR *, uint32, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutClassItem)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutClassName)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutSyntaxName)
   (NWDSContextHandle, Buf_T NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSBeginClassItem)
   (NWDSContextHandle, Buf_T NWFAR *);

// new functions in NWDSPART.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAddPartition)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, int32 NWFAR *, uint8,
   Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAddReplica)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSChangeReplicaType)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSJoinPartitions)
   (NWDSContextHandle, char NWFAR *, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSListPartitions)
   (NWDSContextHandle, int32 NWFAR *, char NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRemovePartition)
   (NWDSContextHandle, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRemoveReplica)
   (NWDSContextHandle, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSSplitPartition)
   (NWDSContextHandle, char NWFAR *, uint32);

// new functions in NWDSNAME.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAbbreviateName)
   (NWDSContextHandle, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSCanonicalizeName)
   (NWDSContextHandle, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRemoveAllTypes)
   (NWDSContextHandle, char NWFAR *, char NWFAR *);

// new functions in NWDSSCH.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSDefineAttr)
   (NWDSContextHandle, char NWFAR *, Attr_Info_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSDefineClass)
   (NWDSContextHandle, char NWFAR *, Class_Info_T NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSListContainableClasses)
   (NWDSContextHandle, char NWFAR *, int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSModifyClassDef)
   (NWDSContextHandle, char NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSReadAttrDef)
   (NWDSContextHandle, uint32, uint8, Buf_T NWFAR *, int32 NWFAR *,
   Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSReadClassDef)
   (NWDSContextHandle, uint32, uint8, Buf_T NWFAR *,
   int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRemoveAttrDef)
   (NWDSContextHandle, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRemoveClassDef)
   (NWDSContextHandle, char NWFAR *);

// new functions in NWDSDC.H:

typedef NWDSContextHandle NWFAR NWPASCAL (*T_NWDSCreateContext)
   (void);

typedef NWDSContextHandle NWFAR NWPASCAL (*T_NWDSDuplicateContext)
   (NWDSContextHandle);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSFreeContext)
   (NWDSContextHandle);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetContext)
   (NWDSContextHandle, int, void NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSSetContext)
   (NWDSContextHandle, int, void NWFAR *);

// new functions in NWDSACL.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetEffectiveRights)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, char NWFAR *,
   uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSListAttrsEffectiveRights)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint8, Buf_T NWFAR *,
   int32 NWFAR *, Buf_T NWFAR *);

// new functions in NWDSDSA.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAddObject)
   (NWDSContextHandle, char NWFAR *, int32 NWFAR *, uint8, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSBackupObject)
   (NWDSContextHandle, char NWFAR *, int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSCompare)
   (NWDSContextHandle, char NWFAR *, Buf_T NWFAR *, uint8 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetPartitionRoot)
   (NWDSContextHandle, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSList)
   (NWDSContextHandle, char NWFAR *, int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSMapIDToName)
   (NWDSContextHandle, int, uint32, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSMapNameToID)
   (NWDSContextHandle, int, char NWFAR *, uint32 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSModifyObject)
   (NWDSContextHandle, char NWFAR *, int32 NWFAR *, uint8, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSModifyDN)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint8);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSModifyRDN)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint8);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSMoveObject)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRead)
   (NWDSContextHandle, char NWFAR *, uint32, uint8, Buf_T NWFAR *,
   int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSReadEffectivePrivileges)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint8, Buf_T NWFAR *,
   int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSReadObjectInfo)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, Object_Info_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRemoveObject)
   (NWDSContextHandle, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSRestoreObject)
   (NWDSContextHandle, char NWFAR *, int32 NWFAR *, uint8, uint32,
   uint8 NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSSearch)
   (NWDSContextHandle, char NWFAR *, int, uint8, Buf_T NWFAR *, uint32,
   uint8, Buf_T NWFAR *, int32 NWFAR *, int32,
   int32 NWFAR *, Buf_T NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSOpenStream)
   (NWDSContextHandle, char NWFAR *, char NWFAR *, uint32, int NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSWhoAmI)
   (NWDSContextHandle, char NWFAR *);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetServerDN)
   (NWDSContextHandle, int, char NWFAR *);
   
typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSGetServerAddresses)
   (NWDSContextHandle, int, uint32 NWFAR *,
   Buf_T NWFAR *);

// new functions in NWDSFILT.H:

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAddFilterToken)
   (Filter_Cursor_T NWFAR *, uint16, void NWFAR *, uint32);

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSAllocFilter)
   (Filter_Cursor_T NWFAR * NWFAR *);

typedef void NWFAR NWPASCAL (*T_NWDSFreeFilter)
   (Filter_Cursor_T NWFAR *, void (NWFAR *)(uint32, void NWFAR *));

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSPutFilter)
   (NWDSContextHandle, Buf_T NWFAR *, Filter_Cursor_T NWFAR *,
   void (NWFAR *)(uint32, void NWFAR *));

typedef NWDSCCODE NWFAR NWPASCAL (*T_NWDSDelFilterToken)
   (Filter_Cursor_T NWFAR *, void (NWFAR *)(uint32, void NWFAR *));

/*****************************************************************************/
/*    NWAUDIT.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <nwaudit.h>

typedef int (*T_NWAddRecordToAuditingFile)
   (LONG, LONG, LONG, LONG, BYTE  *, LONG);

typedef int (*T_NWGetAuditingIdentity)
   (LONG *, BYTE *, char *);

typedef int (*T_NWSetAuditingIdentity)
   (LONG, BYTE *, char *);

/*****************************************************************************/
/*    NWCONN.H is the header associated with the following new functions     */
/*****************************************************************************/

#include <nwconn.h>

typedef int (*T_AttachByAddress)
   (BYTE, LONG, BYTE *, WORD *);

typedef int (*T_SetConnectionCriticalErrorHandler)
   (int(*)(int, int, int));

/*****************************************************************************/
/*    NWDIR.H is the header associated with the following new functions      */
/*****************************************************************************/

#include <nwdir.h>

typedef int (*T_NWGetExtendedVolumeInfo)
   (int, char *, NWVolExtendedInfo *);

/*****************************************************************************/
/*    NWENVRN1.H is the header associated with the following new functions   */
/*****************************************************************************/

#include <nwenvrn1.h>

typedef int (*T_GetConnectionsOpenFiles)
   (WORD, int *, int *, int, CONN_OPEN_FILES *, void *, int);

typedef int (*T_GetConnectionSemaphores)
   (WORD, int *, int *, int, CONN_SEMAPHORE *, void *, int);

typedef int (*T_GetConnectionsTaskInformation)
   (WORD, void **, void *, int);

typedef int (*T_GetConnectionsUsingFile)
   (int, void *, void *, int);

typedef int (*T_GetLogicalRecordInformation)
   (int, void *, void *, int);

typedef int (*T_GetLogicalRecordsByConnection)
   (WORD, WORD, void *, int);

typedef int (*T_GetPhysicalRecordLocksByFile)
   (int, void *, void *, int);

typedef int (*T_GetPhysRecLockByConnectAndFile)
   (int, void *, void *, int);

typedef int (*T_GetSemaphoreInformation)
   (int, void *, void *, int);

typedef int (*T_GetConnectionsUsageStats)
   (int, CONN_USAGE *);

typedef int (*T_GetDiskCacheStats)
   (DISK_CACHE_STATS *);

typedef int (*T_GetDiskChannelStats)
   (int, DISK_CHANNEL_STATS *);

typedef int (*T_GetDriveMappingTable)
   (DRIVE_MAP_TABLE *);

typedef int (*T_GetFileServerLANIOStats)
   (SERVER_LAN_IO *);

typedef int (*T_GetFileServerMiscInformation)
   (SERVER_MISC_INFO *);

typedef int (*T_GetFileSystemStats)
   (FILE_SYS_STATS *);

typedef int (*T_GetLANDriverConfigInfo)
   (BYTE, LAN_CONFIG *);

typedef int (*T_GetPhysicalDiskStats)
   (BYTE, PHYS_DISK_STATS *);

typedef int (*T_TTSGetStats)
   (TTS_STATS *, int, BYTE *);

typedef int (*T_GetPathFromDirectoryEntry)
   (BYTE, WORD, BYTE *, char *);

/*****************************************************************************/
/*    NWLOCALE.H is the header associated with the following new functions   */
/*****************************************************************************/

#include <nwlocale.h>

typedef char *(*T_NWIncrement)
   (char *, size_t);

typedef int (*T_NWLatoi)
   (char *);

typedef int (*T_NWLisalnum)
   (unsigned int);

typedef int (*T_NWLisalpha)
   (unsigned int);

typedef int (*T_NWLisdigit)
   (unsigned int);

typedef LCONV *(*T_NWLlocaleconv)
   (LCONV *);

typedef int (*T_NWLmblen)
   (char *, size_t);

typedef char *(*T_NWLsetlocale)
   (int, const char *);

typedef char *(*T_NWLstrchr)
   (char *, int);

typedef int (*T_NWLstrcoll)
   (char *, char *);

typedef size_t (*T_NWLstrcspn)
   (const char *, const char *);

typedef size_t (*T_NWLstrftime)
   (char *, size_t, char *, struct tm *);

typedef char *(*T_NWLstrpbrk)
   (char *, const char *);

typedef char *(*T_NWLstrrchr)
   (char *, int);

typedef char *(*T_NWLstrrev)
   (char *, char *);

typedef size_t (*T_NWLstrspn)
   (const char *, const char *);

typedef char *(*T_NWLstrstr)
   (char *, char *);

typedef char *(*T_NWLstrupr)
   (char *);

typedef size_t (*T_NWLstrxfrm)
   (char *, char *, size_t);

typedef char *(*T_NWPrevChar)
   (const char *, char *);

typedef int (*T_NWprintf)
   (char *, ...);

typedef int (*T_NWsprintf)
   (char *, char *, ...);

typedef char *(*T_NWstrImoney)
   (char *, NUMBER_TYPE);

typedef char *(*T_NWstrmoney)
   (char *, NUMBER_TYPE);

typedef int (*T_NWstrncoll)
   (char *, char *, size_t);

typedef char *(*T_NWstrncpy)
   (char *, char *, int);

typedef char *(*T_NWstrnum)
   (char *, NUMBER_TYPE);

typedef int (*T_NWvcprintf)
   (char *, va_list);

typedef int (*T_NWvfprintf)
   (FILE *, char *, va_list);

typedef int (*T_NWvprintf)
   (char *, va_list);

typedef int (*T_NWvsprintf)
   (char *, char *, va_list);

/*****************************************************************************/
/*    NWQUEUE.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <nwqueue.h>

typedef int (*T_NWQChangeJobQueue)
   (LONG, LONG, LONG, LONG *);

typedef int (*T_NWQServiceJob)
   (LONG, LONG, WORD *, NWQJobRec_t *, int *);

/*****************************************************************************/
/*    NWSERVST.H is the header associated with the following new functions   */
/*****************************************************************************/

#include <nwservst.h>

typedef LONG (*T_SSGetCacheInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetFileServerInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetFileSystemInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetUserInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetPacketBurstInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetIPXSPXInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetGarbageCollectionInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetCPUInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetVolumeSwitchInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetNLMLoadedList)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetNLMInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetDirCacheInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetOSVersionInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetActiveConnListByType)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetNLMResourceTagList)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetActiveLANBoardList)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetLANConfiguration)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetLANCommonCounters)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetLANCustomCounters)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetLSLInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetLSLLogicalBoardStats)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetMediaManagerObjInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetMediaManagerObjList)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetMediaManagerObjChildList)
   (LONG, LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetVolumeSegmentList)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetActiveProtocolStacks)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetProtocolConfiguration)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetProtocolStatistics)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetProtocolCustomInfo)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetProtocolNumbersByMedia)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetProtocolNumbersByLANBoard)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetMediaNameByNumber)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetLoadedMediaNumberList)
   (BYTE *, WORD);

typedef LONG (*T_SSGetRouterAndSAPInfo)
   (BYTE *, WORD);

typedef LONG (*T_SSGetNetRouterInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetNetworkRoutersInfo)
   (LONG, LONG, BYTE *, WORD);

typedef LONG (*T_SSGetKnownNetworksInfo)
   (LONG, BYTE *, WORD);

typedef LONG (*T_SSGetServerInfo)
   (LONG, BYTE, BYTE *, BYTE *, WORD);

typedef LONG (*T_SSGetServerSourcesInfo)
   (LONG, BYTE, BYTE *, BYTE *, WORD);

typedef LONG (*T_SSGetKnownServersInfo)
   (LONG, BYTE *, WORD);

/*****************************************************************************/
/*    PROCESS.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <process.h>

typedef int (*T_AddLanguage)
   (int, BYTE *, int);

typedef int (*T_ClearNLMDontUnloadFlag)
   (int);

typedef int (*T_GetCurrentOSLanguageID)
   (void);

typedef int (*T_GetNLMIDFromThreadID)
   (int, char *);

typedef int (*T_GetThreadContextSpecifier)
   (int);

typedef LONG (*T_GetThreadHandicap)
   (int);

typedef LONG (*T_LoadLanguageMessageTable)
   (char ***, LONG *, LONG *);

typedef int (*T_RenameLanguage)
   (int, BYTE *, int);

typedef int (*T_ReturnLanguageName)
   (int, BYTE *);

typedef int (*T_ScheduleWorkToDo)
   (void (*)(void *, WorkToDo *), void *, WorkToDo *);

typedef int (*T_SetCurrentOSLanguageID)
   (LONG);

typedef int (*T_SetNLMDontUnloadFlag)
   (int);

typedef int (*T_SetThreadContextSpecifier)
   (int, int);

typedef void (*T_SetThreadHandicap)
   (int, int);

typedef void (*T_ThreadSwitchLowPriority)
   (void);

/*****************************************************************************/
/*    TIME.H is the header associated with the following new functions       */
/*****************************************************************************/

#include <time.h>

typedef void (*T_GetClockStatus)
   (clockAndStatus);

/*****************************************************************************/
/*    UNICODE.H is the header associated with the following new functions    */
/*****************************************************************************/

#include <unicode.h>

typedef int (*T_NWLocalToUnicode)
   (void NWFAR *, unicode NWFAR *, size_t, char NWFAR *, unicode, size_t NWFAR *);

typedef int (*T_NWUnicodeToLocal)
   (void NWFAR *, char NWFAR *, size_t, unicode NWFAR *, char, size_t NWFAR *);

/*****************************************************************************/

#define _NEWIN400_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NEWIN400_H_INCLUDED  */

