
#define REG_ADDRESS 0x4000000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main() {

	// these are different ways to define or detect NULL pointers in C
	void* ptr = (void *)0;
	ptr = 0;
	ptr = '\0';
	ptr = NULL;

	if (ptr == NULL) {
		printf("ptr is null here\n");
	}

	volatile uint32_t *reg = (uint32_t *)(uintptr_t)REG_ADDRESS;
	printf("REG VAL in mem : ld\n", *reg);
	*reg = 0xDEADBEEF;	// One way to use pointer casting to uintptr_t

	printf("IF THE SEGMENTATION FAULT PASSES -> ");
	int first = 3;
	int* pptr = &first;
	float* fpptr = (float *)&first;

	return 0;

}
