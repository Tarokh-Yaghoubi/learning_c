

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// we include stdargs to play with variadic function in C:
#include <stdarg.h>


void func(int first, ...) {
	printf("INTEGERS -> %d\n", first);
	// OK, but how do we get the other arguments ? 
	//  HERE'S IS HOW:
	// you are going to include <stdargs.h>
	
}

int add(int count, ...) {
	// sum all the numbers you get from params together
	int total = 0;
	va_list va;	// variable argument list.

	va_start(va, count);	// Start with arguments after count
	
	for (int i = 0; i < count; ++i) {
		int n = va_arg(va, int);	// take the next arg 
		total += n;
	}

	va_end(va);	// ALL DONE

	return total;
}


int
main() {


	func(10, 11, 12, 13, 14, 15);
	// Variadic functions in C must at least have one arg

	printf("SUM 1 -> %d\n", add(5, 1, 2, 3, 4, 5));
	printf("SUM 2 -> %d\n", add(2, 25, 26));

	return EXIT_SUCCESS;
}

