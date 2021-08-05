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

#ifndef _SAP_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwipxspx.h>
#include <nwtypes.h>

#define SAP_SOCKET               0x452

#define GENERAL_SERVICE_QUERY    1
#define GENERAL_SERVICE_RESPONSE 2
#define NEAREST_SERVICE_QUERY    3
#define NEAREST_SERVICE_RESPONSE 4
#define PERIODIC_ID_PACKET       2

#define NOT_SUPPORTED            1
#define INVALID_QUERY_TYPE       2


/*__________________________________________________________________________*/

typedef struct
 {                                        
    WORD             SAPPacketType;          /* 2 or 4 */
    WORD             serverType;             /* assigned by Novell */
    BYTE             serverName[48];         /* service name */
    InternetAddress  serverAddress;          /* server internetwork address */
    WORD             interveningNetworks;    /* # of networks packet must traverse */
 } T_SAP_ID_PACKET;

/*__________________________________________________________________________*/

typedef struct
 {
   WORD             queryType;               /* 1 or 3 */
   WORD             serverType;              /* assigned by Novell */
 } SERVICE_QUERY_PACKET;

/*__________________________________________________________________________*/

#define SAP_RESPONSES_PER_PACKET    8
#define QUERY_LIST_SIGNATURE        0x454C5253

typedef struct SAPResponse
 {
    WORD                SAPPacketType;       /* 2 or 4 */
    struct
     {
      WORD              serverType;          /* assigned by Novell */
      BYTE              serverName[48];      /* service name */
      InternetAddress   serverAddress;       /* server internetwork address */
      WORD              interveningNetworks; /* # of networks packet must traverse */
     }                  responses[SAP_RESPONSES_PER_PACKET];
    struct SAPResponse *next;
    LONG                signature;
    int                 count;
 } SAP_RESPONSE_LIST_ENTRY;
/*__________________________________________________________________________*/


LONG  AdvertiseService(
         WORD  __serviceType,
         char *__serviceName,
         WORD  __serviceSocket );

int   ShutdownAdvertising(
         LONG       __advertisingHandle );

SAP_RESPONSE_LIST_ENTRY *QueryServices(
         WORD  __queryType,
         WORD  __serviceType );

int   FreeQueryServicesList( 
         SAP_RESPONSE_LIST_ENTRY *__listP );

#define _SAP_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _SAP_H_INCLUDED  */
