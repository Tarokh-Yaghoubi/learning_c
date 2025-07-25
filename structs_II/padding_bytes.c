
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct foo {
	int a;
	char b;
	int c;
	char d;
};

int main(void) {

	printf("%zu\n", sizeof(int) + sizeof(char)
			+ sizeof(int) + sizeof(char));
	
	// Here the compiler adds 6 bytes of padding,
	// to help it be more performant
	
	printf("%zu\n", sizeof(struct foo));

	return EXIT_SUCCESS;
}
