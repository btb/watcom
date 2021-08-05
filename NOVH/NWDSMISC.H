#ifndef 	_NWDSMISC_HEADER_
#ifdef __cplusplus
extern "C" {
#endif
#define	_NWDSMISC_HEADER_
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

#include "nwdsbuft.h"
#include "nwdsdc.h"

#define DS_SYNTAX_NAMES		0
#define DS_SYNTAX_DEFS		1

#define DS_STRING					0x0001	/* string, can be used in names */
#define DS_SINGLE_VALUED		0x0002
#define DS_SUPPORTS_ORDER		0x0004
#define DS_SUPPORTS_EQUAL		0x0008
#define DS_IGNORE_CASE			0x0010	/* Ignore case 			*/
#define DS_IGNORE_SPACE			0x0020	/* Ignore white space 	*/
#define DS_IGNORE_DASH			0x0040	/* Ignore dashes 			*/
#define DS_ONLY_DIGITS			0x0080
#define DS_ONLY_PRINTABLE		0x0100
#define DS_SIZEABLE				0x0200

#ifdef __cplusplus
	extern "C" {
#endif

NWDSCCODE NWFAR NWPASCAL NWDSCloseIteration
(
 	NWDSContextHandle	context,
	int32					iterationHandle,
	uint32				operation
);

NWDSCCODE NWFAR NWPASCAL NWDSGetSyntaxID
(
	NWDSContextHandle context, 
	char NWFAR *attrName, 
	uint32 NWFAR *syntaxID
);

NWDSCCODE NWFAR NWPASCAL NWDSReadSyntaxes
(
	NWDSContextHandle	context,
	uint32	infoType,
	uint8		allSyntaxes,
	Buf_T		NWFAR *syntaxNames,
	int32		NWFAR *iterationHandle,
	Buf_T		NWFAR *syntaxDefs
);

NWDSCCODE NWFAR NWPASCAL NWDSReplaceAttrNameAbbrev
(
	NWDSContextHandle context,
	char NWFAR *inStr, 
	char NWFAR *outStr
);

NWDSCCODE NWFAR NWPASCAL NWDSGetObjectHostServerAddress
(
	NWDSContextHandle context,
	char NWFAR *objectName,
	char NWFAR *serverName,
	Buf_T NWFAR *netAddresses
);

void NWFAR NWPASCAL NWGetNWNetVersion
(
	uint8 NWFAR *majorVersion,
   uint8 NWFAR *minorVersion,
	uint8 NWFAR *revisionLevel,
   uint8 NWFAR *betaReleaseLevel 
);

NWDSCCODE NWFAR NWPASCAL NWIsDSServer
(
	NWCONN_ID		serverHandle,
	char NWFAR 		*treeName
);

NWDSCCODE NWFAR NWPASCAL NWDSGetBinderyContext
(
	NWDSContextHandle	context,
	int					serverHandle, 
	uint8 NWFAR			*BinderyEmulationContext
);

NWDSCCODE NWFAR NWPASCAL NWDSRepairTimeStamps
(
	NWDSContextHandle	context,
	char NWFAR *partitionRoot
);

int	NWFAR NWPASCAL NWGetFileServerUTCTime
(
	int serverHandle,
	uint32 NWFAR *time
);


#ifdef __cplusplus
	}
#endif

#ifdef __cplusplus
};
#endif
#endif
