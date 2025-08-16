

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>


int count = 0;

void sigint_handler(int signum) {
/*
	signal(SIGINT, sigint_handler);

	(void)signum;	 // get rid of unused variable warning
	
*/

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

