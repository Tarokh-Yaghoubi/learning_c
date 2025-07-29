

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	int a = 23;
	int* ptr = &a;
	printf("A=%d, *ptr=%p, ptr=%p, &A=%p\n", a, *ptr, ptr, a);

	int *pptr = ptr;
	printf("pptr=%p, *pptr=%p, &ptr=%p\n", pptr, *pptr, ptr);
	*pptr++;

	printf("%d\n", *pptr);
	

	int first = 34;
	int *fPtr = &first;
	int **Fpptr = &fPtr;
	printf("%p %p\n", Fpptr, &fPtr);


	return 0;

}
