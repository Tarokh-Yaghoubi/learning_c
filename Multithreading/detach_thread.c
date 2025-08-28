
#include "../requirements.h"
#include <threads.h>


#define THREAD_MAX 5

int run(void* arg) {
	(void)arg;
	
	printf("Thread Running -> \n");

	return 0;
}


int main(void) {
	thrd_t t;
	
	for (int i = 0; i < THREAD_MAX; i++) {
		thrd_create(&t, run, NULL);
		thrd_detach(t);
	}
	
	thrd_sleep(&(struct timespec){.tv_sec=1}, NULL);


	return EXIT_SUCCESS;
}
