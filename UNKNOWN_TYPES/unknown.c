
// :)

// UNKNOWN TYPES


#include "../requirements.h"

extern int a[];

// an struct is already and incomplete type until the closing brace is reached.
struct antelope {
	int leg_count;	// incomplete
	float stomach;	// incomplete
	float top_speed; // incomplete
	char* nickname;	// incomplete
};	// now its complete.

// what if we have a linked-list ?
struct node {
	int data;
	struct node* next;	// struct node is incomplete... but its ok!
};

// C's allowance for incomplete types makes it possible. we cannot declare a node,
// but we can declare a pointer to one, even if it is incomplete.
// NOTE: this is the same thing when two structures refer to eachother.

// NOTE:
/*
 * 	THIS WORKS BECAUSE IN C, POINTERS ARE THE SAME SIZE REGARDLESS
 *	ON WHAT THEY ARE POINTING TO. SO THE COMPILER DOES NOT NEED TO
 *	KNOW THE SIZE OF THE STRUCT NODE AT THIS POINT, IT JUST NEEDS TO
 *	KNOW THE SIZE OF A POINTER.
 * */

int main() {

	// This Compiles without an error...

	struct foo *x;
	union bar *y;
	enum baz *z;
	
	// these are examples of incomplete types.
	// an incomplete type is a type that its size is unknown
	// you can have a pointer to an incomplete type, but you cannot dereference 
	// it, you cannot get its size, or use pointer arithmetic on it.
	// and you cannot sizeof it.
}

