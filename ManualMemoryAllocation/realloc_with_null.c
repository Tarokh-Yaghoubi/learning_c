
#include <stdio.h>
#include <stdlib.h>

#include <string.h>

// These two lines are the same
void realloc_null() {
	char* p = malloc(2342);
	char* q = realloc(NULL, 2342);
}

void
main() {
	int* p = NULL;
	int length = 0;

	// Here, cause p is NULL to start, we can use realloc
	// instead of malloc() to initialize.
	
	while (!done) {
		length += 10;
		p = realloc(p, sizeof(*p) * length);
	}

}
