/*
**   (c) 1993 Novell, Inc. All Rights Reserved.
**
**  THIS WORK IS SUBJECT TO U.S. AND INTERNATION COPYRIGHT LAWS AND
**  TREATIES. NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED,
**  COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED,
**  CONDENSED, EXPANDED, COLLECTED, COMPILED, LIINKED, RECAST,
**  TRANSFORMED OR ADAPTED WITHOUT THE PRIOR WRITTEN CONSENT OF
**  NOVELL. ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION
**  COULD SUBJECT THE PERPETRATOR TO CRIMINAL AND CIVAL LIABILITY.
*/

#ifndef __ASP__
#define __ASP__

#include <atp.h>

/* ASP error codes */
#define ASP_ERR_BADVERS     0xfbd6  /* Client/Server ASP version mismatch */
#define ASP_ERR_SERVBUSY    0xfbd1  /* ASP Server is busy (no GetSessions) */


/* Misc. ASP definitions */
#define ASP_PROTO_VERS      0x100   /* ASP protocol version */


/* Event list. These are the events that can come up the pike. */

/*    SSSS   L      SSSS
      S      L      S
      SSS    L      SSS
         S   L         S
      SSSS   LLLLL  SSSS             events

*/

/* When we receive a request for a connection on an open request, receive
** this event.
** No errors.
** U.OpenReq.addr - Adress of requestor
** U.OpenReq.id - ID used by protocol. Hand back in acceptance or rejection.
*/
#define ASP_EVENT_SLS_OPEN_REQ     2


/* If the client asked to reply to each status request individually,
** this event shows that a status request has come in. Please reply to it
** with ATAspSendStat.
** No errors.
** U.StatReq.addr - Adress or requestor. Pass back with reply.
*/
#define ASP_EVENT_SLS_STATUS_REQ   3

/* Returns that the SLS has been initialized on this descriptor, or returns
** an error as to why the initialization failed.
** pass.ret - Error - out of sockets, out of memory
** No Data.
*/
#define ASP_EVENT_SLS_INIT         4 

/* Returned if the set status command was in error.
** pass.ret - EINVAL, ENOBUFS
** No data.
*/
#define ASP_EVENT_SLS_SETSTAT      16

/* Sent up if the SendStat command failed.
** pass.ret - error - EINVAL, ENOBUFS
** pass->U.StatReq.addr - address that was being sent to
*/
#define ASP_EVENT_SLS_SENDSTAT     25

/* SLS connection has been summarily terminated. This is usually do
** to some kind of deadly fatal error. Please close the SLS.
** No return, no data.
*/
#define ASP_EVENT_SLS_CLOSE        99


/*    SSSS   SSSS   SSSS
      S      S      S
      SSS    SSS    SSS
         S      S      S
      SSSS   SSSS   SSSS events
*/
 
/* Received when the SSS receives a command request on the open session.
** Please reply.
** No errors.
** Nothing in the pass structure.
** Data of size ASP_MAXCMD maximum.
*/
#define ASP_EVENT_SSS_CMD_REQ      11

/* Received a write request. Please reply with a writecontinue request
** or write reply if no fastwrite, or this is just informational if fastwrite
** is in effect.
** No errors, nothing in Pass structure.
** Data - Includes the write request data. Max size CmdSize.
*/
#define ASP_EVENT_SSS_WRITE_REQ    12           /* datamp */

/* Rec'd a Write Continue reply. Please reply with a write reply.
** No errors.
** Data is the write data received, max size QuantumSize.
*/
#define ASP_EVENT_SSS_WRITECONT_REPLY 13        /* datamp */

/* Rec'd the acknoledgement of reply to an outstanding send_attention,
** or the Attention transaction timed out.
** Bad return code if unsuccessful.
** U.Attn.id - ID code that client passed in.
** No Data.
*/
#define ASP_EVENT_SSS_ATTN_REPLY      14        /* ret val */

/* Should be abolished in favor of the SSS_ATTN_REPLY.
** Was trying to send the Attn, but an error got in the way. The Attention
** request never made it out of the machine.
** Return Code - EINVAL, ENOBUFS.
** U.Attn.id - ID code that client passed in.
** No Data.
*/
#define ASP_EVENT_SSS_SND_ATTN        17

/* The SSS session has been closed. Please call SSS close.
** pass.ret - errors:
**     ESHUTDOWN - SLS that spawned this was closed.
**     ENETRESET - Network reconfigured under us.
**     0 - received a close request from remote endpoint.
**     ETIMEDOUT - No packets received for a long time, probably dead.
*/
#define ASP_EVENT_SSS_CLOSE           15

/* ASP_WReply was called, but I couldn't send the reply. Possible errors:
** pass.ret -
**     ECONNABORTED - this session is in the closed state.
**     EINVAL - Bad parameter, or bad state for this call.
**     ENOBUFS - not enough memory to send reply.
*/
#define ASP_EVENT_SSS_WRITE_REPLY 21

/* ASP_writecont requ was called, but I couldn't send the request. Possible errors:
** pass.ret -
**     EINVAL - Bad parameter, or bad state for this call.
**     ENOBUFS - Not enough memory to send request.
*/
#define ASP_EVENT_SSS_WRITECONT_REQ   22


/*
** ATAspPass structure. Used to get information from the protocol to the
** client, passed as part of the ATAspGet() function. Please refer to the
** above event definitions to find when you should look in the union.
*/


typedef struct ATAspPass {
     u_short     cmd;
     long        ret;
     union {
        struct Attn_s {
            short       attn_code;
            ATRetry_t  retry;
            u_long      id;
        } Attn;
        struct StatReq_s {
            ATInet_t    addr;
        } StatReq;
        struct OpenReq_s {
            ATInet_t    addr;
            u_long      id;
            u_short     fastwrite;
        } OpenReq;
   } U;
} ATAspPass_t ;



#ifdef __cplusplus
extern "C" {
#endif

extern int ATAspOpen (int *fd);
extern int ATAspClose (int fd);
extern int ATAspGet (int fd, ATAspPass_t *pass, char *buf, int *len);
extern int ATAspAttn (int fd, void *id, u_short attn, ATRetry_t *retry);
extern int ATAspCmdReply (int fd, u_long req_result, char *reply, int replylen);
extern int ATAspGetWorkstation (int fd, ATInet_t *addr);
extern int ATAspGetParms (int fd, int *maxcmd, int *quantum);
extern int ATAspRegisterCallback(int fd, void (*routine) (), void *opaque);
extern int ATAspSSSInit(int SSSfd, void *sss_id, ATInet_t *wss_addr, int fastwrite);
extern int ATAspSLSInit (int fd, int stat_flag);
extern int ATAspSetStat (int fd, char *buf, int len);
extern int ATAspSendStat (int fd, char *buf, int len, ATInet_t *addr);
extern int ATAspSLSReject (int fd, ATInet_t *addr, u_long ret_val);
extern int ATAspWCont (int fd, int len);
extern int ATAspWReply (int fd, u_long result, char *buf, int len);

#ifdef __cplusplus
}
#endif


#endif /* __ASP__ */

