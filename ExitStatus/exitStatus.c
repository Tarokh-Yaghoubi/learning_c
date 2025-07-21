

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// C has two MACROS for exit status values -> EXIT_SUCCES, EXIT_FAILURE

int main(int argc, char **argv) {


	if (argc != 3) {
		printf("Usage: mult x y\n");
		return EXIT_FAILURE;

	}

	printf("%d\n", atoi(argv[1]) * atoi(argv[2]));
	return EXIT_SUCCESS;
}
