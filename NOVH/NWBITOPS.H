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

#ifndef _BITOPS_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
                                                              
#include <nwtypes.h>

void  BitClear(
          void *__bitArray,
          LONG __bitNumber );

void  BitSet(
          void *__bitArray,
          LONG __bitNumber );

LONG  BitTest(
          void *__bitArray,
          LONG __bitNumber );

LONG  BitTestAndClear(
          void *__bitArray,
          LONG __bitNumber );

LONG  BitTestAndSet(
          void *__bitArray,
          LONG __bitNumber );

LONG  ScanBits(
          void *__bitArray,
          LONG __startingBitNumber,
          LONG __totalBitCount);

LONG  ScanClearedBits(
          void *__bitArray,
          LONG __startingBitNumber,
          LONG __totalBitCount );


#define _BITOPS_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _BITOPS_H_INCLUDED  */
