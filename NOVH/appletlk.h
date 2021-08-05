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


/* Miscellaneous definitions for AppleTalk used by all protocol 
 * modules.
 */

#ifndef __APPLETALK__
#define __APPLETALK__

#include <sys/types.h>


/* Miscellaneous types */

typedef u_short ATNet;          /* AppleTalk network number */
typedef u_char  ATNode;         /* AppleTalk node number */
typedef u_char  ATSocket;       /* AppleTalk socket number */


/* AppleTalk Internet Address */


typedef struct ATInet {
    ATNet     net;              /* Network Address */
    ATNode    node;             /* Node number */
    ATSocket  socket;           /* Socket number */
} ATInet_t;


/* at_retry
**
** Tells us how long to continue to retry a transaction.
** Interval is in 1/1000 of a sec.
** Retry is in packets, where -1 means infinite.
** Backoff is the backoff constant - 0 and up
**
** Used by ATP, ZIP and their minions
*/

typedef struct ATRetry {
    u_long     interval;        /* Retry interval in milli seconds */
    short      retries;         /* Maximum number of retries */
    u_char     backoff;         /* Retry backoff, must be 1 through 4 */
} ATRetry_t;


/* This define can be used to determine when AppleTalk is
** handing back a default zone.
*/
#define AT_DEFAULT_ZONE "*"

/* Throw away code. This structure is used in ZIP and routr_if in order
to pass the internal net zone list around, thus cheaply needed. Please
redesign and remove this blight... /bbb/ 6-10-91 */

#define AT_INF_RETRY    -1      /* Retry forever */



#ifdef __cplusplus
extern "C" {
#endif

extern int  appletalk_version(void);
extern int  ATAppletalkVersion(u_char *major, u_char *minor, u_char *revision);

extern char *CstrMacToIBMCP(char * dst, char * src);
extern char *PstrMacToIBMCP(char * dst, char * src);
extern char *CstrIBMCPToMac(char * dst, char * src);
extern char *PstrIBMCPToMac(char * dst, char * src);

#ifdef __cplusplus
}
#endif

#endif /* __APPLETALK__ */

