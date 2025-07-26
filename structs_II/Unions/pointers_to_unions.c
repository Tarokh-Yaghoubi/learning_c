


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// If you have a pointer to a union, you can cast that to any of the types
// of the fields in that union and get the values  out that way.
// here the union has ints, floats and chars in it. And we get pointers to 
// the union but we cast them to int* and float* types. (the cast silences
// compiler warnings.), and then we will dereference them.



union foo {
	int a, b, c, d, e, f;
	float g, h;
	char i, j, k, l;
};

int main(void) {

	union foo x;

	int *foo_int_ptr = (int *)&x;
	float *foo_float_ptr = (float *)&x;

	x.a = 12;
	printf("%d %d \n", x.a, *foo_int_ptr);

	x.g = 12.43;
	printf("%f %f \n", x.g, *foo_float_ptr);


	// If we case foo_int_ptr back to union foo *ptr, we can find access to 
	// the members of the union.

	// Here we cannot see the integers anymore cause they're overwritten
	// using the float number.


	// Here I'll get the integer representation of the float number. 
	printf("FOO INT PTR IS -> %d\n", *foo_int_ptr);

	union foo *union_int_ptr = (union foo *)foo_int_ptr;
	printf("%d %d %f\n", union_int_ptr->a, x.a, union_int_ptr->g);

	return EXIT_SUCCESS;

}

// NOTE:
// Only one memory location is allocated for the whole Union.
// The size of the UNION is equal to the size of the largest member.
// All members share the same memory - so setting one member overwrites the data
// of others.

