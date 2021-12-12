#include "lib_alloc.h"
void *global_base = NULL;


void *ms_malloc (size_t size)
{
  block_meta_t *block;
  size_t nsi;

  nsi = (size + META_SIZE);
  size = nsi + (getpagesize())%nsi ;

  if (size <= 0)
    return NULL;

  if (global_base == NULL) 
    { 
      block = request_space(NULL, size);
      if (block == NULL)
	return NULL;
      global_base = block;
    } 
  else 
    {
      block_meta_t *last = global_base;
      block = find_free_block(&last, size);
      if (block == NULL) 
	{ 
	  block = request_space(last, size);
	  if (block == NULL)
	    return NULL;
	} 
      else 
	{
	  split_block (block, size);
	  block->free = 0;
	}
    }

  return(block+1);

}



ssize_t (*orig_malloc)(size_t size) = NULL;
void *malloc(size_t size)
{
  if (!orig_malloc)
    orig_malloc =  dlsym(RTLD_NEXT, "malloc");
  return ms_malloc(size);
}











