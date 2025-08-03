
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	// these are different ways to define or detect NULL pointers in C
	void* ptr = (void *)0;
	ptr = 0;
	ptr = '\0';
	ptr = NULL;

	if (ptr == NULL) {
		printf("ptr is null here\n");
	}


	return 0;

}
