

// static: this one has two meanings:
// depends on if if the variable is file scope or block scope

// static in block scope

#include <stdio.h>


// static in file scope means that this variable is global and visible to all functions
// but only in this file...


// testing extern in extern.c
int onlyint = 23;


static char c;
static int first;
static float FN;

void counter(void) {
	static int count = 1;

	printf("%d time\n", count);

	count++;
}

int main() {
	counter();
	counter();
	counter();

	return 0;
}

