#include <stdio.h>
#include <malloc.h>

heap_dump()
  {
    struct _heapinfo h_info;
    int heap_status;

    h_info._pentry = NULL;
    for(;;) {
      heap_status = _heapwalk( &h_info );
      if( heap_status != _HEAPOK ) break;
      printf( "  %s block at %Fp of size %4.4X\n",
	(h_info._useflag == _USEDENTRY ? "USED" : "FREE"),
	h_info._pentry, h_info._size );
    }

    switch( heap_status ) {
    case _HEAPEND:
      printf( "OK - end of heap\n" );
      break;
    case _HEAPEMPTY:
      printf( "OK - heap is empty\n" );
      break;
    case _HEAPBADBEGIN:
      printf( "ERROR - heap is damaged\n" );
      break;
    case _HEAPBADPTR:
      printf( "ERROR - bad pointer to heap\n" );
      break;
    case _HEAPBADNODE:
      printf( "ERROR - bad node in heap\n" );
    }
  }

void main()
  {
    char *p;
    heap_dump();   p = (char *) malloc( 80 );
    heap_dump();   free( p );
    heap_dump();
  }
//************ Sample program output ************
//
//OK - heap is empty
//  USED block at 23f8:0ab6 of size 0202
//  USED block at 23f8:0cb8 of size 0052
//  FREE block at 23f8:0d0a of size 1DA2
//OK - end of heap
//  USED block at 23f8:0ab6 of size 0202
//  FREE block at 23f8:0cb8 of size 1DF4
//OK - end of heap
//
//
//OK - heap is empty
//  USED block at 0014:00002a7c of size 0204
//  USED block at 0014:00002c80 of size 0054
//  FREE block at 0014:00002cd4 of size 1D98
//OK - end of heap
//  USED block at 0014:00002a7c of size 0204
//  FREE block at 0014:00002c80 of size 1DEC
//OK - end of heap
//
