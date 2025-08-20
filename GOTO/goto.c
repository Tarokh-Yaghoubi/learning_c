

#include <stdio.h>
#include <unistd.h>

int main() {
	
	printf("One\n");
	printf("Two\n");

	goto skip_3;

	printf("Three\n");

skip_3:
	printf("Four\n");

infinite_loop:
	printf("ERROR!\n");
	goto infinite_loop;

	return 0;

}

// Restarting interrupted systemcalls.

void recall_syscall(void) {

retry:
	FILE*  file;
	file = fopen("file.txt", "a+");
	if (file == NULL) {
		printf("Could Not open the file -- retrying... ");
		sleep(2);
		goto retry;
	}
}

