

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <signal.h>
#include <unistd.h>

// this is just a pointer to a function
// return_type (*pointer_name)(parameter_types);
static void (*old_handler)(int) = NULL;


void sigint_handler(int signum) {

	signal(SIGINT, sigint_handler);	// re-installing handler

	(void)signum;

	// use write: because it is async-signal-safem safer than printf inside a handler 
	write(STDOUT_FILENO, "Custom handler: caught SIGINT\n", 30);

	if (old_handler && old_handler != SIG_DFL && old_handler != SIG_IGN) {
		old_handler(signum);
	} else if (old_handler == SIG_DFL) {
		signal(SIGINT, old_handler);
		raise(SIGINT);
	} else {
		exit(1);
	}
}

