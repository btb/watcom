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

#ifndef _IPXSPX_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

/* ECB status field completion codes */
#define STS_SPX_CONNECTION_TERMINATED           0xFFEC
#define STS_SPX_TERMINATED_POORLY               0xFFED
#define STS_SPX_INVALID_CONNECTION              0xFFEE
#define STS_SPX_CONNECTION_TABLE_FULL           0xFFEF
#define STS_SPX_SOCKET_NOT_OPEN                 0xFFF0
#define STS_SPX_SOCKET_ALREADY_OPEN             0xFFF1
#define STS_SPX_ECB_CANNOT_BE_CANCELLED         0xFFF9
#define STS_SPX_NO_KNOWN_ROUTE_TO_DESTINATION   0xFFFA
#define STS_SPX_EVENT_CANCELLED                 0xFFFC
#define STS_SPX_PACKET_OVERFLOW                 0xFFFD
#define STS_SPX_MALFORMED_PACKET                0xFFFE
#define STS_SPX_TRANSMIT_FAILURE                0xFFFF
/*---------------------------------------------------------------------------*
 *                                                                           *
 *   IPX_ECB status field busy (in-process) codes:                           *
 *                                                                           *
 *   0x11 - AES (asynchronous event service) waiting                         *
 *   0x12 - Holding                                                          *
 *   0x13 - Session listen                                                   *
 *   0x14 - Processing                                                       *
 *   0x15 - Receiving                                                        *
 *   0x16 - Sending                                                          *
 *   0x17 - Waiting                                                          *
 *                                                                           *
 *--------------------------------------------------------------------------*/


typedef struct
   {
   unsigned long  network;   /* high-low */
   unsigned char  node[6];   /* high-low */
   unsigned short socket;    /* high-low */
   } InternetAddress;

typedef struct
   {
   void                   *fragAddress;
   unsigned long           fragSize;
   } ECBFrag;

/*---------------------------------------------------------------------------*
 *   The comment characters in the IPX_ECB structure have the                *
 *   following meanings                                                      *
 *   s - this field must be filled in prior to a send                        *
 *   r - this field must be filled in prior to a receive                     *
 *   R - this field is reserved                                              *
 *   A - this field may be used when the ECB is not in use by IPX/SPX        *
 *   q - the application may read this field                                 *
 *--------------------------------------------------------------------------*/
   
typedef struct IPX_ECBStruct
   {
   unsigned long           semHandleSave;       /* R */
   struct IPX_ECBStruct  **queueHead;           /* sr */
   struct IPX_ECBStruct   *next;                /* A */
   struct IPX_ECBStruct   *prev;                /* A */
   unsigned short          status;              /* q */
   unsigned long           semHandle;           /* sr (ignored for IpxSend) */
   unsigned short          lProtID;             /* R */
   unsigned char           protID [6];          /* R */
   unsigned long           boardNumber;         /* R */
   unsigned char           immediateAddress [6];/* s (IpxSend only) */
   unsigned char           driverWS [4];        /* R */
   unsigned long           ESREBXValue;         /* R */
   unsigned short          socket;              /* sr ignored if socket parm !=0 */
   unsigned short          protocolWorkspace;   /* R */
   unsigned long           dataLen;             /* q */
   unsigned long           fragCount;           /* sr */
   ECBFrag                 fragList [2];        /* sr */
   } IPX_ECB;

/* Packet type codes */
#define UNKNOWN_PACKET_TYPE               0
#define ROUTING_INFORMATION_PACKET        1
#define ECHO_PACKET                       2
#define ERROR_PACKET                      3
#define PACKET_EXCHANGE_PACKET            4
#define SEQUENCED_PACKET_PROTOCOL_PACKET  5

#pragma pack (1);
typedef struct
   {
   unsigned short          checksum;         /* hi-lo */
   unsigned short          packetLen;        /* hi-lo */
   unsigned char           transportCtl;
   unsigned char           packetType;
   unsigned long           destNet;          /* hi-lo */
   unsigned char           destNode[6];      
   unsigned short          destSocket;       /* hi-lo */
   unsigned long           sourceNet;        /* hi-lo */
   unsigned char           sourceNode[6];    
   unsigned short          sourceSocket;     /* hi-lo */
   } IPX_HEADER;

typedef struct          // included only for compatibility
   {
   char                    dummy;
   } IPX_STATS;

#define SPX_ECB   struct IPX_ECBStruct
#define ENABLE_WATCHDOG ((unsigned char) 0xFF)

typedef struct
   {
   unsigned short          checksum;         /* hi-lo */
   unsigned short          packetLen;        /* hi-lo */
   unsigned char           transportCtl;
   unsigned char           packetType;
   unsigned long           destNet;          /* hi-lo */
   unsigned char           destNode[6];      
   unsigned short          destSocket;       /* hi-lo */
   unsigned long           sourceNet;        /* hi-lo */
   unsigned char           sourceNode[6];    
   unsigned short          sourceSocket;     /* hi-lo */

   unsigned char           connectionCtl;
   unsigned char           dataStreamType;
   unsigned short          sourceConnectID;  /* hi-lo */
   unsigned short          destConnectID;    /* hi-lo */
   unsigned short          sequenceNumber;   /* hi-lo */
   unsigned short          ackNumber;        /* hi-lo */
   unsigned short          allocNumber;      /* hi-lo */
   } SPX_HEADER;

#define SPX_END_OF_MESSAGE    ((BYTE)0x10)

typedef struct SPX_ConnStruct
   {
   unsigned char           sStatus;
   unsigned char           sFlags;
   unsigned short          sSourceConnectID;             /* hi-lo */
   unsigned short          sDestConnectID;               /* hi-lo */
   unsigned short          sSequenceNumber;              /* hi-lo */
   unsigned short          sAckNumber;                   /* hi-lo */
   unsigned short          sAllocNumber;                 /* hi-lo */

   unsigned short          sRemoteAckNumber;             /* hi-lo */
   unsigned short          sRemoteAllocNumber;           /* hi-lo */

   unsigned short          sLocalSocket;                 /* lo-hi */
   unsigned char           sImmediateAddrees[6];

   unsigned long           sRemoteNet;                   /* hi-lo */
   unsigned char           sRemoteNode[6];               /* hi-lo */
   unsigned short          sRemoteSocket;                /* hi-lo */

   unsigned char           sRetransmitCount;
   unsigned char           sRetransmitMax;
   unsigned short          sRoundTripTimer;              /* lo-hi */
   unsigned short          sRetransmittedPackets;        /* lo-hi */
   unsigned short          sSuppressedPackets;           /* lo-hi */

   unsigned short          sLastReceiveTime;
   unsigned short          sLastSendTime;
   unsigned short          sRoundTripMax;
   unsigned short          sWatchdogTimeout;
   unsigned long           sSessionXmitQHead;
   unsigned long           sSessionXmitECBp;
   } SPX_SESSION;

/*  SPX_SESSION sStatus field codes: */
#define SPX_SSTATUS_ABORTED      0x00
#define SPX_SSTATUS_WAITING      0x01
#define SPX_SSTATUS_STARTING     0x02
#define SPX_SSTATUS_ESTABLISHED  0x03
#define SPX_SSTATUS_TERMINATING  0x04


int   IpxCheckSocket(
         unsigned short __socket);
int   IpxCancelEvent(
         IPX_ECB *ECBp );

#define IpxCancelPacket IpxCancelEvent

int   IpxCloseSocket(
         unsigned short __socket );

int   IpxConnect(
         IPX_ECB  *ECBp );

int   IpxDisconnect(
         IPX_ECB  *ECBp );

IPX_ECB *IpxGetAndClearQ(
         IPX_ECB **replyQptr );

#pragma aux IpxGetAndClearQ  =                                                \
      0x31 0xC0         /*  xor  eax, eax         ; zero EAX                */\
      0x87 0x02         /*  xchg [edx], eax       ; clear queue head and    */\
      parm [edx] value[eax];                   /* ;  get ptr to head ECB    */

IPX_ECB *IpxDelinkQ(
         IPX_ECB **replyQptr );

#pragma aux IpxDelinkQ =                                                      \
      0xFA              /* cli                    ; Q can be changed by ISR */\
      0x8B 0x02         /* mov  eax, [edx]        ; EAX - head ECB on Q     */\
      0x83 0x78 0x08 0  /* cmp  [eax].next, 0     ; only one ECB on Q?      */\
      0x74 0x0E         /* je   L1                ; yes                     */\
      0x8B 0x48 0x0C    /* mov  ecx, [eax].prev   ; ECX - tail ECB on Q     */\
      0x8B 0x51 0x0C    /* mov  edx, [ecx].prev   ; EDX - new tail ECB      */\
      0x89 0x50 0x0C    /* mov  [eax].prev, edx   ; update tail ptr         */\
      0x83 0xC2 0x08    /* add  edx, 8            ; EDX - ptr to tail.next  */\
      0x8B 0xC1         /* mov  eax, ecx          ; EAX - delinked ECB      */\
                        /* L1:                    ; clear out queuehead     */\
      0xC7 0x02 0 0 0 0 /* mov  dword ptr [edx],0 ;  or tail.next           */\
      0xFB              /* sti                    ; assumes interrupts      */\
                        /*                        ;  were initially enabled */\
      parm [edx] value [eax] modify [ecx];

int   IpxGetInternetworkAddress(
         unsigned char  *__address );

int   IpxGetLocalTarget(
         unsigned char  *__address,
         IPX_ECB        *__ECBp,
         unsigned long  *__timeToNet);

int   IpxGetStatistics( IPX_STATS *ipxStats );

int   IpxGetVersion(
         unsigned char  *majorVersion,
         unsigned char  *minorVersion,
         unsigned short *revision );

int   IpxOpenSocket(
         unsigned short *__socketP );

int   IpxReceive(
         unsigned short __socket,
         IPX_ECB       *__ECBp );

int   IpxResetStatistics(
         void );

int   IpxSend(
         unsigned short socket,
         IPX_ECB  *ECBp );

int   SpxAbortConnection(
         unsigned short __connection );

int   SpxCancelEvent(
         SPX_ECB *__ecb );

#define SpxCancelPacket SpxCancelEvent

int   SpxCheckSocket(
         unsigned short __socket );

int   SpxCloseSocket(
         unsigned short __socket );

int   SpxEstablishConnection(
         unsigned short __socket,
         SPX_ECB  *__ecb,
         unsigned char  __retryCount,
         unsigned char  __watchDogFlag,
         unsigned short *__connection );

int   SpxGetConfiguration(
         unsigned *__maxConn,
         unsigned *__availConn );

int   SpxGetConnectionStatus(
         unsigned short __connection,
         SPX_SESSION *__buffer       /* 56 bytes */ );

int   SpxGetTime(
         unsigned long *__marker );

int   SpxGetVersion(
         unsigned char *__major,
         unsigned char *__minor,
         unsigned short *__revision,
         unsigned long *__revDate );

int   SpxListenForConnection(
         unsigned short __socket,
         SPX_ECB *  __ecb,
         unsigned char  __retryCount,
         unsigned char  __watchDogFlag,
         unsigned short *__connection );

int   SpxListenForConnectedPacket(
         unsigned short __socket,
         SPX_ECB  *__ecb,
         unsigned short __connection );

int   SpxListenForSequencedPacket(
         unsigned short __socket,
         SPX_ECB  *__ecb );

int   SpxOpenSocket(
         unsigned short *__socket );

int   SpxSendSequencedPacket(
         unsigned short __connection,
         SPX_ECB  *__ecb );

int   SpxTerminateConnection(
         unsigned short __connection,
         SPX_ECB  *__ecb );

#define _IPXSPX_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _IPXSPX_H_INCLUDED  */
