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

#ifndef	_NWDSPART_HEADER_
#ifdef __cplusplus
extern "C" {
#endif
#define	_NWDSPART_HEADER_

#include "nwdstype.h"
#include "nwdsbuft.h"
#include "nwdsdc.h"

#ifdef __cplusplus
extern "C" {
#endif

NWDSCCODE NWFAR NWPASCAL NWDSAddPartition
(
	NWDSContextHandle	context,
	char	NWFAR *server,
	char	NWFAR *partitionRoot,
	int32	NWFAR *iterationHandle,
	uint8	more,
	Buf_T	NWFAR *objectInfo
);

NWDSCCODE NWFAR NWPASCAL NWDSAddReplica
(
	NWDSContextHandle	context,
	char		NWFAR *server,
	char		NWFAR *partitionRoot,
	uint32	replicaType
);

NWDSCCODE NWFAR NWPASCAL NWDSChangeReplicaType
(
	NWDSContextHandle	context,
	char	NWFAR *replicaName,
	char	NWFAR *server,
	uint32	newReplicaType
);

NWDSCCODE NWFAR NWPASCAL NWDSJoinPartitions
(
	NWDSContextHandle	context,
	char	NWFAR *subordinatePartition,
	uint32	flags
);

NWDSCCODE NWFAR NWPASCAL NWDSListPartitions
(
	NWDSContextHandle	context,
	int32		NWFAR *iterationHandle,
	char		NWFAR *server,
	Buf_T		NWFAR *partitions
);

NWDSCCODE NWFAR NWPASCAL NWDSRemovePartition
(
	NWDSContextHandle	context,
	char	NWFAR *partitionRoot
);

NWDSCCODE NWFAR NWPASCAL NWDSRemoveReplica
(
	NWDSContextHandle	context,
	char		NWFAR *server,
	char		NWFAR *partitionRoot
);

NWDSCCODE NWFAR NWPASCAL NWDSSplitPartition
(
	NWDSContextHandle	context,
	char	NWFAR *subordinatePartition,
	uint32	flags
);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
};
#endif
#endif  /* _NWDSPART_HEADER_ */
