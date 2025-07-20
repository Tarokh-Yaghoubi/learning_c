

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// After the last string, argv is a pointer to NULL
// argv[argc] == NULL is always true

// char *argv[] == char **argv
// These are equivalent, you can use them both


int
main(int argc, char **argv) {

	// pointer to a pointer-to-char
	// 

	int total = 0;
	int value = 0;
	for (int i = 1; i < argc; i++) {
		value = atoi(*(argv + i));
		total += value;
	}

	printf("TOTAL -> %d\n", total);

	return EXIT_SUCCESS;
}


