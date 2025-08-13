	// mbtowc => multibyte character to wide character
	// wctomb => wide character to multi byte
	// mbstowcs => multibyte string to wide character string
	// wcstombs => wide character string to multibyte string
	

#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>
#include <locale.h>
#include <wchar.h>

int main(void) {

	setlocale(LC_ALL, "");

	char* mb_string = "The cost is \u20AC1.23";
	size_t mb_len = strlen(mb_string);
	printf("%d\n", mb_len);

	wchar_t wc_string[128];	// Holds up to 128 wide characters

	size_t wc_len = mbstowcs(wc_string, mb_string, 128);
	printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
	printf("wide char: \"%ls\" (%zu characters)\n", wc_string, wc_len);

	size_t wc_len_only = mbstowcs(NULL, mb_string, 0);	// This is how we can do it on POSIX-compliant 
	// This is not portable btw, careful ...
	printf("Here we only got the len -> [%zu]\n", wc_len_only);

	size_t len = wcslen(wc_string);
	printf("wclen of wc_string is -> [%ld]\n", (long)len);

	return EXIT_SUCCESS;
}
