#include <stdio.h>

int my_strlen(char* s) {
	char* p = s;

	while (*p != '\0')
		p++;
	
	printf("%p\t%p\n", p, s);

	// Remember that you can only use pointer subtraction between pointers that point to the same array.
	return p - s;
}

int main() {

	int arr[] = {1, 2, 3, 4, 5};
	int* p = &arr[0]; 	// or int* p = arr; works fine as well
//	printf("%d\n", *p);
//	printf("%d\n", *(p + 0));	// this will act the same as the one above.
//	printf("%d\n", *(p + 1));	// this will print 2
	
	// When we increment a pointer, we simply tell C to skip n'Bytes in memory (here its int so it will be 4 bytes)
	// and jump to the next int value in memory.

	// This is what we mean when we say Arrays and Pointers are Equivalent.
	if (arr[2] == (*((p) + (2))))
		printf("These are the same\n");

	for (int i = 0; i < sizeof(arr)/sizeof(int); ++i) 
		printf("%d\n", *(p + i));

	
	printf("------------------------\n");

	// Another example that proofs Array-Pointer equivalency
	for (int i = 0; i < 5; ++i)
		printf("%d\n", *(arr + i));

	int len = my_strlen("tarokh");
	printf("len is -> %d\n", len);
	return 0;
}

// ARRAY-POINTER EQUIVALENCE:
// a[b] == *(a + b)
// a[2] == *(a + 2)
// a = {0, 1, 2, 3, 4, 5};
// a + 2 => 0 + 2 == a[2];
//  :)


