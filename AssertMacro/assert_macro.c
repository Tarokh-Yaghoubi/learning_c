
#include <stdio.h>
#include <string.h>
#include <stdlib.h>



// How to define the ASSERT MACRO, and how to set a condition for that.

#define ASSERT_ENABLED 1

#if ASSERT_ENABLED
#define ASSERT(c, m) \
do { \
    if (!(c)) { \
        fprintf(stderr, __FILE__ ":%d: assertion %s failed: %s\n", \
                __LINE__, #c, m); \
        exit(1); \
    } \
} while(0)
#else
#define ASSERT(c, m) fprintf(stdout, "%s: MACRO NOT ENABLED", __FILE__);
#endif


int
main(void) {

	int x = 10;
	ASSERT(x <= 10, "X must be under or equal to 10");
	return EXIT_SUCCESS;
}
