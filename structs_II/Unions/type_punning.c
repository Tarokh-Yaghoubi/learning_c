

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

union foo {

	float b;
	short a;
}

int main() {

	union foo x;
	x.b = 2.12;

	printf("%f\n", x.b);
	printf("%d\n", x.a);

	// Unions in C refere to the same memory location.
	// So 'a' and 'b' refer to the same memory location.
	// when we read 'a' we are reading the first 2 bytes of float 'b'
	// as if they were a short.
	return EXIT_SUCCESS;
}
