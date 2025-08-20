

#include "../requirements.h"


jmp_buf env;	// global env var to keep the state of things


void depth2(void) {

	printf("Entering depth 2 \n");
	longjmp(env, 3490);	// Bail out
	printf("Leaving depth 2\n");	// This won't happen
}

void depth1(void) {
	printf("Entering depth 1\n");
	depth2();
	printf("Leaving depth 1\n");// This won't happen
}

int main() {

	switch(setjmp(env)) {
		case 0:
			printf("Calling into functions, setjmp() returned 0\n");
			depth1();
			printf("This won't happen\n");
			break;
		case 3490:
			printf("Bailed back to main, setjmp() returned 3490\n");
			break;
	}

	return EXIT_SUCCESS;

}
