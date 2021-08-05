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
          
#ifndef _EXTATTR_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define CRITICAL_ATTRIBUTE_FLAG   0x00000080
#define RESERVED_FLAGS_MASK       0x0000FFFF
#define USER_FLAGS_MASK           0xFFFF0000

  /*------------------------------------------------------------------*
   * T_enumerateEAnoKey is the structure returned in the dataBuffer   *
   * by EnumerateEA if a empty key (or NULL) is specified.  The       *
   * EAsInReply output parameter tells how many T_enumerateEAnoKey    *
   * structures are in the dataBuffer.                                *
   *------------------------------------------------------------------*/
  
typedef struct
   {
   LONG  EALength;
   WORD  keyLength;
   LONG  accessFlags;
   char  key[1];      /* length of this field is given by keyLength */
   } T_enumerateEAnoKey;

  /*----------------------------------------------------------------------*
   * T_enumerateEAwithKey is the structure returned in the dataBuffer     *
   * by EnumerateEA if a non-empty key is specified.  In this case the    *
   * EAsInReply output parameter will return one and there will only be   *
   * one T_enumerateEAwithKey structure in the dataBuffer.                *
   *----------------------------------------------------------------------*/
typedef struct
   {
   LONG  EALength;
   WORD  keyLength;
   LONG  accessFlags;
   LONG  keyExtants;
   LONG  EAExtants;
   char  key[1];      /* length of this field is given by keyLength */
   } T_enumerateEAwithKey;

extern int CloseEA(int handle);

extern int CopyEA(     
         const char *__srcPath, 
         const char *__destPath,
         int         __destVolumeNumber,
         LONG        __destDirectoryNumber,
         LONG       *__EAcount,
         LONG       *__EAdataSize,
         LONG       *__EAkeySize );
                              
extern int EnumerateEA( 
         int         handle,
         const char *keyBuffer,
         BYTE       *dataBuffer,
         LONG        dataBufferSize,
         int         startPosition,
         LONG       *dataSize,
         LONG       *EAsInReply );

extern int GetEAInfo(   
         int   __handle,
         LONG *__totalEAs,
         LONG *__totalDataSizeOfEAs,
         LONG *__totalKeySizeOfEAs );
                 
extern int OpenEA(     
         const char *__path, 
         LONG        __reserved );
                 
extern int ReadEA(     
         int         __handle,
         const char *__keyBuffer,
         char       *__dataBuffer,
         LONG        __dataBufferSize,
         LONG       *__accessFlags );
                 
extern int WriteEA(    
         int         __handle,
         const char *__keyBuffer,
         const char *__dataBuffer,
         LONG        __dataBufferSize,
         LONG        __accessFlags );
                 
#define _EXTATTR_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _EXTATTR_H_INCLUDED */
