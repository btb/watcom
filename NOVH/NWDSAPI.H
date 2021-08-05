#ifndef   __NWDSAPI_H__
#ifdef __cplusplus
extern "C" {
#endif
#define   __NWDSAPI_H__
/*==============================================================================
 = (C) Unpublished Copyright of Novell, Inc.  All Rights Reserved.
 =
 = No part of this file may be duplicated, revised, translated, localized or
 = modified in any manner or compiled, linked or uploaded or downloaded to or
 = from any computer system without the prior written permission of Novell, Inc.
 ===============================================================================
 = This version of NWNET.H is specifically for use under NetWare 386 with the
 = Directory Services API library, 'DSAPI.NLM.' It should be included by users
 = of this library before any other includes prefixed with 'NWDS.'
 ===============================================================================
*/
#define NWFAR
#define NWPASCAL
#define NWDSCCODE      int

#include <NWAlias.h>

#ifndef   __NWDSTYPE_H
# include <NWDSType.h>
#endif

#ifndef   __NWDSDEFS_H
# include <NWDSDefs.h>
#endif

#ifndef   __NWDSERR_H
# include <NWDSErr.h>
#endif

#ifndef   _NWDSNAME_HEADER_
# include <NWDSName.h>
#endif

#ifndef   _NWDSFILT_HEADER_
# include <NWDSFilt.h>
#endif

#ifndef   _NWDSMISC_HEADER_
# include <NWDSMisc.h>
#endif

#ifndef   _NWDSACL_HEADER_
# include <NWDSACL.h>
#endif

#ifndef   _NWDSAUD_HEADER_
# include <NWDSAud.h>
#endif

#ifndef   _NWDSDSA_HEADER_
# include <NWDSDSA.h>
#endif

#ifndef   _NWDSSCH_HEADER_
# include <NWDSSch.h>
#endif

#ifndef   _NWDSATTR_HEADER_
# include <NWDSAttr.h>
#endif

#ifndef   _NWDSASA_HEADER_
# include <NWDSASA.h>
#endif

#ifndef   _NWDSPART_HEADER_
# include <NWDSPart.h>
#endif

#ifndef   _NWDSBUFT_HEADER_
# include <NWDSBufT.h>
#endif

#ifndef   __NAMES_H
# include <NWDSNMTP.h>
#endif

#ifndef   _UNICODE_HEADER_
# include <Unicode.h>
#endif

#ifdef __cplusplus
};
#endif
#endif
