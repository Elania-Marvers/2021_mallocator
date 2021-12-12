#include "lib_alloc.h"

block_meta_t *get_block_ptr(void *ptr) 
{
  return (block_meta_t *) ptr - 1;
}