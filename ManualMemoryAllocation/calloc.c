
// An Alternative: calloc()
// It has two key differences with malloc()
// Instead of a single argument you pass the size of one element and the number of 
// elements you wish to allocate its like it is made for allocating arrays.
//
// ALSO, it CLEARS the memory to zero, (no need for memset() )
// you still have to use free()
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	// This is how we use calloc();
	int* p = calloc(20, sizeof(int));

	// This is equivalent to the one above, here memset is a force if you wanna set to 0. 
	int* q = malloc(sizeof(int) * 20);
	memset(q, 0, (sizeof(int)*20));

	if (p == NULL)
		exit(EXIT_FAILURE);
	// The result is the same for both, but calloc is easier to use here.

	free(p);
	free(q);

	return EXIT_SUCCESS;
}

