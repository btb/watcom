/*
 * Copyright (c) 1980 Regents of the University of California.
 * All rights reserved.  The Berkeley software License Agreement
 * specifies the terms and conditions for redistribution.
 *
 *	@(#)netdb.h	5.7 (Berkeley) 5/12/86
 */

#ifndef _NETDB_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif

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


/*
 * $Header: G:\BLD\NWSDK\NOVH40\m:\nwsdk\NOVH40\rcs\NETDB.H 1.2 93/05/03 11:42:26 John_Dahms Exp $
 * 
 * $Abstract:
 * Standard definitions for accessing the socket interface's network
 * database in Novell's NetWare 386 TCP/IP.  Since process context is
 * limited in NetWare 386, we need to play some games to provide context
 * to the database.
 * $
 * 
 * $Implementation Notes:
 * The actual NetWare 386 TCP/IP routines take an additional parameter
 * to provide them a block for maintaining context.  The normal routines
 * are actually macros which call the context aware routines.
 * 
 * One modification is required for porting an NLM the NetWare 386
 * versions of the database routines: a context block must be defined.
 * This is done by using the macro NETDB_DEFINE_CONTEXT in any one
 * module linked into the NLM.
 * 
 * If the preprocessor symbol NOT_NETWARE_386 is defined, this becomes
 * the standard netdb.h from 4.3BSD for use in more typical environments.
 * $
 */

/*
 * Structures returned by network
 * data base library.  All addresses
 * are supplied in host order, and
 * returned in network order (suitable
 * for use in system calls).
 */
struct	hostent {
	char	*h_name;	/* official name of host */
	char	**h_aliases;	/* alias list */
	int	h_addrtype;	/* host address type */
	int	h_length;	/* length of address */
	char	**h_addr_list;	/* list of addresses from name server */
#define	h_addr	h_addr_list[0]	/* address, for backward compatiblity */
};

/*
 * Assumption here is that a network number
 * fits in 32 bits -- probably a poor one.
 */
struct	netent {
	char		*n_name;	/* official name of net */
	char		**n_aliases;	/* alias list */
	int		n_addrtype;	/* net address type */
	unsigned long	n_net;		/* network # */
	unsigned long	n_mask;		/* net mask -- Novell extension */
};

struct	servent {
	char	*s_name;	/* official service name */
	char	**s_aliases;	/* alias list */
	int	s_port;		/* port # */
	char	*s_proto;	/* protocol to use */
};

struct	protoent {
	char	*p_name;	/* official protocol name */
	char	**p_aliases;	/* alias list */
	int	p_proto;	/* protocol # */
};


#ifdef NOT_NETWARE_386
/* Provide normal definitions if a compiler switch tells us that this
 * isn't NetWare.
 */

/* Don't need to define a context block in a normal environment. */
#define	NETDB_DEFINE_CONTEXT

struct hostent	*gethostbyname(), *gethostbyaddr(), *gethostent();
struct netent	*getnetbyname(), *getnetbyaddr(), *getnetent();
struct servent	*getservbyname(), *getservbyport(), *getservent();
struct protoent	*getprotobyname(), *getprotobynumber(), *getprotoent();
/* Normal h_errno is just a simple int. */
extern  int h_errno;	

#else	/* #ifdef NOT_NETWARE_386 */
/* But normally we assume this is NetWare 386, so we have to fake
 * the whole thing up to provide context.
 */

/*TODO: These are defined for now but will probably change:Andy*/
#define	SCRATCHBUFSIZE	1024
#define MAXALIASES	10
#define MAXALIASSIZE	64
#define MAXNAMESIZE	64
#define MAXADDRSIZE	19
#define MAXHOSTADDR	1

/* Special Novell structure for providing context in the otherwise
 * context-free NetWare 386 environment. The applications SHOULD NOT
 * access this structure !.
 */
typedef struct nwsockent {
	FILE           *nse_hostctx;
	FILE           *nse_netctx;
	FILE           *nse_protoctx;
	FILE           *nse_servctx;
	int		nse_h_errno;
	union sockent {
		struct hostent  nsu_hst;
		struct netent   nsu_net;
		struct protoent nsu_proto;
		struct servent  nsu_serv;
	}               nse_sockent_un;
	char            nse_scratch[SCRATCHBUFSIZE];
} nwsockent;

/* Declare the context block.  The client must supply the actual
 * block by placing NETDB_DEFINE_CONTEXT in one of the C modules
 * in the link.
 */
extern struct nwsockent nwSocketCtx;

/* Macro to define the actual context block somewhere. */
#define	NETDB_DEFINE_CONTEXT	struct nwsockent nwSocketCtx = {0};

/* Host file examination */
extern struct hostent *NWgethostbyname( struct nwsockent *nwsktctx,
					char		 *name
				      );
extern struct hostent *NWgethostbyaddr( struct nwsockent *nwsktctx,
					char		 *addr,
					int		  length,
					int		  type
				      );
extern struct hostent *NWgethostent( struct nwsockent *nwsktctx );
extern void	       NWsethostent( struct nwsockent *nwsktctx,
				     int	       stayopen
				   );
extern void	       NWendhostent( struct nwsockent *nwsktctx );

/* Network file examination */
extern struct netent *NWgetnetbyname( struct nwsockent *nwsktctx,
				      char	       *name
				    );
extern struct netent *NWgetnetbyaddr( struct nwsockent *nwsktctx,
				      long		net,
				      int		type
				    );
extern struct netent *NWgetnetent( struct nwsockent *nwsktctx );
extern void	      NWsetnetent( struct nwsockent *nwsktctx,
				   int		     stayopen
				 );
extern void	      NWendnetent( struct nwsockent *nwsktctx );

/* Service file examination */
extern struct servent *NWgetservbyname( struct nwsockent *nwsktctx,
					char		 *name,
					char		 *protocol
				      );
extern struct servent *NWgetservbyport( struct nwsockent *nwsktctx,
					int		  port,
					char		 *protocol
				      );
extern struct servent *NWgetservent( struct nwsockent *nwsktctx );
extern void	       NWsetservent( struct nwsockent *nwsktctx,
				     int	       stayopen
				   );
extern void	       NWendservent( struct nwsockent *nwsktctx );

/* Protocol file examination */
extern struct protoent *NWgetprotobyname( struct nwsockent *nwsktctx,
					  char		   *name
					);
extern struct protoent *NWgetprotobynumber( struct nwsockent *nwsktctx,
					    int		      protocol
					  );
extern struct protoent *NWgetprotoent( struct nwsockent *nwsktctx );
extern void		NWsetprotoent( struct nwsockent *nwsktctx,
				       int		 stayopen
				     );
extern void		NWendprotoent( struct nwsockent *nwsktctx );
extern int		gethostname(char *name,int namelen);
extern long		gethostid(void);

/* Macros mapping the standard 4.3BSD names to calls with context
 * to our versions of the routines.
 */
#define	gethostbyname( name )				\
	NWgethostbyname( &nwSocketCtx, (name) )
#define	gethostbyaddr( addr, length, type )		\
	NWgethostbyaddr( &nwSocketCtx, (addr), (length), (type) )
#define	gethostent()					\
	NWgethostent( &nwSocketCtx )
#define	sethostent( stayopenflag )			\
	NWsethostent( &nwSocketCtx, (stayopenflag) )
#define	endhostent()					\
	NWendhostent( &nwSocketCtx )
#define	getnetbyname( name )				\
	NWgetnetbyname( &nwSocketCtx, (name) )
#define	getnetbyaddr( net, type )			\
	NWgetnetbyaddr( &nwSocketCtx, (net), (type) )
#define	getnetent()					\
	NWgetnetent( &nwSocketCtx )
#define	setnetent( stayopenflag )			\
	NWsetnetent( &nwSocketCtx, (stayopenflag) )
#define	endnetent()					\
	NWendnetent( &nwSocketCtx )
#define	getservbyname( name, protocol )			\
	NWgetservbyname( &nwSocketCtx, (name), (protocol) )
#define	getservbyport( port, protocol )			\
	NWgetservbyport( &nwSocketCtx, (port), (protocol) )
#define	getservent()					\
	NWgetservent( &nwSocketCtx )
#define	setservent( stayopenflag )			\
	NWsetservent( &nwSocketCtx, (stayopenflag) )
#define	endservent()					\
	NWendservent( &nwSocketCtx )
#define	getprotobyname( name )				\
	NWgetprotobyname( &nwSocketCtx, (name) )
#define	getprotobynumber( protocol )			\
	NWgetprotobynumber( &nwSocketCtx, (protocol) )
#define	getprotoent()					\
	NWgetprotoent( &nwSocketCtx )
#define	setprotoent( stayopenflag )			\
	NWsetprotoent( &nwSocketCtx, (stayopenflag) )
#define	endprotoent()					\
	NWendprotoent( &nwSocketCtx )

/* h_errno is also context dependent, so define a macro for it, too. */
#define	h_errno	nwSocketCtx.nse_h_errno

#endif	/* end of #else clause of #ifdef NOT_NETWARE_386 */

/*
 * Error return codes from gethostbyname() and gethostbyaddr()
 */

#define	HOST_NOT_FOUND	1 /* Authoritive Answer Host not found */
#define	TRY_AGAIN	2 /* Non-Authoritive Host not found, or SERVERFAIL */
#define	NO_RECOVERY	3 /* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
#define NO_ADDRESS	4 /* Valid host name, no address, look for MX record */


#define _NETDB_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif  /* _NETDB_H_INCLUDED  */
