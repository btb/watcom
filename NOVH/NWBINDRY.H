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

#ifndef _NWBINDRY_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

#include <nwtypes.h>

/**** Bindery security definitions ****/
#define BS_ANY_READ          0x0000      /* Readable by anyone                */
#define BS_LOGGED_READ       0x0001      /* Must be logged in to read         */
#define BS_OBJECT_READ       0x0002      /* Readable by same object or super  */
#define BS_SUPER_READ        0x0003      /* Readable by supervisor only       */
#define BS_BINDERY_READ      0x0004      /* Readable only by the bindery      */
#define BS_ANY_WRITE         0x0000      /* Writeable by anyone               */
#define BS_LOGGED_WRITE      0x0010      /* Must be logged in to write        */
#define BS_OBJECT_WRITE      0x0020      /* Writeable by same object or super */
#define BS_SUPER_WRITE       0x0030      /* Writeable only by the supervisor  */
#define BS_BINDERY_WRITE     0x0040      /* Writeable by the bindery only     */

/* Bindery object type definitions */
#define OT_WILD                        (-1)    /* Matches any type            */
#define OT_UNKNOWN                     0x0000  /* Unknown object type         */
#define OT_USER                        0x0001  /* The object is a "user"      */
#define OT_USER_GROUP                  0x0002  /* A group of users            */
#define OT_GROUP                       0x0002
#define OT_PRINT_QUEUE                 0x0003  /* Services print queues       */
#define OT_FILE_SERVER                 0x0004  /* The object serves files     */
#define OT_JOB_SERVER                  0x0005
#define OT_GATEWAY                     0x0006
#define OT_PRINT_SERVER                0x0007
#define OT_ARCHIVE_QUEUE               0x0008
#define OT_ARCHIVE_SERVER              0x0009  /* Services backup jobs        */
#define OT_JOB_QUEUE                   0x000A
#define OT_ADMINISTRATION              0x000B
#define OT_NAS_SNA_GATEWAY             0x0021
#define OT_REMOTE_BRIDGE_SERVER        0x0024
#define OT_TCPIP_GATEWAY               0x0027
#define OT_TIME_SYNCHRONIZATION_SERVER 0x002D
#define OT_ARCHIVE_SERVER_DYNAMIC_SAP  0x002E
#define OT_ADVERTISING_PRINT_SERVER    0x0047
#define OT_BTRIEVE_VAP                 0x004B
#define OT_NW$SQL_VAP                  0x004C
#define OT_PRINT_QUEUE_USER            0x0053

/* Attributes of objects and properties in the bindery */
#define BF_STATIC              0x0000
#define BF_DYNAMIC             0x0001
#define BF_ITEM                0x0000
#define BF_SET                 0x0002

/* Maximum lengths of object, properties, (includes terminating null) */
#define BL_OBJECT              48
#define BL_PROPERTY            16
#define BL_PASSWORD            128


int   AddBinderyObjectToSet(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         char *__memberName,
         WORD __memberType );

int   ChangeBinderyObjectPassword(
         char *__objectName,
         WORD __objectType,
         char *__oldPassword,
         char *__newPassword );

int   ChangeBinderyObjectSecurity(
         char *__objectName,
         WORD __objectType,
         BYTE __newObjectSecurity );

int   ChangePropertySecurity(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         BYTE __newPropertySecurity );

int   CloseBindery(
         void );

int   CreateBinderyObject(
         char *__objectName,
         WORD __objectType,
         BYTE __objectFlag,
         BYTE __objectSecurity );

int   CreateProperty(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         BYTE __propertyFlags,
         BYTE __propertySecurity );

int   DeleteBinderyObject(
         char *__objectName,
         WORD __objectType );

int   DeleteBinderyObjectFromSet(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         char *__memberName,
         WORD __memberType );

int   DeleteProperty(
         char *__objectName,
         WORD __objectType,
         char *__propertyName );

int   GetBinderyAccessLevel(
         BYTE *__accessLevel,
         long *__objectID );

int   GetBinderyObjectID(
         char *__objectName,
         WORD __objectType,
         long *__objectID );

int   GetBinderyObjectName(
         long __objectID,
         char *__objectName,
         WORD *__objectType );

int   IsBinderyObjectInSet(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         char *__memberName,
         WORD __memberType );

int   OpenBindery(
         void );

int   ReadPropertyValue(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         int __segmentNumber,
         BYTE *__propertyValue,
         BYTE *__moreSegments,
         BYTE *__propertyFlags );

int   RenameBinderyObject(
         char *__objectName,
         char *__newObjectName,
         WORD __objectType );

int   ScanBinderyObject(
         char *__searchObjectName,
         WORD __searchObjectType,
         long *__objectID,
         char *__objectName,
         WORD *__objectType,
         char *__objectHasProperties,
         char *__objectFlag,
         char *__objectSecurity );

int   ScanProperty(
         char *__objectName,
         WORD __objectType,
         char *__searchPropertyName,
         long *__sequenceNumber,
         char *__propertyName,
         char *__propertyFlags,
         char *__propertySecurity,
         char *__propertyHasValue,
         char *__moreProperties );

int   VerifyBinderyObjectPassword(
         char *__objectName,
         WORD __objectType,
         char *__password );

int   WritePropertyValue(
         char *__objectName,
         WORD __objectType,
         char *__propertyName,
         int __segmentNumber,
         BYTE *__propertyValue,
         BYTE __moreSegments );

#define _NWBINDRY_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NWBINDRY_H_INCLUDED */
