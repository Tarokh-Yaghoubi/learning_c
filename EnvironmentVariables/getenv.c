

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int
main(void) {

	int ret = 0;
	char *val = getenv("HOSTNAME");
	char *notset = getenv("TUX");

	if (val == NULL) {
		perror("getenv");
		return EXIT_FAILURE;
	}

	printf("%s\n", val);

	// Here the program gets a copy of the environment,
	// so we cannot see TUX In envvariables after the program 
	// runs. but we have access to that variable while the program
	// is alive.
	

	// when the program ends, all changes are lost.
	if (notset == NULL) {
		ret = setenv("TUX", "LINUX IS HERE!", 1);
		if (ret == 0) {
			char *tux = getenv("TUX");
			printf("%s\n", tux);
			return EXIT_SUCCESS;
		} else {
			printf("Error while setting env variable\n");
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;

}

