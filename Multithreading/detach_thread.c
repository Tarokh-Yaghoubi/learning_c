
#include "../requirements.h"
#include <threads.h>


#define THREAD_MAX 5

int run(void* arg) {
	(void)arg;
	
	printf("Thread Running ID -> %lu\n", thrd_current()); // this is not portable
	// because the spec does not say what is the type of a thrd_t under the hood.
	// it could even be a struct... not an unsigned int 
	
	printf("Thread Running -> \n");

	return 0;
}

// Some threads may have duplicate ID's in this way
// C is allowed to reuse thread ID's after the corresponding thread has exited 
// So some threads may finish their run before others are lunched

int main(void) {
	thrd_t t;
	
	for (int i = 0; i < THREAD_MAX; i++) {
		thrd_create(&t, run, NULL);
		thrd_detach(t);	// cause we are detaching we do not need another thrd_t for the next thread creation
		// we just overwrite it.
	}
	
	thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);


	return EXIT_SUCCESS;
}
