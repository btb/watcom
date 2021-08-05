/****************************************************************************
 *
 * (C) Unpublished Copyright of Novell, Inc.  All Rights Reserved.
 *
 * No part of this file may be duplicated, revised, translated, localized
 * or modified in any manner or compiled, linked or uploaded or downloaded
 * to or from any computer system without the prior written permission of
 * Novell, Inc.
 *
 ****************************************************************************/

#ifndef	_NWDSDSA_HEADER_
#ifdef __cplusplus
extern "C" {
#endif
#define	_NWDSDSA_HEADER_

#include "nwdstype.h"
#include "nwdsbuft.h"
#include "nwdsdc.h"

#ifdef __cplusplus
extern "C" {
#endif

NWDSCCODE NWFAR NWPASCAL	NWDSAddObject
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	int32		NWFAR *iterationHandle,
	uint8		more,
	Buf_T		NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSBackupObject
(
	NWDSContextHandle		context,
	char	NWFAR *objectName,
	int32	NWFAR *iterationHandle,
	Buf_T	NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSCompare
(
	NWDSContextHandle		context,
	char	NWFAR *object,
	Buf_T	NWFAR *buf,
	uint8	NWFAR *matched
);

/*-----------------------------------------------------------------------------
 *		In the case that objectName is a partition root, the partitionRootObject
 *		is the same as the objectName
 */

NWDSCCODE NWFAR NWPASCAL	NWDSGetPartitionRoot
(
 	NWDSContextHandle	context,
	char	NWFAR *objectName,
	char	NWFAR *partitionRoot
);

NWDSCCODE NWFAR NWPASCAL NWDSList
(
	NWDSContextHandle		context,
	char		NWFAR *object,
	int32		NWFAR *iterationHandle,
	Buf_T		NWFAR *subordinates
);

NWDSCCODE NWFAR NWPASCAL NWDSMapIDToName
(
	NWDSContextHandle		context,
	int		connID,
	uint32	objectID,
	char		NWFAR *object
);

NWDSCCODE NWFAR NWPASCAL NWDSMapNameToID
(
	NWDSContextHandle		context,
	int		connID,
	char		NWFAR *object,
	uint32	NWFAR *objectID
);

NWDSCCODE NWFAR NWPASCAL NWDSModifyObject
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	int32		NWFAR *iterationHandle,
	uint8		more,
	Buf_T		NWFAR *changes
);

NWDSCCODE NWFAR NWPASCAL NWDSModifyDN
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	char		NWFAR *newDN,
	uint8		deleteOldRDN
);

NWDSCCODE NWFAR NWPASCAL NWDSModifyRDN
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	char		NWFAR *newDN,
	uint8		deleteOldRDN
);

NWDSCCODE NWFAR NWPASCAL NWDSMoveObject
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	char		NWFAR *destParentDN,
	char		NWFAR	*destRDN
);

NWDSCCODE NWFAR NWPASCAL NWDSRead
(
	NWDSContextHandle		context,
	char		NWFAR *object,
	uint32	infoType,
	uint8	   allAttrs,
	Buf_T		NWFAR *attrNames,
	int32		NWFAR *iterationHandle,
	Buf_T		NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSReadObjectInfo
(
	NWDSContextHandle					context,
	char					NWFAR *object,
	char					NWFAR *distinguishedName,
	Object_Info_T		NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSRemoveObject
(
	NWDSContextHandle		context,
	char		NWFAR *object
);

NWDSCCODE NWFAR NWPASCAL NWDSRestoreObject
(
	NWDSContextHandle		context,
	char	NWFAR *objectName,
	int32	NWFAR *iterationHandle,
	uint8 more,
	uint32 size,
	uint8	NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSSearch
(
	NWDSContextHandle		context,
	char		NWFAR *baseObjectName,
	int		scope,
	uint8		searchAliases,
	Buf_T		NWFAR *filter,
	uint32	infoType,
	uint8		allAttrs,
	Buf_T		NWFAR *attrNames,
	int32		NWFAR *iterationHandle,
	int32		countObjectsToSearch,
	int32		NWFAR *countObjectsSearched,
	Buf_T		NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSOpenStream
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	char		NWFAR *attrName,
	uint32	flags,
	int		NWFAR *fileHandle
);

NWDSCCODE NWFAR NWPASCAL NWDSWhoAmI
(
 	NWDSContextHandle	context,
	char	NWFAR *objectName
);

NWDSCCODE NWFAR NWPASCAL NWDSGetServerDN
(
	NWDSContextHandle context,
	int connID, 
	char NWFAR *serverDN
);
						
NWDSCCODE NWFAR NWPASCAL NWDSGetServerAddresses
(
	NWDSContextHandle context,
	int connID, 
	uint32 NWFAR *countNetAddress, 
	Buf_T NWFAR *netAddresses
);
						


#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
};
#endif
#endif									/* #ifndef _NWDSDSA_HEADER_ */

