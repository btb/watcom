#include <stdio.h>
#include <dos.h>

void main()
  {
    struct diskfree_t disk_data;

    /* get information about drive 3 (the C drive) */
    if( _dos_getdiskfree( 3, &disk_data ) == 0 ) {
      printf( "total clusters: %u\n",
			disk_data.total_clusters );
      printf( "available clusters: %u\n",
			disk_data.avail_clusters );
      printf( "sectors/cluster: %u\n",
			disk_data.sectors_per_cluster );
      printf( "bytes per sector: %u\n",
			disk_data.bytes_per_sector );
    } else {
      printf( "Invalid drive specified\n" );
    }
  }
//************ Sample program output ************
//total clusters: 16335
//available clusters: 510
//sectors/cluster: 4
//bytes per sector: 512
