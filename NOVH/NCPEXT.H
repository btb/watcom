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
****************************************************************************/

#ifndef _NCPEXT_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#define BEGIN_SCAN_NCP_EXTENSIONS    0xFFFFFFFF

#define REPLY_BUFFER_IS_FRAGGED      0xFFFFFFFF

#define MAX_NCP_EXTENSION_NAME_BYTES 33

#define CONNECTION_BEING_RESTARTED   0x01101001 
#define CONNECTION_BEING_KILLED      0x02202002 
#define CONNECTION_BEING_LOGGED_OUT  0x03303003 
#define CONNECTION_BEING_FREED       0x04404004 

typedef struct NCPExtensionClient NCPExtensionClient;

struct NCPExtensionClient {
   LONG connection;
   LONG task;
};

typedef struct FragElement FragElement;

struct FragElement {
   void *ptr;
   LONG size;
};

typedef struct NCPExtensionMessageFrag NCPExtensionMessageFrag;

struct NCPExtensionMessageFrag {
   LONG totalMessageSize;
   LONG fragCount;
   struct FragElement fragList[4];
};


int   NWDeRegisterNCPExtension(
         void *__queryData);

int   NWGetNCPExtensionInfo(
         const char *__NCPExtensionName,
         LONG *__NCPExtensionID,
         BYTE *__majorVersion,
         BYTE *__minorVersion,
         BYTE *__revision,
         void *__queryData);

int   NWGetNCPExtensionInfoByID(
         LONG __NCPExtensionID,
         char *__NCPExtensionName,
         BYTE *__majorVersion,
         BYTE *__minorVersion,
         BYTE *__revision,
         void *__queryData);

int   NWRegisterNCPExtension(
         const char *__NCPExtensionName,
         BYTE (*__NCPExtensionHandler)(
            struct NCPExtensionClient *__NCPExtensionClient,
            void *__requestData,
            LONG __requestDataLen,
            void *__replyData,
            LONG *__replyDataLen),
         void (*__ConnectionEventHandler)(
            LONG __connection,
            LONG __eventType),
         void (*__ReplyBufferManager)(
            struct NCPExtensionClient *__NCPExtensionClient,
            void *__replyBuffer),
         BYTE __majorVersion,
         BYTE __minorVersion,
         BYTE __revision,
         void **__queryData);

int   NWRegisterNCPExtensionByID(
         LONG __NCPExtensionID,
         const char *__NCPExtensionName,
         BYTE (*__NCPExtensionHandler)(
            struct NCPExtensionClient *__NCPExtensionClient,
            void *__requestData,
            LONG __requestDataLen,
            void *__replyData,
            LONG *__replyDataLen),
         void (*__ConnectionEventHandler)(
            LONG __connection,
            LONG __eventType),
         void (*__ReplyBufferManager)(
            struct NCPExtensionClient *__NCPExtensionClient,
            void *__replyBuffer),
         BYTE __majorVersion,
         BYTE __minorVersion,
         BYTE __revision,
         void **__queryData);

int   NWScanNCPExtensions(
         LONG *__NCPExtensionID,
         char *__NCPExtensionName,
         BYTE *__majorVersion,
         BYTE *__minorVersion,
         BYTE *__revision,
         void *__queryData);

int   NWSendNCPExtensionFraggedRequest(
         LONG __NCPExtensionID,
         const struct NCPExtensionMessageFrag *requestFrag,
         struct NCPExtensionMessageFrag *replyFrag);

int   NWSendNCPExtensionRequest(
         LONG __NCPExtensionID,
         const void *__requestData,
         LONG __requestDataLen,
         void *__replyData,
         LONG *__replyDataLen);

#define _NCPEXT_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NCPEXT_H_INCLUDED  */
