
#include <stdio.h>

// this will not work because we need to compile the two files together and
// it is not possible in this example cause we have two definitions for main()

extern int onlyint;

int main() {

	printf("%d\n", onlyint);	// from the other file static.c 
	
	onlyint = 34;

	// same a at static.c but now we have changed its value 
	
	printf("%d\n", onlyint);

	return 0;
}
