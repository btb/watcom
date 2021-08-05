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


#ifndef __ATP_H__
#define __ATP_H__

#include <appletlk.h>


#define ATP_HDR_SIZE        8  /* Size of the ATP header */
#define ATP_DATA_SIZE       578  /* Maximum size of the ATP data area */


/* Timer values for XO release timers */
#define ATP_XO_DEF_REL_TIME   0
#define ATP_XO_30SEC          0
#define ATP_XO_1MIN           1
#define ATP_XO_2MIN           2
#define ATP_XO_4MIN           3
#define ATP_XO_8MIN           4



/*
** ATP event types
**
** When a atp_get returns, one of these functions is the event.
** Sends will occur when an error condition, like ETIMEDOUT, occurs.
**
*/

#define     ATP_EVENT_RCV_REQ 30
#define     ATP_EVENT_RCV_RSP 31
#define     ATP_EVENT_SND_REQ 32
#define     ATP_EVENT_SND_RSP 33


/* ATP passing structure
**
** This structure will be used by both the library routines and the
** streams functions. For STREAMS, the data will be held in the M_PROTO
** portion of a putmsg/getmsg message. For across the library boundry, the
** data will be pointed to by the structure.
**
** Brian Bulkowski, Novell Inc, 1991
**
*/



typedef struct ATAtpPass {

   u_short          event;
   int              ret;
   ATInet_t         at_addr;
   void             *TransID;
   u_char           xo;
   u_char           xo_relt;
   u_char           bitmap;
   u_char           packetize;
   ATRetry_t        retry;

   void             *data;
   u_short          data_len;

   u_long           userdata[8];
   u_short          packet_len[8];
      
} ATAtpPass_t;



#ifdef __cplusplus
extern "C" {
#endif

extern int ATAtpOpen(int *fd, ATSocket *socket);
extern int ATAtpClose(int fd);
extern int ATAtpGet (int fd, ATAtpPass_t *pass);
extern int ATAtpSendRsp (int fd, ATAtpPass_t *pass);
extern int ATAtpSendReq (int fd, ATAtpPass_t *pass);
extern int ATAtpCancelSendReq (int fd, void *TransID);
extern int ATAtpCancelRecvReq (int fd, void *TransID);

#ifdef __cplusplus
}
#endif


#endif /* __ATP__ */
