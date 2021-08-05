/** Copyright (c) 1989  Mentat Inc.
 ** dlpihdr.h 1.2, last change 7/19/90
 **/

#ifndef _DLPI_
#ifdef __cplusplus
extern "C" {
#endif
#define _DLPI_

/* Client requests */
#define	DL_ATTACH_REQ		1	/* Attach to PPA */
#define	DL_BIND_REQ		2	/* Bind to DLSAP address */
#define	DL_CONNECT_REQ		3	/* Request outgoing connection */
#define	DL_CONNECT_RES		4	/* Respond to incoming connection */
#define	DL_DATA_REQ		5
#define	DL_DETACH_REQ		6	/* Detach from PPA */
#define	DL_DISCONNECT_REQ	7	/* Drop current connection */
#define	DL_INFO_REQ		8	/* Information request */
#define	DL_RESET_REQ		9	/* Initiate a resynchronization */
#define	DL_RESET_RES		10	/* Complete a resynchronization */
#define	DL_TOKEN_REQ		11	/* Retrieve token assigned to stream */
#define	DL_UNBIND_REQ		12	/* Unbind from DLSAP address */
#define	DL_UNITDATA_REQ		13

/* Provider responses */
#define	DL_BIND_ACK		20	/* Bind acknowledgement */
#define	DL_CONNECT_CON		21	/* Confirmation of outgoing connect */
#define	DL_CONNECT_IND		22	/* Indication of inbound connect */
#define	DL_DATA_IND		23
#define	DL_DISCONNECT_IND	24	/* Indication of connection failure */
#define	DL_ERROR_ACK		25
#define	DL_INFO_ACK		26	/* Information acknowledgement */
#define	DL_OK_ACK		27
#define	DL_RESET_CON		28	/* Confirmation of resynchronization */
#define	DL_RESET_IND		29
#define	DL_TOKEN_ACK		30
#define	DL_UNITDATA_IND		31
#define	DL_UDERROR_IND		32

/* DLPI error values */
#define	DL_ACCESS	1	/* Permissions insufficient for request */
#define	DL_BADADDR	2	/* DLSAP address invalid or incorrect format */
#define	DL_BADCORR	3	/* Invalid correlation number */
#define	DL_BADDATA	4	/* Amount of data exceeded limit */
#define	DL_BADQOSPARAM	5	/* Invalid quality of service parameter */
#define	DL_BADQOSTYPE	6	/* Quality of service type not supported */
#define	DL_BADTOKEN	7	/* Invalid stream token */
#define	DL_BOUND	8	/* Address is bound to another stream */
#define	DL_INITFAILED	9	/* Automatic init of PPA failed */
#define	DL_NOADDR	10	/* Could not alloc DLSAP address */
#define	DL_NOTINIT	11	/* PPA has not been initialized */
#define	DL_OUTSTATE	12	/* Primitive issued from invalid state */
#define	DL_SYSERR	13	/* System error occurred, check unix error */
#define	DL_UNSUPPORTED	14	/* Requested service mode not supported */
#define	DL_BADPPA	15	/* PPA invalid */
#define	DL_BADPRIM	16	/* Primitive invalid */

/* DLPI states */
#define	DL_ATTACH_PENDING	1
#define	DL_BIND_PENDING		2
#define	DL_CONN_RES_PENDING	3
#define	DL_DATAXFER		4
#define	DL_DETACH_PENDING	5
#define	DL_IDLE			6
#define	DL_INCON_PENDING	7
#define	DL_OUTCON_PENDING	8
#define	DL_PROV_RESET_PENDING	9
#define	DL_UNATTACHED		10
#define	DL_UNBIND_PENDING	11
#define	DL_UNBOUND		12
#define	DL_UDQOS_PENDING	13
#define	DL_USER_RESET_PENDING	14

/* Disconnect reasons */
#define	DL_CONREJ_DEST_UNKNOWN			1
#ifdef vms
#define	DL_CONREJ_DEST_UNREACH_PERMANEN		2 /* Can never reach dest */
#define DL_CONREJ_DEST_UNREACH_TRANSIEN		3 /* Cannot reach dest now */
#else
#define	DL_CONREJ_DEST_UNREACH_PERMANENT	2 /* Can never reach dest */
#define DL_CONREJ_DEST_UNREACH_TRANSIENT	3 /* Cannot reach dest now */
#endif
#define	DL_CONREJ_PERMANENT_COND		4
#define	DL_CONREJ_QOS_UNAVAIL_PERMANENT		5 /* QOS not available */
#define	DL_CONREJ_QOS_UNAVAIL_TRANSIENT		6
#define	DL_CONREJ_TRANSIENT_COND		7
#define	DL_DISC_ABNORMAL_CONDITION		8 /* Abnormal release */
#define	DL_DISC_NORMAL_CONDITION		9 /* Normal release */
#define	DL_DISC_PERMANENT_CONDITION		10
#define	DL_DISC_TRANSIENT_CONDITION		11
#define	DL_DISC_UNSPECIFIED

/* Reset reasons */
#define	DL_RESET_FLOW_CONTROL	1	/* Flow control congestion */
#define	DL_RESET_LINK_ERROR	2	/* Data link error situation */
#define	DL_RESET_RESYNCH	3	/* Request for resynchronization */

/* Service modes */
#define	DL_CODLS	0x1	/* Connection-oriented data link service */
#define	DL_CLDLS	0x2	/* Connectionless data link service */

/* Provider styles */
#define	DL_STYLE1	1	/* PPA attached by opening major/minor */
#define	DL_STYLE2	2	/* PPA must be explicitly attached */

/* Media types */
#define	DL_CSMACD	1	/* Carrier Sense Multiple Access with Collision Detection (ISO 8802/3) */
#define	DL_TPB		2	/* Token-Passing Bus (ISO 8802/4) */
#define	DL_TPR		3	/* Token-Passing Ring (ISO 8802/5) */
#define	DL_METRO	4	/* Metro Net (ISO 8802/6) */
#define	DL_ETHER	5	/* Ethernet Bus */
#define	DL_HDLC		6	/* bit synchronous communication line */
#define	DL_CHAR		7	/* character synchronous communication line */
#define	DL_CTCA		8	/* channel-to-channel adapter */

typedef struct {
	ulong	dl_primitive;	/* DL_ATTACH_REQ */
	ulong	dl_ppa;		/* Physical point of attachment identifier */
} dl_attach_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_BIND_ACK */
	ulong	dl_sap;			/* DLSAP associated with stream */
	ulong	dl_addr_length;		/* Length of complete DLSAP address */
	ulong	dl_addr_offset;		/* Offset to DLSAP address */
	ulong	dl_max_conind;		/* Allowed max of DL_CONNECT_INDs */
	ulong	dl_growth;
} dl_bind_ack_t;

typedef struct {
	ulong	dl_primitive;		/* DL_BIND_REQ */
	ulong	dl_sap;			/* DLSAP identifier */
	ulong	dl_max_conind;		/* Max incoming connect inds allowed */
	ushort	dl_service_mode;	/* Desired mode of service */
	ushort	dl_conn_mgmt;		/* PPA "connection management" stream*/
} dl_bind_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_CONNECT_CON */
	ulong	dl_resp_addr_length;	/* Length of local responding addr */
	ulong	dl_resp_addr_offset;	/* Offset to address */
	ulong	dl_qos_length;		/* Length of selected qos params */
	ulong	dl_qos_offset;		/* Offset to qos params */
	ulong	dl_growth;
} dl_connect_con_t;

typedef struct {
	ulong	dl_primitive;		/* DL_CONNECT_IND */
	ulong	dl_correlation;		/* To be passed in DL_CONNECT_RES */
	ulong	dl_called_addr_length;	/* Length of local address */
	ulong	dl_called_addr_offset;	/* Offset to local address */
	ulong	dl_calling_addr_length;	/* Length of originator's address */
	ulong	dl_calling_addr_offset;	/* Offset to originator's address */
	ulong	dl_qos_length;		/* Length of requested qos params */
	ulong	dl_qos_offset;		/* Offset to qos params */
	ulong	dl_growth;
} dl_connect_ind_t;

typedef struct {
	ulong	dl_primitive;		/* DL_CONNECT_REQ */
	ulong	dl_dest_addr_length;	/* DLSAP to connect to */
	ulong	dl_dest_addr_offset;	/* Offset to address in message */
	ulong	dl_qos_length;		/* Length of desired qos params */
	ulong	dl_qos_offset;		/* Offset to qos params */
	ulong	dl_growth;
} dl_connect_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_CONNECT_RES */
	ulong	dl_correlation;		/* Correlation passed in CONNECT_IND */
	ulong	dl_resp_token;		/* Token of stream to accept connect */
	ulong	dl_qos_length;		/* Length of selected qos params */
	ulong	dl_qos_offset;		/* Offset to selected qos params */
	ulong	dl_growth;
} dl_connect_res_t;

typedef struct {
	ulong	dl_primitive;		/* DL_DATA_IND */
	ulong	dl_more;		/* Last piece of DLSDU indication */
} dl_data_ind_t;

typedef struct {
	ulong	dl_primitive;		/* DL_DATA_REQ */
	ulong	dl_more;		/* Last piece of DLSDU ? */
} dl_data_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_DETACH_REQ */
} dl_detach_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_DISCONNECT_IND */
	ulong	dl_originator;		/* Disconnect by user or provider */
	ulong	dl_reason;		/* Reason for disconnect */
	ulong	dl_correlation;		/* Connection token in CONNECT_IND */
} dl_disconnect_ind_t;

typedef struct {
	ulong	dl_primitive;		/* DL_DISCONNECT_REQ */
	ulong	dl_reason;		/* Reason for disconnect */
	ulong	dl_correlation;		/* Connection token in CONNECT_IND */
} dl_disconnect_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_ERROR_ACK */
	ulong	dl_error_primitive;	/* Primitive in error */
	ulong	dl_errno;		/* DLPI error code */
	ulong	dl_unix_errno;		/* UNIX system error code */
} dl_error_ack_t;

typedef struct {
	ulong	dl_primitive;		/* DL_INFO_ACK */
	ulong	dl_max_sdu;		/* Max number of transmit bytes */
	ulong	dl_min_sdu;		/* Min number of transmit bytes */
	ulong	dl_addr_length;		/* Length of provider's DLSAP address*/
	ulong	dl_mac_type;		/* Type of medium supported */
	ulong	dl_reserved;		/* Must be zero */
	ulong	dl_current_state;	/* State of DLPI interface */
	ulong	dl_max_idu;		/* Max number of DLIDU bytes */
	ulong	dl_service_mode;	/* Service modes supported */
	ulong	dl_qos_length;		/* Quality of service params length */
	ulong	dl_qos_offset;		/* Offset to qos paramaters */
	ulong	dl_qos_range_length;	/* Length of available range of qos */
	ulong	dl_qos_range_offset;	/* Offset to qos range */
	long	dl_provider_style;	/* Style of DLS provider */
	ulong	dl_growth;
} dl_info_ack_t;

typedef struct {
	ulong	dl_primitive;		/* DL_INFO_REQ */
} dl_info_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_OK_ACK */
	ulong	dl_correct_primitive;	/* Successfully received primitive */
} dl_ok_ack_t;

typedef struct {
	ulong	dl_primitive;		/* DL_RESET_CON */
} dl_reset_con_t;

typedef struct {
	ulong	dl_primitive;		/* DL_RESET_IND */
	ulong	dl_originator;		/* User or provider initiated */
	ulong	dl_reason;		/* Reason for reset */
} dl_reset_ind_t;

typedef struct {
	ulong	dl_primitive;		/* DL_RESET_REQ */
} dl_reset_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_RESET_RES */
} dl_reset_res_t;

typedef struct {
	ulong	dl_primitive;		/* DL_TOKEN_ACK */
	ulong	dl_token;		/* Connection response token */
} dl_token_ack_t;

typedef struct {
	ulong	dl_primitive;		/* DL_TOKEN_REQ */
} dl_token_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_UNBIND_REQ */
} dl_unbind_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_UDERROR_IND */
	ulong	dl_dest_addr_length;	/* Length of destination address */
	ulong	dl_dest_addr_offset;	/* Offset to address */
	ulong	dl_reserved;
	ulong	dl_errno;
} dl_uderror_ind_t;

typedef struct {
	ulong	dl_primitive;		/* DL_UDQOS_REQ */
	ulong	dl_qos_length;		/* Length of requests qos params */
	ulong	dl_qos_offset;		/* Offset to qos params */
} dl_udqos_req_t;

typedef struct {
	ulong	dl_primitive;		/* DL_UNITDATA_IND */
	ulong	dl_src_addr_length;	/* Length of source address */
	ulong	dl_src_addr_offset;	/* Offset to address */
	ulong	dl_dest_addr_length;	/* Length of destination address */
	ulong	dl_dest_addr_offset;	/* Offset to address */
	ulong	dl_reserved;
} dl_unitdata_ind_t;

typedef struct {
	ulong	dl_primitive;		/* DL_UNITDATA_REQ */
	ulong	dl_dest_addr_length;	/* Length of destination address */
	ulong	dl_dest_addr_offset;	/* Offset to address */
	ulong	dl_reserved[2];		/* Must be zero */
} dl_unitdata_req_t;

#ifdef __cplusplus
};
#endif
#endif
