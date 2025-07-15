
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main(void) 
{
	// Alignment must be a power of 2.
	// size must be a multiple of alignment (here 64)
	// aligned_alloc(alignment, size);


	// If this size is not a multiple of alignment,
	// the function failes and returns NULL.
	// or crashes on some systems...
	char* p = aligned_alloc(64, 128); // 128 == 64 * 2
	
	strcpy(p, "This is C programming - RUN");
	printf("%s\n", p);

	free(p);

	return EXIT_SUCCESS;

}
