#ifndef	_NWDSNAME_HEADER_
#ifdef __cplusplus
extern "C" {
#endif
#define	_NWDSNAME_HEADER_

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

NWDSCCODE NWFAR NWPASCAL NWDSAbbreviateName
(
	NWDSContextHandle	context,
	char	NWFAR *inName,
	char	NWFAR *abbreviatedName
);

NWDSCCODE NWFAR NWPASCAL NWDSCanonicalizeName
(
	NWDSContextHandle	context,
	char	NWFAR *objectName,
	char	NWFAR *canonName
);

NWDSCCODE NWFAR NWPASCAL NWDSRemoveAllTypes
(
	NWDSContextHandle	context,
	char	NWFAR *name,
	char	NWFAR *typelessName
);

#ifdef __cplusplus
	}
#endif

#ifdef __cplusplus
};
#endif
#endif									/* #ifndef _NWDSNAME_HEADER_ */

