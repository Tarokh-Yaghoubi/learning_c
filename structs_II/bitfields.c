

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is not rarely used. but this might become useful on lower-level applications.

struct foo {
	unsigned int a:5;
	unsigned int b:5;
	unsigned int c:3;
	unsigned int d:3;
};


// Only adjacent bit-firlds are combined, and cause here they are interrupted
// with non-bit-fields, we get no savings...
struct nonAdjacent {

	unsigned int a:1;
	unsigned int b;
	unsigned int c:1;
	unsigned int d;
};	// This is actually  16 bytes, same as usual.

// A rearrangement can yield to some space savings:

struct someSpaceSaving {
	unsigned int a:1;
	unsigned int c:1;
	unsigned int b;
	unsigned int d;
};

// Unnamed BitFields
// Here we use the top two bits and the bottom one bit, and we are not going to 
// use the middle five bits 

struct unnamedBits {

	unsigned char a:2;
	unsigned char :5;	// Unnamed bit-field
	unsigned char b:1;
};

int main(void) {

	// Here we get 4 bytes, but we might also get 2 bytes
	// depends on the compiler and the platform.
	printf("%zu\n", sizeof(struct foo));
	printf("%zu\n", sizeof(struct nonAdjacent));
	printf("%zu\n", sizeof(struct someSpaceSaving)); // 12 on my system
	printf("Unnamed bitfield size -> %zu\n", sizeof(struct unnamedBits));
	return EXIT_SUCCESS;
}
