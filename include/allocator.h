/*
 * Module for handling memory allocation and related errors.
 */
#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include "result.h"

#include <stdlib.h>

/*
 * Allocates memory for given size and saves allocation result code in the
 * second parameter. This way it can return allocated memory while also
 * returning the result of the operation.
 */
void *allocate_memory(size_t size, Result *result);

/*
 * Free memory in given pointer and saves operation result in result param.
 */
void free_memory(void *ptr, Result *result);

#endif // !ALLOCATOR_H
