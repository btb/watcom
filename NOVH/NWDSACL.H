#ifndef _NWDSACL_HEADER_
#ifdef __cplusplus
extern "C" {
#endif
#define _NWDSACL_HEADER_

#include "nwdstype.h"
#include "nwdsbuft.h"
#include "nwdsdc.h"

#ifdef __cplusplus
	extern "C" {
#endif

NWDSCCODE NWFAR NWPASCAL NWDSGetEffectiveRights
(
	NWDSContextHandle context,
	char	NWFAR *subjectName,
	char	NWFAR *objectName,
	char	NWFAR *attrName,
	uint32	NWFAR *privileges
);

NWDSCCODE NWFAR NWPASCAL NWDSListAttrsEffectiveRights
(
	NWDSContextHandle		context,
	char		NWFAR *objectName,
	char		NWFAR *subjectName,
	uint8		allAttrs,
	Buf_T		NWFAR *attrNames,
	int32		NWFAR *iterationHandle,
	Buf_T		NWFAR *privilegeInfo
);

#ifdef __cplusplus
	}
#endif

#ifdef __cplusplus
};
#endif
#endif

