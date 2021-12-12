#include "lib_alloc.h"

block_meta_t *request_space(block_meta_t *last, size_t size) 
{
  block_meta_t *block;
  void *request;
  block = sbrk (0);
  request = sbrk (META_SIZE + size);
  assert((void *) block == request); 

  if (request == (void *) -1)
    return NULL; 

  if (last != NULL)
    last->next = block;
  

  block->size = size;
  block->next = NULL;
  block->free = 0;
  return block;
}



