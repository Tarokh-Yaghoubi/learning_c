
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
	Examples of Standard Pragma:
	#pragma STDC FP_CONTRACT OFF
	#pragma STDC CX_LIMITED_RANGE ON
*/



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

