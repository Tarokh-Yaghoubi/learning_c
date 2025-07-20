#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int 
main(int argc, char **argv) {

	int total = 0, value = 0;
	(void)argc;	// a way to make compiler silent cause we're not
			// using argc.

	for (char **p = argv + 1; *p != NULL; p++) {
		value = atoi(*p);
		total += value;
	}

	printf("%d\n", total);
}
