

#include "../requirements.h"


int func(int *const volatile p);
int func2(int p[const volatile]);	// this way is also possible
int func3(int p[const volatile 10]);	// this way is possible as well.

void limited_func(char arr[static 4]);	// this means the array you pass to the func must have at least four elements.

int main() {

	char arr[4] = {'a', 'b', 'c', 'd', '\0'};
	limited_func(arr);	// this is ok
	fflush(stdout);
	limited_func((char []){'a', 'b', 'c', 'd', 'f', '\0'});	// this is not ok
	return EXIT_SUCCESS;
}

void limited_func(char arr[static 4]) {
	
	for(int i = 0; i < strlen(arr); ++i)
		printf("%c ", arr[i]);

	printf("\n");
}
