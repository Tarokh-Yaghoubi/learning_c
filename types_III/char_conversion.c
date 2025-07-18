

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char five = '5';	// is this the same with 5, no
	int y = five - '0';

	printf("%d %d \n", 5, y);

	// also we can convert the other way, like integer to character (numbers) like this
	
	int number = 5;
	char num = number + '0';	// this gives us 53 in the ascii table
	printf("%c\n", num);	// so here i have 5 with %c
	return EXIT_SUCCESS;


}
