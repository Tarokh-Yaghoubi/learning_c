

#include "../requirements.h"
#include <threads.h>

mtx_t serial_lock;

int run(void * arg) {
	
	(void)arg;

	static int serial = 0;	// shared static variable 
	

	mtx_lock(&serial_lock);

	// between mtx_lock and unlock is the critical section 
	// where we don't want multiple threads to interfere

	printf("Thread running... %d\n", serial);

	serial++;

	mtx_unlock(&serial_lock);

	// NOTE: If you have multiple MUTEXES, always unlock them in the opposite 
	// order which you locked them.

	// NOTE: There are few mutex types that you can create with mtx_init()
	// some of them can be a result of a bitwise OR operation:
	
	// mtx_plain	->	Regular Mutex
	// mtx_times	->	Mutex that supports timeouts 
	// mtx_plain | mtx_recursive	->	Recursive Mutex
	// mtx_timed | mtx_recursive	-> 	Recursive Mutex that supports timeouts
	
	// explaining deadlocks later...

	return 0;

}

#define THREAD_MAX 10

int main() {

	// if you want to only allow a single thread in a critical section 
	// of code at a time, you protect that section with a mutex.
	

	// you can start with mtx_init,  then mtx_lock and mtx_unlock
	// we can also destroy it with mtx_destroy, oposite logic of mtx_init.

	mtx_init(&serial_lock, mtx_plain);	// <-- CREATE MUTEX

	thrd_t t[THREAD_MAX];

	for (int i = 0; i < THREAD_MAX; i++)
		thrd_create(t + i, run, NULL);

	for (int i = 0; i < THREAD_MAX; i++)
		thrd_join(t[i], NULL);


	mtx_destroy(&serial_lock);	// <-- DESTROY-MUTEX

	return 0;
}

