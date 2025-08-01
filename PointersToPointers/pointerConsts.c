

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int x = 23;
	int* const p = &x;	// this means you cannot change the value of p
				// for example p++ will give an error.
				// COMPILE-TIME ERROR
	int **q = &p;
i
	return EXIT_SUCCESS;
}
