/*
 * Copyright (c) 1983 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)inet.h 1.7 88/02/07 SMI; from UCB 5.1 5/30/85
 */

/*
 * External definitions for
 * functions in inet(3N)
 */
#ifdef __cplusplus
extern "C" {
#endif

unsigned long inet_addr(char *);
struct	in_addr inet_makeaddr(int,int);
unsigned long inet_network(char *);
int inet_lnaof(struct in_addr);
int inet_netof(struct in_addr);

#ifdef	NOT_NETWARE_386

/* provide normal compilations if a compiler tells us that this is not
netware */

/* Don't need to define a context block in a normal environment. */

#define	NETDB_DEFINE_CONTEXT
char	*inet_ntoa();

#else /* #ifdef NOT_NETWARE_386 */

int inet_netent(char *,unsigned long *,unsigned long *);
int inet_hostent(char *cp,unsigned long *);

/* Return codes for inet_netent, and inet_hostent */
#define INET_OK		 	 0	/* Success                            */
#define INET_BAD_PARAM		-1	/* Bad parameter                      */
#define INET_MALFORMED_STRING	-2	/* Illegal input string               */
#define INET_EXPERIMENTAL_ADDR	-3	/* Class D or E address               */
#define INET_MASK_TOO_SHORT	-4	/* Mask does not cover natural mask   */
#define INET_MASK_MUST_BE_ZERO	-5	/* Non-zero default route mask        */
#define INET_NET_ZERO		-6	/* Net number is all 0's or all 1's   */
#define INET_SUBNET_ZERO	-7	/* Subnet field is all 0's or all 1's */
#define INET_HOST_ZERO		-8	/* Host field is all 0's or all 1's   */

/* Declare the context block.  The client must supply the actual
 * block by placing NETDB_DEFINE_CONTEXT in one of the C modules
 * in the link.
 */

extern char nwinet_scratch[18];
#define NETINET_DEFINE_CONTEXT	char nwinet_scratch[18] ={0};
extern char *NWinet_ntoa(char *,struct in_addr);
#define inet_ntoa(in)			\
	NWinet_ntoa(nwinet_scratch,(in))

#endif

#ifdef __cplusplus
};
#endif
