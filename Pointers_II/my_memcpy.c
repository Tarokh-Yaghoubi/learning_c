#include <stdio.h>
#include "my_memcpy.h"

void* my_memcpy(void* dest, void* src, int bytecount) {
	char* s = src, *d = dest;

	while (bytecount--)
		*d++ = *s++;

	return dest;

}
