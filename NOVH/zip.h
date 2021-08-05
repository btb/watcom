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


#ifndef __ZIP__
#define __ZIP__

/* Definitions for ZIP, per AppleTalk Zone Information Protocol
 * documentation from `Inside AppleTalk', July 14, 1986.
 */

#include <nbp.h>



#ifdef __cplusplus
extern "C" {
#endif

extern int ATZipGetLocalZones (int *start, ATNvestr_t *zones, int *z_size, 
    int *last, ATInet_t *router);
extern int ATZipGetMyZone (ATNvestr_t *zone);
extern int ATZipGetZoneList (int *start, ATNvestr_t *zones, int *z_size, 
    int *last, ATInet_t *router);
extern int ATZipGetNBPZones(ATNvestr_t *zones, int *z_size, int *more);
extern void ATZipZoneXlate(ATNvestr_t *zones, int z_size);

#ifdef __cplusplus
}
#endif


#endif /* __ZIP__ */
