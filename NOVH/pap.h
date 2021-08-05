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

#ifndef __PAP__
#define __PAP__

#include <appletlk.h>


#define PAP_DATA_SIZE   512    /* Max PAP Data size */
#define PAP_STATUS_SIZE 255    /* Max PAP status length */

/* List of pap events that could come up in a pap_get */

/* Rc'd close conn, sent response, nothing to do but close */
/* No data comes up */
#define PAP_EVENT_CLOSECONN_REQ     4  

/* Rc'd when reponse to a previous getstat request comes in.
   If pass.ret, then an error occured. Don't assume the request completed.
    U.GetStat.id - ID the requestor sent down
    U.GetStat.addr - Adress that the request was made of 
*/
#define PAP_EVENT_GETSTAT_REPLY     1

/* SLS has been inited and is now ready to accept everything.
** Could return allocation errors and no socket errors. No data.
*/
#define PAP_EVENT_SLS_INIT          21

/* Received as companion to pap_connect. Says that the WSS connection
   has been established or failed.
    Memory allocation failure, socket allocation failure.
    pass.ret returns errors that happened locally
    Data: U.ConnReply.result - result code from remote machine - 0 is sucess
    pap_get data is filled with the status message from remote end - 255 bytes max 
*/
#define PAP_EVENT_OPENSESS_REPLY    2

/* Rec'd data from remote endpoint.
** pass.ret returns local errors.
** U.Data.eof - returns if an EOF was sent with this transaction.
** pap_get data is filled with data sent. Max PAP_DATA_SIZE*8.
** Data could be of length 0, which would indicate a 0 length transaction.
** Transactions are never coalessed.
*/
#define PAP_EVENT_DATA              3 

/* Rec'd when an SSS or WSS dies. Could be for a number of reasons.
** Examples: Tickle timeout. SLS is closed, closing all SSS.
** Protocol stack becomes unbound or reconfigured from the network.
** The error fields will be 0, no data.
*/
#define PAP_EVENT_CONN_DIED         13

/* Rec'd on an SLS. Indicates that a request for Connection made it
** through the fairness arbitration and GetNextJob stuff.
** Accept or reject it.
** Data - 
** U.ConnReq.addr - Adress that the request came in on. Use for deciding to reject/accept, and pass in to accept/reject.
** U.ConnReq.id - ID of the request, hand back to reject/accept.
*/
#define PAP_EVENT_OPENSESS_REQ      15 /* Receive on SLS when OpenSess comes in */


/* pap_disconn was called, and now all data has been delivered and the
** close transaction has been completed, all gracefully. Please to close
** the file descriptor.
** No Data.
*/
#define PAP_EVENT_DISCONN           17 /* Pap disconnect has completed */



/* List of flags for SLS SetStatus. */
#define PAP_FLAG_GETSTAT_STATUS     1 /* For responding to GetStatus requests */
#define PAP_FLAG_OC_FAILED_STATUS   2 /* For sucessful OpenConn requests */


/*  ATPapPass structure
**
** Passed in and returned with the ATPapGet() function. Refer to the above
** descriptions of the events to determine which fields are valid for which
** events.
*/

typedef struct ATPapPass_s {
    u_short  cmd;
    long     ret;
    union {
        struct ConnReq_s {
            ATInet_t    addr;
            void        *id;
        } ConnReq;
        struct Data_s {
            u_char      eof;
        } Data;
        struct ConnReply_s {
            u_short     result;
        } ConnReply;
        struct GetStat_s {
            ATInet_t    addr;
            ATRetry_t   retry;
            void        *id;
        } GetStat;
   } U;
} ATPapPass_t ;



#ifdef __cplusplus
extern "C" {
#endif

extern int ATPapOpen(int *fd);
extern int ATPapClose(int fd);
extern int ATPapGetStatus(int fd, ATInet_t *addr, ATRetry_t *retry, void *id);
extern int ATPapConnect(int fd, ATInet_t *addr, u_short waittime_waited, int retry_time);
extern int ATPapDisconnect (int fd);
extern int ATPapSLInit(int fd);
extern int ATPapSetStatus(int fd, u_short flag, u_short status_len, char *status);
extern int ATPapGetNextJob(int fd, int num_jobs);
extern int ATPapReject (int fd, void *connect_id, ATInet_t *addr, 
    char *status,u_short status_len);
extern int ATPapAccept (int fd, void *connect_id, ATInet_t *addr, 
    char *status,u_short status_len);
extern int ATPapFindClient (int fd, ATInet_t *addr);
extern int ATPapWrite(int fd, char *data, int *data_len, u_char flush, u_char eof, u_char eot);
extern int ATPapGet(int fd, ATPapPass_t *pass, char *buf, int *len);

#ifdef __cplusplus
}
#endif


#endif /* __PAP__ */
