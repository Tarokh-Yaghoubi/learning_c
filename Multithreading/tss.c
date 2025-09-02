
#define THREAD_MAX 5

#include "../requirements.h"
#include <threads.h>

// Thread-Specific Storage - TSS
// It is another way of getting per-thread data.

tss_t str;	// GLOBAL TSS KEY -> Like a locker number 

void some_func(void) {

	// Retrieve the per-thread value of this string
	// Here we get the value of str, which we set in the thread
	char* tss_string = tss_get(str);
	
	printf("TSS String: %s\n", tss_string);
}


int run(void* arg) {
	
	// this is my thread function 
	
	int serial = *(int*)arg;	// get this threads serial number
	
	free(arg);
	
	// I allocated some memory for holding my string, and used sprintf to populate 's' with some data.
	char* s = malloc(sizeof(*s) * 64);	// or simply 64 XDDD
	sprintf(s, "thread %d!", serial);
	
	// now I set the 'str' locker ("key") to the value of 's' which is ("thread %d", serial) - 'i took serial from thrd_create data field'
	// NOTE: str is not actually storing data, It's more like a key that each thread uses to access its own private storage slot.
	
	tss_set(str, s); // Stores THIS threads string in ITS slot.
	
	/*
		NOW here is the magic, when Thread 0 calls tss_set(str, s), it stores "thread 0!" in Thread 0's private slot.
		When Thread 1 calls tss_set(str, s); it stores "thread 1!" in Thread 1's private slot. They're using the same 
		variable name  " str ", but accessing completely separate storage.
	
	*/
	
	
	// here i call the some_func() function
	some_func();
	
	return 0;

}

int main() {	

	thrd_t t[THREAD_MAX];
	
	// make a new tss variable, the free function is the destructor
	tss_create(&str, free);
	
	for(int i = 0; i < THREAD_MAX; i++) {
		int* n = malloc(sizeof(*n));
		*n = i;
		thrd_create(t + i, run, n);
	}
	
	for (int i = 0; i < THREAD_MAX; i++) {
		thrd_join(t[i], NULL);
	}

	// We're done with this when all the threads are done.
	tss_delete(str);

}



