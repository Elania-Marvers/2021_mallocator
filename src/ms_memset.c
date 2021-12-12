#include "lib_alloc.h"

void * ms_memset( void * pointer, 
				  int value, 
				  size_t count )
{
    unsigned char *dst;
    dst = pointer;
    while (count > 0) 
    {
        *dst = (unsigned char) value;
        dst++;
        count--;
    }
    return pointer;	
}
