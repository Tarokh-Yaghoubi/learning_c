
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <wchar.h>
#include <locale.h>

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

	// For Bigger unicodes ( bigger than 16 bits ), we use capital u, \U
	char* str2 = "\U0001D4D1"; // mathematical B -> 𝓑

	printf("%s\n", str2);
	
	// These two are the same \u03C0 == \U000003C0
	
	const char* utf8_japanese = "\U00003041\U00003052\U00003073\U00003064\U00003081";
	
	// This is supposed to be 5 but it is 15, cause strlen is counting the bytes and it will mislead you
	// with other character sets, such as Japanese or chinese

	printf("uf8_japanese => [%zu]\n", strlen(utf8_japanese));

	// mbstowcs() => Converts a multibyte string (char*). into a wide-char string wchar_t* and returns the number of wide chars 
	// stored - excluding the null terminator.
	
	// size_t mbstowcs(wchar_t *dest, const char* src, size_t n);
	
	setlocale(LC_ALL, ""); // enable UTF8 Handling
	
	wchar_t wbuf[20];

	size_t len = mbstowcs(wbuf, utf8_japanese, 20);	// wbuf now contains the converted string
	
	size_t len2 = mbstowcs(NULL, utf8_japanese, 20); // it does not copy anything, it will just return the len

	printf("mbstowcs len => [%zu][%zu]\n", len, len2);

	printf("\u0024\n");

	// printf() variants allow for a way to only print some specific bytes of a string. like %.12s as an example

	// Strings: are multibyte strings made up of multibyte characters.
	// C string -> C Multibyte String
	// Even if the data in a String are single byte, and it's made up of single-byte characters, it is still called multi-byte
	
	char c[128] = "Hello, Jacob is here";	// Multibyte String
	char* s = "\u20AC1.23";
	printf("%zu\n", strlen(s)); // this is 7 on my system, remember that strlen returns the number of bytes in a string, 
				    // not the number of characters
	size_t len3 = mbstowcs(NULL, s, 10);
	printf("LEN3 IS -> %d\n", len3);	// now here len is 5

	wchar_t wch[10];	// if your system is using UTF-32, each element is a fixed 4-byte, so one array element == one Unicode Character
	// A wide character is a single value that can uniquely represent any character in the current locale.
	
	// wchar_t is like char, but it is wide 

	return 0;
}

