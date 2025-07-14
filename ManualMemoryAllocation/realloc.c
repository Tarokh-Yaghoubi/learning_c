
/*
	When you allocate 10 ints, but then you decide you need 20.
	One option is to allocate some new space, 
	and then memcpy() the memory over, but it turns out that sometimes 
	you dont need to move anything, and there is one function,
	that is just smart enough to do the right thing in all the right circumstances: 
	realloc().
*/


// realloc() takes a pointer to some previously-allocated memory (by malloc or calloc)
// and a new size for the memory region to be.

// It then shrinks the region, it might return the same pointer or a different one, 
// pointing to the same place.

// NOTE: realloc wants the number of bytes to allocate, and not the number of elements.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int number = 5;
	int* p = malloc(number * sizeof(int));
	if (p == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	int* np = realloc(p, 10 * sizeof(int));
	if (np == NULL) {
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	p = np;
	memset(p, 0, sizeof(int)* 10);
	for (int i = 0; i < 10; ++i)
		printf("[%p] --- [%d]\n", (void*)&p[i], p[i]);

	free(p);
	return EXIT_SUCCESS;

}

