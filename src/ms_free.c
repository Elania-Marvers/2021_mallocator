#include "lib_alloc.h"

void ms_free (void *p)
{
  if (p == NULL)
    return;

  block_meta_t* block_ptr;
  block_ptr = get_block_ptr(p);

  assert(block_ptr->free == 0);
  block_ptr->free = 1;

  if (block_ptr->next != NULL)
    if (block_ptr->next->free == 1)
      ms_merge(block_ptr);

}

ssize_t (*orig_free)(void *ptr) = NULL;
void free (void *ptr)
{
  if (!orig_free)
    orig_free =  dlsym(RTLD_NEXT, "free");
  return ms_free(ptr);
}