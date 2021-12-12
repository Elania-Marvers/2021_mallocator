#include "lib_alloc.h"

void		ms_memcpy(void		*dest,
          			  void		*src,
          			  size_t	n)
{
  char *csrc;
  char *cdest;
  csrc = (char *)src;
  cdest = (char *)dest;
  
  int i;
  i = 0;
  
  while (i != n)
    {
      cdest[i] = csrc[i];
      i++;
    }
}