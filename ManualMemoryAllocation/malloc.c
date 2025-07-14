// If you want something to percist longer than a particular block ? ? ?
// This is where manual memory management comes into play.

// You can tell C explicitly to allocate for you a certain number of bytes that you can use 
// as you please. and these bytes will remain allocated until you explicitly free that memory.

// NOTE: All the memory will get freed after program exits. 


// NOTE: Some systems allow you to allocate memory that persists after a program exits. 
// But It's system dependent.

// Automatic Local Variables are allocated on the "STACK"
// Manually Allocated Memory is on the "HEAP"

/*
	malloc() -> accepts a number of bytes to allocate - returns a void* to that block of 
	newly-allocated memory.
	Since it is a void* you can assign it into whatever pointer type that you want,
	normally this will correspond in some way to the umber of bytes you're allocating.
*/

// NOTE: It is undefined behavior to use a memory region after you free() it.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate_for_array(void)
{
	char* x = malloc(20);	// this is indeed an array of 2000 chars. 
	char* p = x;

	// we should use memset to initialize our manually allocated array of chars.
	memset(p, '0', (sizeof(char) * 20));
	for (int i = 0; i < 20; ++i)
		printf("[%p] --- [%c]\n", p, *p++);

	free(x);
}

int main(void)
{
	char* c;
	char* temp;

	int* p = malloc(sizeof(int));
	*p = 12;
	printf("%d\n", *p);

	free(p);	// All done with that manually allocated memory.

	// This is a way that we commonly use to do Error-Handling while allocating memory.
	
	c = malloc(sizeof(char) * 10);
	if (c == NULL) {
		printf("Error allocating 10 chars\n");
		return -1;
	}
	
	temp = c;
	for (int i = 0; i < (sizeof(char)*10); i++) {
		*temp = 'x';
		temp++;
	}


	temp--;
	for (; temp >= c; temp--) 
		printf("[%c] at [%p]\n", *temp, temp);
	

	printf("base pointer address -> [%p] - [%p]\n", c, temp);

	allocate_for_array();
	free(c);


}

