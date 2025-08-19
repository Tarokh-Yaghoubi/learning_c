
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

