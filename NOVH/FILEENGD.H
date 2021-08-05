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

#ifndef _FILEENGD_H_DEFINED
#ifdef __cplusplus
extern "C" {
#endif
#define _FILEENGD_H_DEFINED

#include <nwtypes.h>

  /*---------------------------------------------*
   * Values for flagBits parameter to FEcreat.   *
   * Valid flag bits when file is CREATED:       *
   *---------------------------------------------*/
#define  DELETE_FILE_ON_CREATE_BIT     0x0001
#define  NO_RIGHTS_CHECK_ON_CREATE_BIT 0x0002


  /*---------------------------------------------*
   * Values for flagBits parameter to FEsopen.   *
   * Valid flag bits when file is OPENED:        *
   *---------------------------------------------*/
#define  FILE_WRITE_THROUGH_BIT           0x00000040
#define  ENABLE_IO_ON_COMPRESSED_DATA_BIT 0x00000100
#define  LEAVE_FILE_COMPRESSED_DATA_BIT   0x00000200
#define  NO_RIGHTS_CHECK_ON_OPEN_BIT      0x00010000
#define  OK_TO_OPEN_DOS_FILE              0x80000000

  /*---------------------------------------*
   * Namespace and datastream constants    *
   *---------------------------------------*/
#define DOSNameSpace                    0
#define MACNameSpace                    1
#define NFSNameSpace                    2
#define FTAMNameSpace                   3
#define OS2NameSpace                    4
#define NTNameSpace                     5

#define NWDOS_NAME_SPACE   DOSNameSpace
#define NWMAC_NAME_SPACE   MACNameSpace
#define NWNFS_NAME_SPACE   NFSNameSpace
#define NWFTAM_NAME_SPACE  FTAMNameSpace
#define NWOS2_NAME_SPACE   OS2NameSpace
#define NWNT_NAME_SPACE    NTNameSpace

#define PrimaryDataStream               0
#define MACResourceForkDataStream       1
#define FTAMStructuringDataStream       2

  /*------------------------------*
   * Path parsing function type   *
   *------------------------------*/
typedef int (*T_PathParseFunc) ( const char *inputPath,
                                 WORD *connectionIDp,
                                 int  *volumeNumberP,
                                 LONG *directoryNumberP,
                                 BYTE *outPathStringP,
                                 LONG *outPathCountP );
            

  /*--------------*
   * Prototypes   *
   *--------------*/

extern int  CountComponents( 
         BYTE *__pathString, 
         int   __len );

extern int  FEConvertDirectoryNumber(      
         int    __sourceNameSpace,
         LONG   __volumeNumber,
         LONG   __sourceDirectoryNumber,
         int    __destinationNameSpace,
         LONG  *__destinationDirectoryNumberP );

extern int  FEcreat(           
         char  *__name,
         int    __permission,
         int    __flagBits );

extern int  FEFlushWrite(      
         int    __handle );

extern LONG FEGetCWDnum( 
         void );

extern LONG FEGetCWVnum( 
         void );

extern int  FEGetDirectoryEntry( 
         int    __volumeNumber,
         LONG   __directoryNumber,
         BYTE  *__pathString,
         LONG   __pathCount,
         int    __desiredNameSpace,
         void **__namespaceDirectoryStructPp,
         void **__DOSdirectoryStructPp );

extern int FEGetEntryVersion(
         int    __volumeNumber,
         LONG   __directoryNumber,
         BYTE  *__pathString,
         LONG   __pathCount,
         WORD   *__version);

extern LONG FEGetOriginatingNameSpace( 
         LONG __volumeNumber,
         LONG __directoryNumber );

extern int FEMapConnsHandleToVolAndDir(
         LONG  __connection,
         int   __handle,
         int  *__volumeNumberP,
         LONG *__directoryNumberP);

extern int  FEMapHandleToVolumeAndDirectory( 
         int    __handle,
         int   *__volumeNumberP,
         LONG  *__directoryNumberP );

extern int  FEMapPathVolumeDirToVolumeDir( 
         char  *__pathName,
         int    __volumeNumber,
         LONG   __directoryNumber,
         int   *__newVolumeNumberP,
         LONG  *__newDirectoryNumberP );

extern int  FEMapVolumeAndDirectoryToPath( 
         int    __volumeNumber,
         LONG   __directoryNumber,
         BYTE  *__pathString,
         LONG  *__pathCount );

extern int  FEMapVolumeNumberToName(       
         int    __volumeNumber,
         BYTE  *__volumeName );

extern int  FERegisterNSPathParser( 
         T_PathParseFunc __normalFunc );

extern LONG FESetCWDnum( 
         LONG __CWDnum );

extern LONG FESetCWVandCWDnums( 
         LONG __CWVnum, 
         LONG __CWDnum );

extern LONG FESetCWVnum( 
         LONG __CWVnum );

extern int  FEsopen(           
         char *__name,
         int   __access,
         int   __share,
         int   __permission,
         int   __flagBits,
         BYTE  __dataStream );

extern int GetDataStreamName( 
         int   __volume,
         BYTE  __dataStream,
         char *__name,
         int  *__numberOfDataStreams );

extern int GetNameSpaceName( 
         int   __volume,
         LONG  __nameSpace,
         char *__name,
         int  *__numberOfNameSpaces );

extern int NWGetDirBaseFromPath(char *path,
                         BYTE  nameSpace,
                         LONG  *volNum,
                         LONG *NSDirBase,
                         LONG *DOSDirBase);

extern BYTE SetCurrentNameSpace( 
         BYTE __newNameSpace );

extern BYTE SetTargetNameSpace( 
         BYTE __newNameSpace );

#pragma aux CountComponents =                   \
      0x33 0xd2  /*          xor     edx,edx */ \
      0x8b 0xc2  /*          mov     eax,edx */ \
      0xe3 0x0a  /*          jcxz    count   */ \
      0x03 0xce  /*          add     ecx,esi */ \
      0xac       /*  loop    lodsb           */ \
      0x42       /*          inc     edx     */ \
      0x03 0xf0  /*          add     esi,eax */ \
      0x3b 0xf1  /*          cmp     esi,ecx */ \
      0x72 0xf8  /*          jb      loop    */ \
                 /*  count                   */ \
      parm caller [esi] [ecx] value [edx] modify [eax];

#ifdef __cplusplus
};
#endif
#endif //_FILEENGD_H_DEFINED
