
// Before your program gets compiled, it first runs through a phase called 
// preprocessing. It's almost like there is a language on top of the C programming
// language that runs first. And it outputs the C code, which then gets compiled.


// The angle brackets tell C that "don't look in the current directory for the header files,
// check the whole system".


// for including local files you can check double quotes " ". #include "something"

#include <stdio.h>
// #include <tlist.h> typeof lives here
#include <stdlib.h>

#define SQR(x) (x) * (x)

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
	printf("FILENAME: %s, LINE: %d, FUNC: %s\n", __FILE__, __LINE__, __func__);
	printf("DATE and TIME: %s %s\n", __DATE__, __TIME__);
	printf("%s %f\n", HELLO, PI);
	// printf("%s %f\n", hELLO wORLD, 3.14159);
	
	int sqr_4 = SQR(12);
	printf("SQR -> %ld\n", sqr_4);
	
	return EXIT_SUCCESS;
}


// Conditional Compilation

// It is possible to get the preprocessor to decide whether or not to present certain blocks 
// of code to the compiler, or just remove them entirely before compilation.
// We do that by wrapping up the code in conditional blocks.

void
conditionalPreprocessor(void) {

#ifdef NOTHING
	printf("NOTHING IS DEFINED\n");
#endif
	printf("OK\n");

// elifndef and elifdef - New features in C23.

#ifdef MOD1
	printf("MOD1\n");
#elifndef MOD1
	printf("not MOD1\n");
#endif
// This can be replaced with:

#if !defined MOD2
	printf("MOD2 is undefined \n");
#endif
}

void 
undefineAMacro(void) {
	#undef NOTHING
#ifdef NOTHING
	printf("NOTHING IS NOT UNDEFINED\n");

#endif

}

