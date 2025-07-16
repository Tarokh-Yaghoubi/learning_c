

// realloc does not have any alignment guarantees. so if you need to get some aligned 
// reallocated space, you'll have to do it the hard way with memcpy().


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* aligned_realloc(void* ptr, size_t old_size, size_t alignment, size_t size)
{
	char* new_ptr = aligned_alloc(alignment, size);

	if (new_ptr == NULL)
		return NULL;

	size_t copy_size = old_size < size ? old_size : size;
	
	if (ptr != NULL)
		memcpy(new_ptr, ptr, copy_size);

	free(ptr);

	return new_ptr;

}

