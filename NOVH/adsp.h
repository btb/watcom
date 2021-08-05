/*
**	(c) 1993 Novell, Inc. All Rights Reserved.
**
**	THIS WORK IS SUBJECT TO U.S. AND INTERNATIONAL COPYRIGHT LAWS AND
**	TREATIES. NO PART OF THIS WORK MAY BE USED, PRACTICED, PERFORMED,
**	COPIED, DISTRIBUTED, REVISED, MODIFIED, TRANSLATED, ABRIDGED,
**	CONDENSED, EXPANDED, COLLECTED, COMPILED, LIINKED, RECAST,
**	TRANSFORMED OR ADAPTED WITHOUT THE PRIOR WRITTEN CONSENT OF
**	NOVELL. ANY USE OR EXPLOITATION OF THIS WORK WITHOUT AUTHORIZATION
**	COULD SUBJECT THE PERPETRATOR TO CRIMINAL AND CIVIL LIABILITY.
*/

#ifndef __ADSP_H__
#define __ADSP_H__


#define  ADSP_MAJOR     2
#define  ADSP_MINOR     0
#define  ADSP_REVISION  0

/* ADSP Options */

typedef struct ATAdspOpt {
   char           Major;             /* READ-ONLY */
   char           Minor;             /* READ-ONLY */
   char           Revision;          /* READ-ONLY */
   unsigned char  reserved1;
   unsigned short TransThresh;       /* OBSOLETE */
   unsigned       TransTimerIntrvl;  /* OBSOLETE */
   unsigned char  reserved2[118];
} ATAdspOpt_t;

#endif /* __ADSP_H__ */
