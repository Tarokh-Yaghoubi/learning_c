
#define THREAD_MAX 5

#include "../requirements.h"
#include <threads.h>

// Thread-Specific Storage - TSS
// It is another way of getting per-thread data.

tss_t str;

void some_func(void) {

	// Retrieve the per-thread value of this string
	char* tss_string = tss_get(str);
	
	printf("TSS String: %s\n", tss_string);
}


int run(void* arg) {
	
	int serial = *(int*)arg;	// get this threads serial number
	
	free(arg);
	
	char* s = malloc(sizeof(*s) * 64);	// or simply 64 XDDD
	
	sprintf(s, "thread %d!", serial);
	
	tss_set(str, s);
	
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
	
	tss_delete(str);

}



