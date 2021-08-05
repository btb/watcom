#include <sys\stat.h>
#include <sys\types.h>
#include <fcntl.h>
#include <share.h>

void main()
  {
    int handle;

    /* open a file for output		       */
    /* replace existing file if it exists      */

    handle = sopen( "file",
		O_WRONLY | O_CREAT | O_TRUNC,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP,
		SH_DENYWR );

    /* read a file which is assumed to exist   */

    handle = sopen( "file", O_RDONLY, SH_DENYWR );

    /* append to the end of an existing file   */
    /* write a new file if file does not exist */

    handle = sopen( "file",
		O_WRONLY | O_CREAT | O_APPEND,
		S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP,
		SH_DENYWR );
  }
