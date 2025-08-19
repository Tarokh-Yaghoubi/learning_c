
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// C provides a way for you to declare an array whose size is determined at runtime.
// This gives you the benefits of dynamic runtime sizing like you get with malloc(),
// but without needing to worry about free()ing the memory after.

// A lot of people do not like VLAs, it is banned from the Linux Kernel, for example.

// This is an optional feature of the language. The macro __STDC_NO_VLA__ is set to 1 if the VLAs are not present.
// The were mandatory in C99, and then became optional in C11.

#if __STDC_NO_VLA__ == 1
#error VLA_UNAVAILABLE
#endif

int main() {

	int n;
	char buf[32];

	printf("Enter a number: ");
	fflush(stdout);

	fgets(buf, sizeof(buf), stdin);
	n = strtoul(buf, NULL, 10);

	int v[n];

	for (int i = 0; i < n; i++)
		v[i] = i * 10;

	for (int i = 0; i < n; i++)
		printf("v[%d] = %d\n", i, v[i]);

	return 0;
}

// Some restrictions:
// 1- You cannot declare a VLA at file scope, and you cannot make a static one in the block scope.*
// 2- You cannot use an initializer list to initialize the array.
// 3- Also entering a negative value for the size of the array invokes undefined behaviour.
// * - This is due to how VLAs are typically allocated on the stack, whereas static variables are on the heap. 
// and the whole idea with VLAs is the will be automatically deallocated when the stack frame is popped at the end of the function.

// sizeof and VLAs.

void sizeof_and_vlas() {
	
	int n;
	char buf[32];

	printf("Enter a number: \n");
	fflush(stdout);

	fgets(buf, sizeof(buf), stdin);
	n = strtoul(buf, NULL, 10);

	int arr[n];

	for (int i = 0; i < n; i++)
		arr[i] = i * n;

	size_t size = sizeof(arr) / sizeof(arr[0]);

	printf("SIZE -> %zu\n", size);
}

// you must watchout when using goto near VLAs because a lot of things are not legal.
// also when you are using longjmp() there is a case that you could leak memory with VLAs.

/*

GENERAL ISSUES:

VLAs have been banned from the Linux kernel for a few reasons:

	• Lots of places they were used should have just been fixed-size.
	• The code behind VLAs is slower (to a degree that most people wouldn’t notice, but makes a difference
	in an operating system).
	• VLAs are not supported to the same degree by all C compilers.
	• Stack size is limited, and VLAs go on the stack. If some code accidentally (or maliciously) passes a

large value into a kernel function that allocates a VLA, Bad Things™ could happen.
Other folks online point out that there’s no way to detect a VLA’s failure to allocate, and programs that
suffered such problems would likely just crash. While fixed-size arrays also have the same issue, it’s far
more likely that someone accidentally make a VLA Of Unusual Size than somehow accidentally declare a
fixed-size, say, 30 megabyte array.

*/

