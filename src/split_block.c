#include "lib_alloc.h"

void split_block(block_meta_t *b, size_t s) 
{
  block_meta_t *new_block;
  new_block = (void *) b + s;
  new_block->next = b->next;

  new_block->size = s;
  b->size -= s;
  b->next = new_block;
  new_block->free = 0;
  b->free = 0;
}