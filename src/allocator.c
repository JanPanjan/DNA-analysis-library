#include "../include/allocator.h"

#include <stdlib.h>
#include <string.h>

void *_allocate_memory_(size_t size, Result *result) {
  void *ptr = malloc(size);

  if (ptr == NULL) {
    *result = (Result){MEMORY_ALLOCATION_FAIL, __LINE__, __FILE__,
                       "pointer is null after attempt of allocation."};
    return NULL;
  }

  *result = (Result){RESULT_SUCCESS, __LINE__, __FILE__,
                     "Successfully allocated pointer"};
  return ptr;
}

void _free_memory_(void *ptr, Result *result) {
  if (ptr == NULL) {
    *result = (Result){MEMORY_FREE_NULL_PTR, __LINE__, __FILE__,
                       "Pointer is already null, 'free' is not allowed."};
    return;
  }

  free(ptr);
  ptr = NULL;
  *result = (Result){RESULT_SUCCESS, __LINE__, __FILE__,
                     "Successfully freed the pointer"};
}
