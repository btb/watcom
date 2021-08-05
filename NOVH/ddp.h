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

#ifndef __DDP__
#define __DDP__

#include <appletlk.h>

/* TLI option structure for DDP */

typedef struct ATDdpOpt {
    u_short  checksum;      /* optional */
    u_char   ddp_type;      /* required */
    char     major;         /* a read-only option */
    char     minor;         /* a read-only option */
    char     revision;      /* a read-only option */
} ATDdpOpt_t;


/* Header and data sizes */

#define  DDP_HDR_SIZE                 5  /* DDP (short) header size */
#define  DDP_X_HDR_SIZE              13  /* DDP extended header size */
#define  DDP_DATA_SIZE              586  /* Maximum DataGram data size */
#define  DDP_DATAGRAM_SIZE          599  /* Maximum DataGram size */


/* DDP socket definitions */

#define  DDP_SOCKET_FIRST_RESERVED    1    /* First socket in reserved range*/
#define  DDP_SOCKET_FIRST_DYNAMIC   128  /* First socket in dynamic range */
#define  DDP_SOCKET_LAST            254  /* Last socket in any range */


/* DDP extended header packet format */

/* These defines are true only for the 386 processor - little endian */

typedef struct {
    u_short    length_hi2:2,
               hopcount:4,
               unused:2,
               length_lo8:8;
    u_short    checksum;    /* Checksum */
    ATNet     dst_net;      /* Destination network number */
    ATNet     src_net;      /* Source network number */
    ATNode    dst_node;     /* Destination node ID */
    ATNode    src_node;     /* Source node ID */
    ATSocket  dst_socket;   /* Destination socket number */
    ATSocket  src_socket;   /* Source socket number */
    u_char    type;         /* Protocol type */
    char      data[DDP_DATA_SIZE];
} ATDdp_t;


/*
 * macros to access the ddp length value in the packet
 */

#define DDP_LENGTH(ddp) ( ((ATDdp_t*)(ddp))->length_hi2<<8 | \
                              ((ATDdp_t*)(ddp))->length_lo8 )
#define SET_DDP_LENGTH(ddp,len) { unsigned short _len = (len); \
                              ((ATDdp_t*)(ddp))->length_hi2 = _len>>8; \
                              ((ATDdp_t*)(ddp))->length_lo8 = _len; }


/* DDP interface prototypes */

#ifdef __cplusplus
extern "C" {
#endif

extern int ATDdpOpen(int *);
extern int ATDdpClose(int);
extern int ATDdpRead(int fd, ATDdp_t *ddp, int *len);
extern int ATDdpWrite(int fd, ATDdp_t *ddp, long len);
extern int ATDdpRegisterListener(int, ATInet_t *);
extern int ATDdpDeregisterListener(int, ATSocket);
extern int ATDdpNetinfo(int fd, ATInet_t *node, ATInet_t *router, int *flags);

#ifdef __cplusplus
}
#endif


#endif /* __DDP__ */

