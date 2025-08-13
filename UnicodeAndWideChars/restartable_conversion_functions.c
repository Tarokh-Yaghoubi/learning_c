
/*

NOTE: A list of restartable functions, to pass in your own mbstate_t:

   • mbrtowc()—multibyte to wide character
   • wcrtomb()—wide character to multibyte
   • mbsrtowcs()—multibyte string to wide character string
   • wcsrtombs()—wide character string to multibyte string
*/

// These functions are completely like the non-restartable ones. except you have to pass your own mbstate_t var
// to avoid race.

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <wchar.h>
#include <locale.h>

int main(void) 
{

	setlocale(LC_ALL, "");

	char* mb_string = "The cost is \u20AC1.23";
	size_t mb_len = strlen(mb_string);


	wchar_t wc_string[128];

	mbstate_t mbs;
	memset(&mbs, 0, sizeof(mbs));

	const char* invalid  = mb_string;

	size_t wc_len = mbsrtowcs(wc_string, &invalid, 128, &mbs);

	if (invalid == NULL) {
		printf("no invalid characters found\n");
		printf("multibyte: \"%s\" (%zu bytes)\n", mb_string, mb_len);
		printf("wide char: \"%ls\" (%zu characters)\n", wc_string, wc_len);
	} else {
	
		ptrdiff_t offset = invalid - mb_string;
		printf("Invalid character at offset %td\n", offset);
		
	}

	return EXIT_SUCCESS;
}
