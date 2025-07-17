


// we are  going to talk about converting one type to another.
// C does not do String to Numbers
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void stringToNumeric(void) {
	// There are a couple of functions to do this:
	// atoi -> ASCII to int.
	// atof -> ASCII to float.
	// atol -> ASCII to long int.
	// atoll -> ASCII to long long int.
	// strtol -> String (ascii) to long.
	// These functions live in stdlib.h , and they  have a bad error handling, 
	// for example: undefined behavior while passing a bad string, so be careful...
	
	char* binary = "101010";
	char* s = "3490";
	char* pi = "3.14159";
	float f;

	f = atof(pi);
	printf("%.5f\n", f);

	// f = atof("FOO");	-> This is dangerous
	
	// Convert string s, a number in base 10, to an unsigned long int.
	// NULL means we do not care about any ERROR information.
	unsigned long int x = strtoul(s, NULL, 10); 
	printf("%lu\n", x);

	unsigned long int y = strtoul(binary, NULL, 2);	// we are going base-2 binary.
	printf("%lu\n", y);	// 42


}

int main() {

	char s[10];
	float f = 3.14159;

	// when we want to convert a number to a String, we use sprintf(), or snprintf()
	
	// convert f to string and copy it into s, and write at most 10 characters including the NUL terminator \0
	snprintf(s, 10, "%f", f);

	printf("String value: %s\n", s);

	stringToNumeric();

	return 0;
}

