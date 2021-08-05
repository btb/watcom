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

#ifndef _DIRECT_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

#ifndef _SIZE_T_DEFINED_

   typedef unsigned int size_t;
   #define _SIZE_T_DEFINED_

#endif

#ifndef _TYPES_H_INCLUDED

   #include <sys\types.h>

#endif

#define NAME_MAX        12              /* 8 chars + '.' +  3 chars */

/*----------------------------------------------------------------------------*
 *   DIR structure                                                            *
 *----------------------------------------------------------------------------*/
typedef struct dirent 
   {  
   unsigned long  d_attr;                 /* entry's attribute               */
   unsigned short d_time;                 /* entry's modification time       */
   unsigned short d_date;                 /* entry's modification date       */
   long           d_size;                 /* entry's size - files only       */
   ino_t          d_ino;                  /* serial number                   */
   dev_t          d_dev;                  /* volume number                   */
   unsigned long  d_cdatetime;            /* creation date and time          */
   unsigned long  d_adatetime;            /* last access date - files only   */
   unsigned long  d_bdatetime;            /* last archive date and time      */
   long           d_uid;                  /* owner id (object id)            */
   unsigned long  d_archivedID;           /* obj ID that last archived file  */
   unsigned long  d_updatedID;            /* obj ID that last updated file   */
   char           d_name[ NAME_MAX + 1 ]; /* entry's DOS namespace name      */
   unsigned short d_inheritedRightsMask;  /* entry's inherited rights mask   */
   unsigned char  d_originatingNameSpace; /* entry's creating name space     */

   /* The next two fields are only valid in ScanErasedFiles                  */
   unsigned long  d_ddatetime;            /* deleted date/time               */
   unsigned long  d_deletedID;            /* deleted ID                      */
   } DIR;

/*----------------------------------------------------------------------------*
 *   File attribute constants for d_attr field                                *   
 *----------------------------------------------------------------------------*/
#define _A_NORMAL           0x00 /* Normal file - read/write permitted       */
#define _A_RDONLY           0x01 /* Read-only file                           */
#define _A_HIDDEN           0x02 /* Hidden file                              */
#define _A_SYSTEM           0x04 /* System file                              */
#define _A_EXECUTE          0x08 /* Execute only file                        */
#define _A_VOLID            0x08 /* Volume ID entry (SAME as EXECUTE)        */
#define _A_SUBDIR           0x10 /* Subdirectory                             */
#define _A_ARCH             0x20 /* Archive file                             */
#define _A_SHARE            0x80 /* Used for compatibility with DOS software */
                                 /*  that is not network aware               */

/* Extended attributes:     (NYI means Not Yet Implemented)                  */

#define _A_TRANS      0x00001000 /* Transactional - file will use TTS        */
#define _A_READAUD    0x00004000 /* Read audit - NYI in NW386 V3.1           */
#define _A_WRITAUD    0x00008000 /* Write audit - NYI in NW386 V3.1          */

#define _A_IMMPURG    0x00010000 /* Immediate purge                          */
#define _A_NORENAM    0x00020000 /* Mac rename inhibit                       */
#define _A_NODELET    0x00040000 /* Mac delete inhibit                       */
#define _A_NOCOPY     0x00080000 /* Mac copy inhibit                         */


extern int chdir( 
         const char *__pathName );

extern int closedir( 
         DIR *__dirP );

extern char *getcwd( 
         char  *__buffer, 
         size_t __size );

extern int mkdir( 
         const char *__pathName );

extern DIR *opendir( 
         const char *__pathName );

extern DIR *readdir(
         DIR *__dirP );

extern int rmdir( 
         const char *__pathName );

extern int SetReaddirAttribute( 
         DIR          *__dirP, 
         unsigned long __newAttribute );


#define _DIRECT_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif /* _DIRECT_H_INCLUDED  */
