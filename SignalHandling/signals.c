
// your program can be configured to be interrupted to handle a signal
// and optionally continue where it left off once the signal has been handled 
//
// On a unix-like system (or windows) we have a lot of signals 
// but in the C spec they are just a few:
//
// SIGABRT -> like when abort is called - Abnormal Termination
// SIGFPE -> floating point exception
// SIGILL -> Illegal Instruction
// SIGINT -> Intrerrupted - Usually the result of CTRL-C
// SIGSEGV -> Segmentation Violation - Invalid Memory Access
// SIGTERM -> Termination Requested

// You can set your program to ignore - handle - or allow the default action for each of these 
// by using the signal() function

// HANDLING SIGNALS using signal()

// signal() takes two params: the signal and the action to take, which can be a pointer to a signal handler 
// function, and it can be one of these two: SIG_IGN -> to ignore the signal, SIG_DFL -> to restore the 
// default handler for the signal.


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <signal.h> // This is necessary

void signum(int num) {
	printf("SIGNUM Is -> %d\n", num);
}

int main() {

	char s[1024];
	
	signal(SIGINT, signum);	// just ignore the SIGINT signal which is CTRL-c
	
	printf("Try hitting CTRL-c ... \n");

	fgets(s, sizeof(s), stdin);
}

