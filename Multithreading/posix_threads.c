
#include "../requirements.h"
#include <threads.h>

// C11, introduced multithreading to the C language.
// It is very similar to POSIX threads.
// If a C11+ compiler defines __STDC_NO_THREADS__, threads will not be 
// present in the library.

#ifdef __STDC_NO_THREADS__
#error I need threads to build this program! 
#endif

// Also you might need to specify certain linker options when building. In the case of 
// Unix-likes, try appending a -lpthreads to the end of the command line to link
// the pthreads library.
// gcc -std=c11 -o foo foo.c -lpthreads
//
// If you get linker errors, that could be because the appropriate library is not imported


#define THREAD_COUNT 5

int run(void * arg) {

	int a = *(int*)arg;
	
	free(arg);

	printf("THREAD: running thread with arg -> %d\n", a);

	return a;

}


int main(void) {

	// we have thread local storage, mutexes, conditional variables
	// thrd_t is a unique identifer per thread
	// if you do not thrd_join after the thread for the sake of cleanup
	// you'll leak memory,
	// unless you call thrd_detach()

	// instead of this array i could use malloc()
	
	// int tp[THREAD_COUNT];
	thrd_t t[THREAD_COUNT];
	int i;

	printf("Launching threads... \n");

	for (i = 0; i < THREAD_COUNT; i++) {
		int* arg = malloc(sizeof(*arg));
		*arg = i;	
		thrd_create(t + i, run, arg);
	
	}

	printf("Doing other things while the thread runs... \n");
	printf("Waiting threads to complete ... \n");

	for (int i = 0; i < THREAD_COUNT; i++) {
		int res;
		thrd_join(t[i], &res);
		printf("T data -> %ld\n", (long)t[i]);
		printf("THREAD %d completed...\n", res);
	}

	printf("All threads completed...\n");

	return EXIT_SUCCESS;
}

