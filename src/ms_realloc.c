#include "lib_alloc.h"

void *ms_realloc(void *ptr, size_t size)
{
  if (ptr == NULL) 
    return malloc(size);
  

  block_meta_t *block_ptr;
  block_ptr = get_block_ptr(ptr);


  if (block_ptr->size >= size)
  {
    split_block(block_ptr, size);
    return ptr;
  }


  void *new_ptr;
  new_ptr = malloc (size);

  if (new_ptr == NULL)
    return NULL; 
  
  ms_memcpy(new_ptr, ptr, block_ptr->size);
  free(ptr);
  return new_ptr;
}


ssize_t (*orig_realloc)(void *ptr, size_t size) = NULL;
void *realloc(void *ptr, size_t size)
{
  if (!orig_realloc)
    orig_realloc =  dlsym(RTLD_NEXT, "realloc");
  return ms_realloc(ptr, size);
}