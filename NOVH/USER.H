/** Copyright (c) 1989-1990  Mentat Inc.
 ** user.h 1.4, last change 7/18/90
 **/

#ifndef _USER_
#ifdef __cplusplus
extern "C" {
#endif
#define	_USER_

struct user {
	int	u_error;
	int	u_uid;
	int	u_gid;
	int	u_ruid;
	int	u_rgid;
	short	* u_ttyp;
	struct proc	* u_procp;
};

extern struct user	u;

#ifdef __cplusplus
};
#endif
#endif
       
