
// Before your program gets compiled, it first runs through a phase called 
// preprocessing. It's almost like there is a language on top of the C programming
// language that runs first. And it outputs the C code, which then gets compiled.


// The angle brackets tell C that "don't look in the current directory for the header files,
// check the whole system".


// for including local files you can check double quotes " ". #include "something"

#include <stdio.h>
#include <tlist.h>
#include <stdlib.h>
/*
 *	stdio.h
 *	
 * */
// A MACRO is an identifier that gets expanded to another piece of code before the compiler
// even sees it. Think of it like a placeholder. when the preprocessor sees one of those 
// identifiers, it replaces it with another value that you've defined.

// we do this with #define (often read "pound define")

#define HELLO "hELLO World!"	// constant 

#define PI 3.14159

#define NOTHING


int main() {
	printf("%s %f\n", HELLO, PI);
	printf("%s %f\n", hELLO wORLD, 3.14159);
	return EXIT_SUCCESS;
}


// Conditional Compilation

// It is possible toe get the preprocessor to decide whether or not to present certain blocks 
// of code to the compiler, or just remove them entirely before compilation.
// We do that by wrapping up the code in conditional blocks.

void
conditionalPreprocessor(void) {

#ifdef NOTHING
	printf("NOTHING IS DEFINED\n");
#endif
	printf("OK\n");
}

