/** Copyright (c) 1989-1990  Mentat Inc.
 ** lihdr.h 1.4, last change 6/20/90
 **/

#ifndef	_LIHDR_
#ifdef __cplusplus
extern "C" {
#endif
#define	_LIHDR_

/* Client requests */
#define	DL_BIND_REQ		2
#define	DL_INFO_REQ		8
#define	DL_UNBIND_REQ		12
#define	DL_UNITDATA_REQ		13

/* Device responses */
#define	DL_BIND_ACK		20
#define	DL_ERROR_ACK		25
#define	DL_INFO_ACK		26
#define	DL_OK_ACK		27
#define	DL_UNBIND_ACK		13
#define	DL_UNITDATA_IND		31

/* Service classes */
#define	DL_NOSERV		0

/* States */
#define	DL_IDLE			1	/* Idle (ready to send/receive) */
#define	DL_UNBND		2	/* Unbound */
#define	DL_WACK_B		3	/* Waiting for bind acknowledgement */
#define	DL_WACK_U		4	/* Waiting for unbind acknowledgement */

struct DL_bind_ack {
	long	PRIM_type;
	long	LLC_sap;
	long	ADDR_length;
	long	ADDR_offset;
};
#define	DL_BIND_ACK_SIZE	sizeof(struct DL_bind_ack)

struct DL_bind_req {
	long	PRIM_type;
	long	LLC_sap;
	long	GROWTH_field[2];
};
#define	DL_BIND_REQ_SIZE	sizeof(struct DL_bind_req)

struct DL_error_ack {
	long	PRIM_type;
	long	ERROR_prim;
	long	LLC_error;
	long	UNIX_error;
};
#define	DL_ERROR_ACK_SIZE	sizeof(struct DL_error_ack)

typedef struct DL_ok_ack {
	long	PRIM_type;
	long	CORRECT_prim;
};
#define	DL_OK_ACK_SIZE		sizeof(struct DL_ok_ack)

struct DL_unitdata_ind {
	long	PRIM_type;
	long	RA_length;	/* length of destination address */
	long	RA_offset;
	long	LA_length;	/* length of source address */
	long	LA_offset;
	long	SERV_class;
};
#define	DL_UNITDATA_IND_SIZE	sizeof(struct DL_unitdata_ind)

struct DL_unitdata_req {
	long	PRIM_type;
	long	RA_length;	/* length of destination address */
	long	RA_offset;	/* offset to destination address */
	long	SERV_class;
	long	FILLER_field;
};
#define	DL_UNITDATA_REQ_SIZE	sizeof(struct DL_unitdata_req)

union DL_primitives {
	long			prim_type;
	struct DL_bind_req	bind_req;
	struct DL_bind_ack	bind_ack;
	struct DL_error_ack	error_ack;
	struct DL_ok_ack	ok_ack;
	struct DL_unitdata_req	data_req;
	struct DL_unitdata_ind	data_ind;
};

#ifdef __cplusplus
};
#endif
#endif
