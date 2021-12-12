#include "lib_alloc.h"

void *ms_calloc (size_t nmemb, size_t size)
{
  void *p;
  p = malloc (nmemb * size);
  if (p != NULL)
    p = ms_memset (p, 0, size * nmemb);
  return p;
}

ssize_t (*orig_calloc)(size_t nmemb, size_t size) = NULL;
void *calloc (size_t nmemb, size_t size)
{
  if (!orig_calloc)
    orig_calloc =  dlsym(RTLD_NEXT, "calloc");
  return ms_calloc(nmemb, size);
}