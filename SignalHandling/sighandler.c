

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>


int count = 0;

void sigint_handler(int signum) {

	// This is a portable code which also gets along with the ancient UNIX behaviours.
	// In ancient UNIX behaviour, once a signal was delivered, the handler would reset to the default action 
	// which, for SIGINT is to terminate the program.
	
	// That means the handler would only run once.

	signal(SIGINT, sigint_handler);

	(void)signum;	 // get rid of unused variable warning
	
	
	count++;

	printf("Count : %d\n", count);

	if (count == 2) {
		printf("Exiting...");
		exit(EXIT_SUCCESS);
	}
}


int main() {
	signal(SIGINT, sigint_handler);
	printf("Try hitting CTRL-c...\n");
	for (;;);

}

