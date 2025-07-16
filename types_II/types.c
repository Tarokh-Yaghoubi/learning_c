

#include <stdio.h>
#include <limits.h>	// MACROS for LIMITATIONS.

#include <float.h>	// to figure out how much precision we can have in a float.

int main() {
	int a = 100;
	
	printf("%c\n", a);
	printf("CHAR MIN/MAX -> %d %d\n", CHAR_MIN, CHAR_MAX);
	printf("SHRT CHAR MIN/MAX -> %d %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("SHRT MIN/MAX -> %d %d\n", SHRT_MIN, SHRT_MAX);
	printf("INT MIN/MAX -> %d %d\n", INT_MIN, INT_MAX);
	printf("LONG MIN/MAX -> %ld %ld\n", LONG_MIN, LONG_MAX);
	printf("LONG LONG MIN/MAX -> %lld %lld\n", LLONG_MIN, LLONG_MAX);
	printf("UNSIGNED CHAR -> %c\n", UCHAR_MAX);
	printf("UNSIGNED SHORT -> %d\n", USHRT_MAX);
	printf("UNSIGNED INT -> %d\n", UINT_MAX);

	printf("---------------------\n");

	printf("FLT_DIG  -> %d\n", FLT_DIG);
	printf("DBL_DIG  -> %d\n", DBL_DIG);
	printf("LDBL_DIG -> %d\n", LDBL_DIG);

	return 0;
}


