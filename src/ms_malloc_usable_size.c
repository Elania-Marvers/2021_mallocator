#include "lib_alloc.h"

size_t ms_malloc_usable_size (void *ptr)
{
  return ((block_meta_t *) ptr)->size;
}

ssize_t (*orig_malloc_usable_size)(void *ptr) = NULL;

size_t malloc_usable_size (void *ptr)
{
  if (!orig_malloc_usable_size)
    orig_malloc_usable_size =  dlsym(RTLD_NEXT, "malloc_usable_size");
  return ms_malloc_usable_size(ptr);
}