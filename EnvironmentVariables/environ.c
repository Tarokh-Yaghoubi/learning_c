

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char **environ;


// Use getenv() cause it is more portable.
// But it is also possible to use environ.
// and also it is possible to take the env variables as a third parameter from main():
// main(int argc, char **argv, char **env);  // But this is even less portable 

int
main(void) {
	
	for (char **p = environ; *p != NULL; p++)
		printf("%s\n", *p);

	// or you could do this
	
	for (int i = 0; environ[i] != NULL; i++) {
		printf("%s\n", environ[i]);
	}

	return EXIT_SUCCESS;
}

