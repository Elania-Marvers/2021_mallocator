#include "lib_alloc.h"

void ms_merge (block_meta_t *block)
{
  block->size += block->next->size;
  block->next = block->next->next; 
}