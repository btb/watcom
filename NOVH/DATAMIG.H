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

#ifndef _DATAMIG_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define	ERR_INVALID_SUPPORT_MODULE_ID				240
#define	ERR_SUPPORT_MODULE_ALREADY_REGISTERED	241
#define	ERR_SUPPORT_MODULE_CREATE_FAILED			242
#define	ERR_SUPPORT_MODULE_CLOSE_FAILED			243
#define	ERR_SM_WRITE_NO_SPACE						244
#define	ERR_SM_WRITE_IO_ERROR						245
#define	ERR_SM_READ_IO_ERROR							246
#define	ERR_SUPPORT_MODULE_OPEN_FAILED			247
#define	ERR_SUPPORT_MODULE_DELETE_FAILED			248

#define	MaximumNumberOfDataStreams					3

/*
typedef struct
{
	LONG rIOStatus;
	LONG rInfoBlockSize;
	LONG rAvailSpace;
	LONG rUsedSpace;
	BYTE rSMString;
} Info0Rep;

typedef struct
{
	LONG rSMRegs;
} Info1Rep;

typedef struct
{
	BYTE NameLength; 
} Info2Rep;
*/

typedef  struct {
	LONG	IOStatus;
	LONG	InfoBlockSize;
	LONG	AvailSpace;
	LONG	UsedSpace;
	BYTE	SMString;	/* 128 length limit, Info block follows string */
} SUPPORT_MODULE_INFO;



LONG	NWDeRegisterDMSupportModule(
		LONG	SupportModuleID,
		BYTE	*SupportModuleName,
		LONG	SlotNumber);

LONG NWDeRegisterRTDataMigrationNLM(
		LONG Station,
		BYTE *DMTAG,
		LONG ForceFlag);

/* Local and Remote Call */
void	NWGetDataMigratorInfo(
		LONG *DMPresentFlag,
		LONG *majorVersion,
		LONG *minorVersion,
		LONG *numberOfSupportModules);

/* Local and Remote call */
LONG	NWGetDefaultSupportModule(
		LONG *defaultSupportModuleID);
			
/* Local and Remote call */
LONG	NWGetDMFileInfo(
		char *path,
		LONG nameSpace,
		LONG *supportModuleID,
		LONG *validDataStreams,
		LONG *estRetrievalTime,
		LONG *info);

/* Local and Remote call */
LONG	NWGetDMVolumeInfo(
		LONG volume,
		LONG supportModuleID,
		LONG *numberOfFilesMigrated,
		LONG *totalMigratedSize,
		LONG *spaceUsed,
		LONG *limboUsed,
		LONG *spaceMigrated,
		LONG *filesLimbo);
				
/* Local and Remote call */
LONG	NWGetSupportModuleInfo(
		LONG informationLevel,
		LONG supportModuleID,
		void *returnInfo,
		LONG *returnInfoLen);

LONG	NWIsDataMigrationAllowed( LONG Volume);

/* Local and Remote call */
LONG	NWMoveFileFromDM(
		char *path,
		LONG nameSpace);
/* Local and Remote call */

LONG	NWMoveFileToDM(
		char *path,
		LONG nameSpace,
		LONG SupportModuleID,
		LONG flags);

LONG	NWPeekFileData(
		char *path,
		LONG nameSpace,
		LONG noWaitFlag,
		LONG startingSector,
		LONG sectorsToRead,
		BYTE *buffer,
		LONG *sectorsRead,
		LONG *bytesRead,
		LONG *NoWaitReason);

LONG	NWRegisterDMSupportModule(
		LONG	ioFlag,
		LONG	(*addr[])(),
		BYTE	*SupportModuleName,
		LONG	SupportModuleID,
		LONG	MaxSectorsXF,
		LONG	*SlotNumber);

LONG NWRegisterRTDataMigrationNLM(
		LONG Station,
		LONG	(*addr[])(),
		BYTE *DMTAG,
		LONG majorVersion,
		LONG minorVersion);

/* Local and Remote call */
LONG	NWSetDefaultSupportModule(
		LONG newSupportModuleID,
		LONG *currentSupportModuleID);
			

#define _DATAMIG_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _DATAMIG_H_INCLUDED  */
