

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compar(const void*, const void*);

int
main(void) {
	// You can put the data type that is required in the casting, 
	// inside to paranthesis in front of the expression:
	
	int first = 12;
	long int second = (long int) first + 19;	// we cast first to long int.
	
	// NOTE: More commonly you see a cast that is converting a void pointer type "void*"
	// into a specific pointer type so it can derefernced:
	// compar();


}

int 
compar(const void* first, const void* second) {

	if (*((const int*)first) > *((const int*) second)) return 1;
	if (*((const int*)first) < *((const int*)second)) return -1;
	return 0;
}



