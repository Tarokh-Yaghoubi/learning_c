
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// that NULL, as the second param of the strtoXYZ family, what is that ? 
// That helps us figure out if an error occured in the processing of a string.
// It's a pointer, to a pointer-to-character.

void badchar_nulTerminator(void);

int
main(int argc, char **argv)
{
	char* s = "35x45"; // x is not a valid digit in base 10;
	char* badchar;

	unsigned long int x = strtoul(s, &badchar, 10);
	printf("%lu\n", x);	// 35
	
	printf("Invalid Character -> %c\n", *badchar);	// x is invalid.

	badchar_nulTerminator();

	return EXIT_SUCCESS;

}

// if nothing goes wrong, badchar will just point to the nul-terminator at the end of the string.

void 
badchar_nulTerminator(void) 
{
	char* s = "3456";
	char* badchar;

	unsigned long x = strtoul(s, &badchar, 10);



	if (*badchar == '\0') {
		printf("%lu\n", x);
	} else {
		printf("Partial Conversion -> %lu\n", x);
		printf("BAD CHAR -> %c\n", *badchar);

	}

}

