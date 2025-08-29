

#include "../requirements.h"
#include <threads.h>

int global_var = 0;

int first_thread(void* args) {
	
	int arg = *(int*)args;
	
	while(global_var <= 100) {
		global_var++;
		printf("Thread[%d] incremented global_var -> %d\n", arg, global_var);
		
	}
	return 0;
}

int second_thread(void* args) {
	int arg = *(int *)args;
	
	while (global_var <= 100) {
		global_var++;
		printf("Thread[%d] incremented global_var -> %d\n", arg, global_var);
		
	}
	return 0;
}

#define THREAD_MAX 2

int main() {

	int id1 = 300, id2 = 500;
	thrd_t first, second;
	thrd_create(&first, first_thread, &id1);
	thrd_create(&second, second_thread, &id2);

	thrd_join(first, NULL);
	thrd_join(second, NULL);
		
	return 0;
}

