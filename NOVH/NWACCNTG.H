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

#ifndef _NWACCTNG_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

int   AccountingInstalled(
          WORD __fileServerID );

int   GetAccountStatus(
          WORD __binderyObjectType,
          char *__binderyObjectName,
          long *__balance,
          long *__limits,
          long *__holds );

int   SubmitAccountCharge(
          WORD __binderyObjectType,
          char *__binderyObjectName,
          WORD __serviceType,
          long __chargeAmount,
          long __cancelHoldAmount,
          WORD __commentType,
          char *__comment );

int   SubmitAccountChargeWithLength(
          WORD __binderyObjectType,
          char *__binderyObjectName,
          WORD __serviceType,
          long __chargeAmount,
          long __cancelHoldAmount,
          WORD __commentType,
          void *__comment,
          WORD commentLength);

int   SubmitAccountHold(
          WORD __binderyObjectType,
          char *__binderyObjectName,
          long __reserveAmount );


int   SubmitAccountNote(
          WORD __binderyObjectType,
          char *__binderyObjectName,
          WORD __serviceType,
          WORD __commentType,
          char *__comment);


#define _NWACCTNG_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWACCTNG_H_INCLUDED */
