

#include <stido.h>
#include <string.h>
#include <stdlib.h>

int main() {


	int a = 0x1A2B;
	int b = 0x1a2b; // case does not matter for hex digits
	
	printf("%x", a);	// %x for printing a hex number
	
	// if you lead a number with 0 it is read as an octal number
	
	int c = 012;
	printf("%o\n", c);
	
	int x = 111111;
	int y = 00111;	// Decimal 73 
	int z = 01111; 	// Decimal 585


	int bin = 0b101010;	// 42 decimal - 101010 binary
	printf("%d\n", bin);

	return EXIT_SUCCESS;

}
