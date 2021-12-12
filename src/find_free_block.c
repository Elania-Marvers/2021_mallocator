#include "lib_alloc.h"


block_meta_t *find_free_block(block_meta_t **last, size_t size)
{
  bool END;
  END = false;
  block_meta_t *current;
  current = global_base;
  while (current != NULL && END == false) 
    {
      if (current->free == 1 && current->size >= size && (current->size - size) > META_SIZE)
	END = true;
      else
	{
	  *last = current;
	  current = current->next;
	}
    }

  return current;
}

