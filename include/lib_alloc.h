#define __USE_GNU
#define _GNU_SOURCE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <dlfcn.h>
#include <assert.h>
#include <errno.h>




typedef struct block_meta_s
{
  size_t size;
  struct block_meta_s *next;
  int free;
} block_meta_t;
#define META_SIZE sizeof(block_meta_t)
extern void *global_base;



void *ms_memset( void * pointer, int value, size_t count );
void ms_memcpy(void		*dest, void		*src, size_t	n);
void *malloc (size_t size);
void *calloc (size_t nmemb, size_t size);
void *realloc(void *ptr, size_t size);
void free (void *ptr);
size_t malloc_usable_size (void *ptr);







//under function for malloc
block_meta_t *find_free_block(block_meta_t **last, size_t size);
block_meta_t *request_space(block_meta_t *last, size_t size);
void split_block(block_meta_t *b, size_t s);
void ms_merge (block_meta_t *block);
block_meta_t *get_block_ptr(void *ptr);




