/*
 *  stdio.h	Standard I/O functions
 *
 *  Copyright by WATCOM International Corp. 1988-1993.  All rights reserved.
 */
#ifndef _STDIO_H_INCLUDED
#ifdef __cplusplus
extern "C" {
#endif
#pragma pack(1);


#ifndef _SIZE_T_DEFINED_
#define _SIZE_T_DEFINED_
 typedef unsigned size_t;
#endif

#define NULL   0

#ifndef __VALIST
 #ifdef  __HUGE__
  typedef char __far *__va_list[1];
 #else
  typedef char *__va_list[1];
 #endif
 #define __VALIST
#endif

#ifdef __386__
 #define BUFSIZ 	4096
#else
 #define BUFSIZ 	512
#endif
#define _NFILES 	20	/* number of files that can be handled */
#define FILENAME_MAX	80

typedef struct	__iobuf {
	unsigned char	*_ptr;		/* next character position */
	int		_cnt;		/* number of characters left */
	unsigned char	*_base; 	/* location of buffer */
	unsigned	_flag;		/* mode of file access */
	int		_handle;	/* file handle */
	unsigned	_bufsize;	/* size of buffer */
	unsigned char	_ungotten;	/* character placed here by ungetc */
	unsigned char	_tmpfchar;	/* tmpfile number */
} FILE;

typedef long	fpos_t;

#if !defined(NO_EXT_KEYS) /* extensions enabled */
 #define FOPEN_MAX	_NFILES
 #define OPEN_MAX	FOPEN_MAX
 #define PATH_MAX	80
#else			/* extensions not enabled */
 #define FOPEN_MAX	(_NFILES-2)
#endif

extern	FILE   __near __iob[];
/*
 *  Define macros to access the three default file pointer (and descriptors)
 *  provided to each process by default.  They will always occupy the
 *  first three file pointers in each processes' table.
 */
#define stdin	((FILE *)&__iob[0])	/* standard input file	*/
#define stdout	((FILE *)&__iob[1])	/* standard output file */
#define stderr	((FILE *)&__iob[2])	/* standard error file	*/
#ifndef NO_EXT_KEYS	/* extensions enabled */
#define stdaux	((FILE *)&__iob[3])	/* standard auxiliary file  */
#define stdprn	((FILE *)&__iob[4])	/* standard printer file  */
#endif

/* values for _flag field in FILE struct and _iomode array */

#define _READ	0x0001	/* file opened for reading */
#define _WRITE	0x0002	/* file opened for writing */
#define _UNGET	0x0004	/* ungetc has been done */
#define _BIGBUF 0x0008	/* big buffer allocated */
#define _EOF	0x0010	/* EOF has occurred */
#define _SFERR	0x0020	/* error has occurred on this file */
#define _APPEND 0x0080	/* file opened for append */
#define _BINARY 0x0040	/* file is binary, skip CRLF processing */
#define _IOFBF	0x0100	/* full buffering */
#define _IOLBF	0x0200	/* line buffering */
#define _IONBF	0x0400	/* no buffering */
#define _TMPFIL 0x0800	/* this is a temporary file */
#define _DIRTY	0x1000	/* buffer has been modified */
#define _ISTTY	0x2000	/* is console device */
#define _DYNAMIC 0x4000 /*  FILE is dynamically allocated   */

#define EOF	    (-1)		/*  End of File/Error return code   */

#define SEEK_SET    0			/*  Seek relative to start of file  */
#define SEEK_CUR    1			/*  Seek relative to current positn */
#define SEEK_END    2			/*  Seek relative to end of file    */

#define L_tmpnam	13
#define TMP_MAX     (26*26*26)		/*  Max times tmpnam can be called  */

void	 clearerr( FILE *__fp );
int	 fclose( FILE *__fp );
int	 feof( FILE *__fp );
int	 ferror( FILE *__fp );
int	 fflush( FILE *__fp );
int	 fgetc( FILE *__fp );
int	 fgetpos( FILE *__fp, fpos_t *__pos );
char	*fgets( char *__s, int __n, FILE *__fp );
FILE	*fopen( const char *__filename, const char *__mode );
int	 fprintf( FILE *__fp, const char *__format, ... );
int	 fputc( int __c, FILE *__fp );
int	 fputs( const char *__s, FILE *__fp );
size_t	 fread( void *__ptr, size_t __size, size_t __n, FILE *__fp );
FILE	*freopen( const char *__filename, const char *__mode, FILE *__fp );
int	 fscanf( FILE*__fp, const char *__format, ... );
int	 fseek( FILE *__fp, long int __offset, int __whence );
int	 fsetpos( FILE *__fp, const fpos_t *__pos );
long int ftell( FILE *__fp );
size_t	 fwrite( const void *__ptr, size_t __size, size_t __n, FILE *__fp );
int	 getc( FILE *__fp );
int	 getchar( void );
char	*gets( char *__s );
void	 perror( const char *__s );
int	 printf( const char *__format, ... );
int	 putc( int __c, FILE *__fp );
int	 putchar( int __c );
int	 puts( const char *__s );
int	 remove( const char *__filename );
int	 rename( const char *__old, const char *__new );
void	 rewind( FILE *__fp );
int	 scanf( const char *__format, ... );
void	 setbuf( FILE *__fp, char *__buf );
int	 setvbuf( FILE *__fp, char *__buf, int __mode, size_t __size );
int	 sprintf( char *__s, const char *__format, ... );
int	 sscanf( const char *__s, const char *__format, ... );
FILE	*tmpfile( void );
char	*tmpnam( char *__s );
int	 ungetc( int __c, FILE *__fp );
int	 vfprintf( FILE *__fp, const char *__format, __va_list __arg );
int	 vprintf( const char *__format, __va_list __arg );
int	 vsprintf( char *__s, const char *__format, __va_list __arg );

#if !defined(NO_EXT_KEYS) /* extensions enabled */
 int	 fcloseall( void );
 FILE	*fdopen( int __handle, const char *__mode );
 int     _grow_handles( int __new_count );
 int	 fgetchar( void );
 int	 fputchar( int __c );
 FILE	*_fsopen( const char *__filename, const char *__mode, int __shflag );
 int	 flushall( void );
 int	 vfscanf( FILE *__fp, const char *__format, __va_list __arg );
 int	 vscanf( const char *__format, __va_list __arg );
 int	 vsscanf( const char *__s, const char *__format, __va_list __arg );
 int	 _bprintf( char *__buf, unsigned int __bufsize, const char *__fmt, ... );
 int	 _vbprintf( char *__s, unsigned int __bufsize, const char *__format, __va_list __arg );
#endif


#define clearerr(fp)	((fp)->_flag &= ~(_SFERR|_EOF))
#define feof(fp)	((fp)->_flag & _EOF)
#define ferror(fp)	((fp)->_flag & _SFERR)
#define getc(fp) \
	((fp)->_cnt<=0 \
	|| !((fp)->_flag&_BINARY) \
        || (fp)->_flag&_UNGET \
	? fgetc(fp) \
	: ((fp)->_cnt--,*(fp)->_ptr++))
#define putc(c,fp) \
	((fp)->_flag&_IONBF \
	|| !((fp)->_flag&_BINARY) \
	|| (fp)->_bufsize-(fp)->_cnt<=1 \
	? fputc(c,fp) \
	: ((*(fp)->_ptr=(unsigned char)(c))=='\n'&&(fp)->_flag&_IOLBF) \
	? fputc('\n',fp) \
	: ((fp)->_flag|=_DIRTY,(fp)->_cnt++,*(fp)->_ptr++))
#define getchar()	getc(stdin)
#define putchar(c)	putc(c,stdout)

#pragma pack();
#define _STDIO_H_INCLUDED
#ifdef __cplusplus
};
#endif
#endif
