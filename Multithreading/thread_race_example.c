

#include "../requirements.h"
#include <threads.h>

#define THREAD_MAX 5

int run(void *arg) {

	int n = *(int *)arg;
	free(arg);

	// In this way, each thread will have its own 'foo' static variable, they shall not interfere eachother.	
	_Thread_local static int foo = 10;	// this is shared
	// same as: thread_local static int foo = 10;
	// NOTE: you can use thread_local which is a typedef for _Thread_local so you'll keep your code less uglier
	
	// NOTE: if a thread_local variable is in block-scope it must be static, cause a non-static block-scope variable 
	// is already safe, cause they're "per thread" already, since each thread has its own non-static variables.
	
	
	
	int x = foo;	// this is not shared among other threads - this is local 
	// in this example - foo may change sooner by another thread, and our condition x != foo
	// my fail
	
	printf("Thread: %d, X = %d, foo = %d\n", n, x, foo);

	if (x != foo) {
		printf("Thread %d: Craziness! x != foo! %d != %d\n", n, x, foo);
	}
	
	foo++; // increment shared value
	
	return 0;
}

int main() {
	thrd_t t[THREAD_MAX];
	
	for (int i = 0; i < THREAD_MAX; i++) {
		int* n = malloc(sizeof(*n)); // fod holding a thread serial number
		*n = i;
		thrd_create(t + i, run, n);
	
	}

	for (int i = 0; i < THREAD_MAX; i++)
		thrd_join(t[i], NULL);
	
	return 0;
}

