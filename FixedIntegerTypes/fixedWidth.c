


#include "../requirements.h"

int main() {

	// The bit-sized types
	
	// for both signed and unsigned integers, we can specify a type that is a certain 
	// number of bits, with some caveats.

	printf("%ld\n", INT_MAX);

	// Integers of exactly a ceratin size -> intN_t
	// Integers that are at least a certain size (int_leastN_t)
	// Integers that are at least a certain size and are as fast as possible (int_fastN_t)
	int32_t w;	// w is exactly 32 bits, signed 
	uint16_t x;	// x is exactly 16 bits, unsigned
	int_least8_t y;	// y is at least 8 bits, signed 

	uint_fast64_t z; // z is the fastest representation at least 64 bits, unsigned.

	// There's a type you can use that holds the largest representable integers available 
	// on the system, both signed and unsigned :
	// intmax_t and uintmax_t
	intmax_t maxInt;
	uintmax_t maxUint;
	int first = 34;
	int second = 34;
	printf("%d\t%d\n", ~first, second);
	// If you have a constant that you want to have fit in a certain number of bits,
	// you cna use these macros to automatically append the proper suffix onto the number
	// like INT8_C(x), UINT16_C(x), INTMAX_C(x);
	
	maxInt = INTMAX_C(first);
	uint16_t ff = UINT16_C(2342);

	return EXIT_SUCCESS;

}

