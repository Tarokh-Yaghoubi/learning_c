
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Examples of Standard Pragma:
	#pragma STDC FP_CONTRACT OFF
	#pragma STDC CX_LIMITED_RANGE ON
*/

// we can also use #line so the __LINE__ can keep counting from the new line that you have determined.

#line 10 "carrot.jacob"	// here we say: start from line 10 and set the filename to carrot.jacob

#define ASSERT_FEATURE 1

int
main(void) {

#ifndef ASSERT_FEATURE
#error ("%s ASSERT FEATURE MUST BE ENABLED", __FILE__)
#endif

// OR AS A REAL-WORLD example:

#if !defined(_WIN32) && !defined(__linux__)
#error "This code only runs on one of the platforms"
#endif

	return EXIT_SUCCESS;

}

/*

"In the same way we have formal rules to handle complex numbers 
(so we know we're doing safe and consistent math), compilers have rules, 
like #pragma, where the programmer and the compiler can agree on behavior 
that is not normally covered by standard rules."

*/
