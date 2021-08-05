#ifndef	_NWDSAUD_HEADER_
#ifdef __cplusplus
extern "C" {
#endif
#define	_NWDSAUD_HEADER_

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

#include "nwdstype.h"
#include "nwdsdc.h"

#ifdef __cplusplus
extern "C" {
#endif

NWDSCCODE NWFAR NWPASCAL NWDSAuditGetObjectID
(
	NWDSContextHandle context,
	char		NWFAR *objectName,
	int		NWFAR *connectionID,
	uint32	NWFAR *objectID
);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
};
#endif
#endif									/* #ifndef _NWDSAUD_HEADER_ */
