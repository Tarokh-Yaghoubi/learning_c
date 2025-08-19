


#include <stdio.h>

int sum(int arr[], int size) {
	int total = 0;

	for (int i = 0; i < size; i++)
		total += arr[i];

	return total;

}

int main() {

	// compound literals
	// the syntax for creating unnamed literals :
	(int []){1, 2, 3, 4};	// the type is an array of ints, the value is 1,2,3,4
	
	// this line of code doesn't do anything on its own. it is just on the air so we can have
	// a pointer to it so we can use its value
	
	int* ptr = (int []){1, 2, 3, 4, 5, 6};
	printf("%d\n", *(++ptr));	// 2

	int s = sum((int []){1, 2, 3, 4}, 4); // this is where it comes handy.
	printf("SUM is -> %d\n", s);

	return 0;
}
