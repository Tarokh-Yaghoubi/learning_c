

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	// Type Qualifiers and Storage-Class specifiers
	
	// const: the most common type qualifier, for defining a constant variable,
	// so it is read-only.
	
	const int x = 32;
	// x = 23; 	// this is wrong.
	
	// CONST AND POINTERS
	// NOTE: there are two different meanings when it comes to constants and pointers.
	// first one is that you can make it so you cannot change the thing the pointer points
	// to, like this:
	
	const int* p = &x;
	p++;	// this is completely valid
	// *p = 23;	// this is a bug
	
	// Somewhat confusingly these two things are equivalent:
	const int* s;	// cannot modify what s points to
	int const *j;	// cannot modify what j points to

	// NOTE: So here we cannot change what the pointer points to, but we can change the
	// pointer itself, what if we want the other way ?
	
	// this is fine but here x is const, so you'll see a warning 
	int* const otherway = &x; // this way we can change what the pointer points to,
				// but we cannot change the pointer itself.
	// otherway++;	// Compiler error.
	*otherway = 56;	// this is completely fine.

	const int* const ptr;	// this way: you cannot change the pointer,
				// and also you cannot change what the pointer points to.
	// It is kinda read-only.
	
	const char*** characterss; // a char pointer that points to another pointer that 
				   // points to a pointer-to-character
	

	char** const p;	// p++ is wrong cause p is constant, but it is fine to change the val
	char* const* o;	// p++ is ok, but you cannot change the value 
	char* const *const i;	// you cannot change the address or the value it is pointing
				// at.
	

	return EXIT_SUCCESS;
}

