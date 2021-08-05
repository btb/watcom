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


#ifndef __NBP__
#define __NBP__

#include <atp.h>        /* For the retry structure */


/* Protocol defaults */

#define NBP_RETRY_COUNT         2            /* Maximum repeats */
#define NBP_RETRY_INTERVAL      2000         /* Retry timeout */


/* Special (partial) wildcard character */
#define NBP_SPL_WILDCARD    0xC5
#define NBP_ORD_WILDCARD    0x3D


/* NVE strings */
#define NBP_NVE_STR_SIZE    32    /* Maximum NBP tuple string size WO len byte!!! */


typedef struct ATNvestr {
    u_char      len;
    u_char      str[NBP_NVE_STR_SIZE];
} ATNvestr_t;



/* Entity Name */

typedef struct ATEntity {
    ATNvestr_t    object;
    ATNvestr_t    type;
    ATNvestr_t    zone;
} ATEntity_t;



/* Packet definitions */

#define NBP_TUPLE_SIZE  99  /* 3 for field lengths + 3*32 for three names */
#define NBP_TUPLE_MAX   15  /* Maximum number of tuples in one DDP packet */
#define NBP_HDR_SIZE    2


typedef struct ATNbptuple {
    ATInet_t   enu_addr;
    union {
      struct {
         u_char      enumerator;
         ATEntity_t  entity;
      } en_se;
      struct {
            u_char   enumerator;
            u_char   name[NBP_TUPLE_SIZE];
      } en_sn;
    } en_u;
} ATNbptuple_t;



/* Some macros for easier access to the tuple union */
#define enu_enum    en_u.en_sn.enumerator
#define enu_name    en_u.en_sn.name
#define enu_entity  en_u.en_se.entity


#ifdef __cplusplus
extern "C" {
#endif

extern int ATNbpLookup (ATEntity_t *entity, ATNbptuple_t *buf, int *max, 
    ATRetry_t *retry, int *more);
extern int ATNbpDirectedLookup (ATEntity_t *entity, ATInet_t *addr,
    ATNbptuple_t *buf, int *max, ATRetry_t *retry, int *more);
extern int ATNbpConfirm (ATEntity_t *entity, ATInet_t *dest, ATRetry_t *retry);
extern int ATNbpMakeEntity (ATEntity_t *entity, 
    char *obj, char *type, char *zone);
extern int ATNbpParseEntity (ATEntity_t *entity, char *str);
extern int ATNbpRegister (ATEntity_t *entity, int fd, ATRetry_t *retry);
extern int ATNbpRegByAddr (ATEntity_t *entity, ATInet_t *addr, ATRetry_t *retry);
extern int ATNbpRemove (ATEntity_t *entity, int fd);
extern int ATNbpRemoveByAddr (ATEntity_t *entity, ATSocket socket);
extern int ATNbpMakeEntityXlate (ATEntity_t *entity, 
    char *obj, char *type, char *zone);

#ifdef __cplusplus
}
#endif

#endif /* __NBP__ */
