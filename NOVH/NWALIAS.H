/*--------------------------------------------------------------------------
     (c) Copyright 1993 Novell, Inc.  All Rights Reserved.

 No part of this file may be duplicated, revised, translated, localized or
 modified in any manner or compiled, linked, or uploaded or downloaded to or
 from any computer system without the prior written consent of Novell, Inc.
--------------------------------------------------------------------------*/
#ifndef _NWALIAS_H
#ifdef __cplusplus
extern "C" {
#endif
   #define _NWALIAS_H
   #ifndef NWCONN_HANDLE
      #define NWCONN_HANDLE          NWCONN_ID
   #endif
   #define NWCONN_NUM_WORD           unsigned int
   #define NWCONN_TYPE               BYTE
   #define NWSTATUS                  DWORD
   #ifndef NWAPI
      #define NWAPI                  NWFAR NWPASCAL
   #endif
   #define NWOBJ_TYPE                WORD
   #define NWOBJ_ID                  DWORD
   #define NWSIZE                    DWORD
   #define NWLEN                     DWORD
   #define NWACCT_BALANCE            long
   #define NWACCT_LIMIT              long
   #define NWACCT_HOLDS              WORD
   #define NWHOLDS_INFO              HOLDS_INFO
   #define NWHOLDS_STATUS            HOLDS_STATUS
   #define NWCHARGE_AMOUNT           long
   #define NWHOLD_CANCEL_AMOUNT      DWORD
   #define NWHOLD_AMOUNT             DWORD
   #define NWNOTE_TYPE               WORD
   #define NWPSTR                    char NWFAR *
   #define NWAFP_ENTRY_ID            DWORD
   #define NWAFP_FILE_ATTRIBUTES     WORD
   #define NWAFP_FORK_LEN            DWORD
   #define NWAFP_NUM_OFFSPRING       WORD
   #define NWDATE                    WORD
   #define NWTIME                    WORD
   #define NWFINDER_INFO             BYTE
   #define NWAFP_ACCESS_PRIVILEGES   WORD
   #define NWAFP_FILE_INFO           AFPFILEINFO
   #define NWAFP_SET_INFO            AFPSETINFO
   #define NWDIR_TRUSTEE_RIGHTS      WORD
   #define NWVOL_NUM                 WORD
   #define NWACCESS_RIGHTS           BYTE
   #define NWFLAGS                   BYTE
   #define NWHANDLE                  BYTE
   #define NWREQUEST_MASK            WORD
   #define NWSTRUCT_SIZE             WORD
   #define NWFILE_MODE               BYTE
   #define NWLOCAL_FILE_HANDLE       WORD    /* FOR DOS, OS/2, AND WINDOWS */
   #define NWSEARCH_MASK             WORD
   #define NWAUDIT_FLAGS             DWORD
   #define NWAUDIT_SIZE              NWSIZE
   #define NWADDR_TYPE               BYTE
   #define NWADDR_LEN                BYTE
   #define NWCOUNT                   DWORD
   #define NWAUDIT_REPLICA_NUM       WORD
   #define NWAUDIT_EVENT             WORD
   #define NWMINUTES                 BYTE
   #define NWSECONDS                 DWORD
   #define NWAUDIT_CONTAINER_BIT_MAP DWORD
   #define NWAUDIT_CONN_ID           DWORD
   #define NWAUDIT_PROCESS_ID        DWORD
   #define NWAUDIT_STATUS_CODE       DWORD
   #define NWAUDIT_BUF_SIZE          WORD
   #define NWAUDIT_REC_NUM           DWORD
   #define NWAUDIT_DATE_TIME         DWORD
   #define NWDATE_TIME               DWORD
   #define NWATTR                    DWORD
   #define FILE_ATTRIBUTES_MASK      DWORD
   #define NWRIGHTS_MASK             WORD
   #define NWDISK_SPACE              DWORD
   #define NWAUDIT_OBJ_SECURITY      DWORD
   #define NWAUDIT_NAME_SPACE        DWORD
   #define NWAUDIT_FILE_HANDLE       DWORD
   #define NWNUM_BYTES               DWORD
   #define NWOFFSET                  DWORD
   #define NWAUDIT_TRUSTEE_RIGHTS    DWORD
   #define NWAUDIT_QUEUE_TYPE        DWORD
   #define NWNUM_BLOCKS              DWORD
   #define NWAUDIT_RECORD_ID         DWORD
   #define NWAUDIT_DATA_LEN          DWORD
   #define NWAUDIT_VOL_NUM           DWORD
   #define NWAUDIT_KEY_BUF           BYTE NWFAR *
   #define NWAUDIT_PASSWORD          BYTE NWFAR *
   #define NWAUDIT_FILE_CODE         int
   #define NWAUDIT_DS_FLAG           int
   #define NWAUDIT_LEVEL             BYTE
   #define NWSEGMENT_NUM             BYTE
   #define NWSEGMENT_DATA            BYTE NWFAR *
   #define NWSEQUENCE                DWORD
   #define TRUSTEE_RIGHTS            DWORD
   #define NWSYS_TIME                DWORD
   #define NWTRUSTEE_SEQUENCE_NUM    WORD
   #define NWELEMENT_VALUE           int
   #define NWNUM_ELEMENTS            int
   #define NWCONFIG_ELEMENT_NUM      int
   #define NWCONFIG_PARAM_TYPE       int
   #define NWCONFIG_DEFAULT_VALUE    long
   #define NWNUMBER                  WORD
   #define NWNUM                     DWORD
   #define NWCONN_FLAGS              WORD
   #define NWSESSION_ID              WORD
   #define NWNUM_PACKETS             DWORD
   #define NWLOGIN_TIME              BYTE[6]
   #define NWLOCAL_MODE              WORD
   #define NWLOCAL_SCOPE             WORD
   #define NWNAME_SPACE              BYTE
   #define NWDIR_ID                  BYTE
   #define NWDIR_NUM                 WORD
   #define NWDIR_ENTRY               DWORD
   #define NWNAME                    BYTE NWFAR *
   #define NWNAME_LEN                BYTE
   #define NWFILE_LEN                DWORD
   #define NWDELETE_TIME             DWORD
   #define NWVOL                     DWORD
   #define NWDIR_SPACE               DWORD
   #define NWFAT                     DWORD
   #define NWSEARCH_ATTRIBUTES       WORD
   #define NWSEARCH_ATTR             BYTE
   #define NWAUGMENT                 WORD /* AN ADDITIONAL FLAG SIZE */
   #define NWNUM_ENTRIES             WORD
   #define NWBITS                    DWORD
   #define NWNUM_DIR_ENTRIES         DWORD
   #define NWRESERVED32              DWORD
   #define NWRESERVED16              DWORD
   #define NWNUM_SECTORS             BYTE
   #define NWSEQUENCE_NUM            WORD
   #define NWDIR_ATTRIBUTES          BYTE
   #define NWDIR_STAMP               WORD
   #define NWDRIVE_NUM               WORD
   #define NWPATH_VOL                BYTE
   #define NWDIR_VOL                 BYTE
   #define NWNET_ADDR_TYPE           DWORD
   #define NWNET_ADDR_LEN            DWORD
   #define NWNET_ADDR                BYTE
   #define NWPOSITION                DWORD
   #define NWEA                      NW_EA_HANDLE
   #define NWEA_HANDLE               DWORD
   #define NWEA_KEY_LEN              WORD
   #define NWEA_KEY_OFFSET           WORD
   #define NWEA_KEY                  WORD
   #define NWEA_SCAN                 NW_EA_FF_STRUCT
   #define NWFILE_ATTR               BYTE

   #define NWVCONSOLE_VERSION        BYTE
   #define NWVCONSOLE_REVISION       BYTE
   #define NWFACTOR                  DWORD
   #define NWNUM_HOPS                WORD
   #define NWNUM_BUFFERS             WORD
   #define NWUTILIZATION             DWORD
   #define NWLOCK_COUNT              WORD
   #define NWNUM_REQUESTS            DWORD
   #define NWSOCKET_COUNT            WORD
   #define NWAES_COUNT               WORD
   #define NWECB_CANCEL_COUNT        WORD
   #define NWGLT_FAIL_COUNT          WORD
   #define NWSPX_COUNT               WORD
   #define NWFSE_FLAGS               DWORD
   #define NWNLM_TYPE                DWORD
   #define NWNLM_ID                  DWORD
   #define NWOS_VERSION              WORD
   #define NWOS_REVISION             WORD
   #define NWAPP_NUM                 WORD
   #define NWDRV_FLAGS               WORD
   #define NWDRV_NAME                DWORD
   #define NWDRV_TYPE                DWORD
   #define NWDRV_ID                  WORD
   #define NWDRV_VERSION             BYTE
   #define NWDRV_LINK                DWORD
   #define NWDRV_MEM                 DWORD
   #define NWDRV_TAG                 DWORD
   #define NWDRV_CONFIG              DWORD
   #define NWDRV_COMMAND             DWORD
   #define NWSTATS_VERSION           BYTE
   #define NWMEDIA_TYPE              DWORD
   #define NWMEDIA_MASK              DWORD
   #define NWPROTOCOL_VERSION        BYTE
   #define NWPROTOCOL_MASK           DWORD
   #define NWFSE_CONN_TYPE           DWORD

   #define NWVERSION                 DWORD
   #define NWREVISION                DWORD
   #define NWFILE_SYS_ID             DWORD


   #define NWTRAN_TYPE               BYTE
   #define NWLENGTH                  WORD
   #define NWBUF_SIZE                WORD
   #define NWDISTANCE                WORD
   #define NWMAX_PACKET_SIZE         WORD
   #define NWSERVER_NAME_LEN         WORD

   #define NWRIGHTS                  DWORD
   #define NWTASK_NUM                WORD
   #define NWLOCK_TYPE               BYTE
   #define NWNUM_CONNS               BYTE
   #define NWNEXT_REQUEST            WORD
   #define NWTASK                    WORD
   #define NWNUM_FORKS               BYTE
   #define NWOPEN_COUNT              WORD
   #define NWCURRENT_REC             WORD
   #define NWUSE_COUNT               WORD
   #define NWDENY_COUNT              WORD
   #define NWSEARCH_CONTEXT          WORD
   #define NWSEQ_NUM                 BYTE
   #define NWLAST_RECORD             int
   #define NWTICKS                   WORD

   #define NWMODULE_ID               DWORD
   #define NWDATA_STREAM             DWORD
   #define NWINFO_LEVEL              DWORD
   #define NWDM_FLAGS                DWORD
   #define NWFRAG_SIZE               WORD
   #define NWTASK_STATE              BYTE
   #define NWLOCK_STATE              BYTE
   #define NWTASK_COUNT              BYTE
   #define NWREQUESTER_VERSION       BYTE
   #define NWACCESS_MODE             BYTE
   #define NWBROADCAST_MODE          WORD
   #define NWDIR_BASE                DWORD
   #define NWNS_MASK                 DWORD
   #define NWNS_BITS                 WORD
   #define NWNS_FLAGS                WORD
   #define NWPATH_SIZE               WORD
   #define NWNS_ACCESS_RIGHTS        WORD
   #define NWNS_HANDLE               DWORD
   #define NWNS_ATTR                 WORD
   #define NWNS_LIST_SIZE            BYTE
   #define NWNS_NUM                  BYTE
   #define NWNS_DATA_STREAM          BYTE
   #define NWNS_TYPE                 WORD
   #define NWNS_DATA_STREAM2         WORD
   #define NWNS_ACCESS_MODE          WORD
   #define NWFORM_TYPE               WORD
   #define NWSTATION_NUM             BYTE
   #define NWSTATION_NUM2            DWORD
   #define NWJOB_POSITION            BYTE
   #define NWJOB_POSITION2           WORD
   #define NWTAB                     BYTE
   #define NWPRINT_TASK              DWORD
   #define NWPRINT_FLAGS             WORD
   #define NWJOB_TYPE                WORD
   #define NWQMS_TASK                DWORD
   #define NWJOB_FLAGS               WORD
   #define NWQMS_HANDLE              DWORD
   #define NWJOB_HANDLE              DWORD

   #define NWNUMBER_ENTRIES          BYTE
   #define NWDRIVE_NUMBER            BYTE
   #define NWVOL_TYPE                DWORD
   #define NWVOL_NUMBER              BYTE
   #define NWVOL_FLAGS               WORD
   #define NWNUM_TRANSACTIONS        BYTE
   #define NWTDS                     WORD
   #define NWTDS_OFFSET              WORD
   #define NWREC_OFFSET              WORD
   #define NWLOCK_TYPE               BYTE
   #define NWSEM_VALUE               WORD
   #define NWLOCK_DATA_STREAM        BYTE
   #define NWSEM_HANDLE              DWORD
   #define NWSEM_INT                 int
   #define NWOPTION_NUM              BYTE
   #define NWDISK_CHANNEL            BYTE
   #define NWDISK_TYPE               BYTE
   #define NWCTLR_NUM                BYTE
   #define NWCTLR_TYPE               BYTE
   #define NWNUM_HEADS               BYTE
   #define NWHF_START                DWORD
   #define NWDISK_FLAGS              WORD
   #define NWDISK_DRV_TYPE           BYTE
   #define NWIO_MEM                  WORD
   #define NWMEM_OFFSET              WORD
   #define NWINTERRUPT               BYTE
   #define NWDMA                     BYTE
   #define NWSUPPORT_LEVEL           BYTE
   #define NWNUM_DRIVES              BYTE
   #define NWSERVICE_VERSION         BYTE
   #define NWDISK_NUM                BYTE
   #define NWLAN_NUM                 BYTE
   #define NWSERVER_TYPE             WORD
   #define NWPRINTER                 WORD
   #define NWNUM_COPIES              BYTE
   #define NWFORM_NUM                BYTE
   #define NWDEVICE_ID               WORD
   #define NWLPT                     BYTE
   #define NWDSLEN                   unit32
   #define NWDS_FLAGS                uint32
   #define NWDS_VALIDITY             uint32
   #define NWDS_TYPE_LEVEL           uint32
   #define NWDS_INTERVAL             uint32
   #define NWDS_PRIVILEGES           uint32
   #define NWREPLICA_NUM             long
   #define NWEMAIL_TYPE              uint32
   #define NWDS_EVENT                uint32
   #define NWSYNTAX_ID               uint32
   #define NWNAME_SPACE_TYPE         uint32
   #define NWDS_OPERATION            uint32
   #define NWDS_VALUE                uint32
   #define NWDS_ID                   int
   #define NWDS_SYNTAX_FLAGS         int
   #define NWREPLICA_TYPE            uint32
   #define NWCHANGE_TYPE             uint32
   #define NWDS_BUFFER               Buf_T
   #define NWOBJECT_INFO             Object_Info_T
   #define NWASN1_ID                 Asn1ID_T
   #define NWATTR_INFO               Attr_Info_T
   #define NWCLASS_INFO              Class_Info_T
   #define NWSYNTAX_INFO             Syntax_Info_T
   #define NWDS_SIZE                 uint32
   #define NWDS_SESSION_KEY          NWDS_Session_Key_T
   #define NWDS_ITERATION            int32
   #define NWDS_TYPE                 uint32
   #define NWDS_SEARCH_SCOPE         int
   #define NWDS_NUM_OBJ              int32
   #define NWDS_TOKEN                uint16
   #define NWDS_FILTER_NODE          Filter_Node_T
   #define NWDS_FILTER_LEVEL         uint16
   #define NWDS_FILTER_CURSOR        Filter_Cursor_T
   #define NWDS_LOGIN_FILE           int
#ifdef __cplusplus
};
#endif
#endif
