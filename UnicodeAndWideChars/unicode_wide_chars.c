
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *	It's about two things:
 *		First we have the code point which tells us effectively the serial number of
 *		a particular character.
 *
 * 		Second, we have the encoding which tells us how we are going to represent that number in memory.
 *	
 *		With UTF-16 and UTF-32 byte-order matters, so we see UTF_16BE for big-endian, and UTF-16LE
 *		technically if unspecified, you should assume big-endian. 
 *		Example: 
 *
 *		Char    Code Point   UTF-16BE   UTF32-BE   UTF16-LE    UTF-32LE    UTF-8
 *		π(PI)        3C0        03C0     000003C0     C003      C0030000    CF80
 * */

	// There is a way in C to specify unicode characters and these will get translated by the compiler to the execution
	// character set. 
	// Like the euro symbol [ 0x20AC ]

int main() {

	char* str = "\u20AC 1.23";
	printf("EU Price -> %s\n", str);

	return 0;
}
