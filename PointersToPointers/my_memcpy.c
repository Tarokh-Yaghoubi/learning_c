
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void* my_memcpy(void* dst, const void* src, size_t n)
{
	const unsigned char* s = src;
	unsigned char* d = dest;

	while (n-- > 0)		// for the given number of bytes
		*d++ = *s++;	// copy src files to dest files
	
	// Most copy functions return a pointer to the destination as a convenience to the caller.
	
	return dest;
}

int
main() {





	return EXIT_SUCCESS;
}
