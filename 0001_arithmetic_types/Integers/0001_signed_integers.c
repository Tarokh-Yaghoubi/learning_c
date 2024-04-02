/**
*
*   Author: Tarokh Yaghoubi
*   Description:
*       - SIGNED Integer Types and Integer Constants in the C programming language
*       - Signed Integers - Integer Constants - How to define and use them in C
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>


// Each unsigned integer type (except _Bool) has a corresponding signed integer type that occupies the same amount of storage.
// We use sign integers to represent negative, zero and positive values, the range of which depends on the number bits
// allocated to the type and the representation.

// REPRESENTING
// representing signed integer types is more complicated than representing unsigned integer types.
// Historically, the C language has supported three signed integer representation schemes:

// 1 - Sign and Magnitute: The high-order indicates the sign, and the remaining bits represent the magnitute of the value in pure binary notation.
// 2 - One's complement: The sign bit is given the weight ((2 ^ (N - 1)) - 1), and the other value bits have the same weights as for unsigned.
// 3 - Two's complement: The sign bit is given the weight (2 ^ (N - 1)), and the other value bits have the same weights as for unsigned.

// You cannot choose which representation to use; that is determined by the implementers of C for the various systems.
// Through all three are still in use, Two's Complement is by far is the most popular representation.
// In Two's Complement, the MSB (Most Significant Bit) or the leftmost bit, represents the sign of the number.
// for example for the number 18, the binary representation is : 00010010, which the MSB shows the sign (which is now a zero so the number is positive)
// But what about the negative number ? How is it's representation in Two's Complement ? Here it is :

// 1 - You must find the binary representation of the number, which is : 00010010.
// 2 - You must invert all the bits: 11101101.
// 3 - Then, you need to add 1 to the result, like this:
/*

       +---+---+---+---+---+---+---+---+
       | 0 | 0 | 0 | 0 | 0 | 0 | 0 | 1 |  (00000001)
    +  | 1 | 1 | 1 | 0 | 1 | 1 | 0 | 1 |  (11101101)
       +---+---+---+---+---+---+---+---+
       | 1 | 1 | 1 | 0 | 1 | 1 | 1 | 0 |  (11101110)
       +---+---+---+---+---+---+---+---+

*/

// Then, 11101110 is representing the decimal -18 (assuming an 8 bit signed integer representation)


// OVERFLOW
// overflow occurs when a signed integer operation results in a value that can not be represented in the resulting type.
// For example, the following implementation of a function-like macro that returns the absolue value of an integer can
// overflow:

#define Abs(i) ((i) < 0 ? (-i) : (i))

// This macro will perfectly work fine on most of the numbers, except the most negative value of a signed type.
// because when we try to negate, for example -128, the result cannot be represented within this range.
// when we do the Two's complement process on the most negative value, The result is indeed "10000000", which represents -128 again.
// In the context of an 8-bit signed integer type, there's no way to represent the positive value corresponding to "10000000".
// This situation results in overflow because the positive result exceeds the maximum representable value for the data type, 
// which leads to undefined behavior.

void test_abs_ok(void) {
    signed int si = -25;
    signed int abs_si = Abs(si);
    printf("absolue value of si is -> [%d]\n", abs_si);
}

void test_abs_overflow(void) {
    signed int si = INT_MIN;
    signed int si_abs = Abs(si);    // undefined behavior
    printf("(OVERFLOW) is -> [%d]\n", si_abs);
}

int main() {
    test_abs_ok();
    test_abs_overflow();
    return EXIT_SUCCESS;
}


// Signed Integer Overflow is undefined behavior in C, allowing implementations to silently wrap (the most common behavior), Trap, or both.
// "Traps" interrupt execution of the program so that no further operations are performed.
// Common architectures like x86 do a combination of both. Because the behavior is undefined, no universally correct solution to this problem exists.

int abs(int i) {

    return (i >= 0) ? i : -(unsigned)i; // this avoids overflow, because we are casting it to unsigned

}

// INTEGER CONSTANTS

// Integer Constants or Integer Literals, are constants we use to introduce particular integer values into a program.
// For example, you might use them in a declaration or assignment to initialize a counter to 0.
// C has three kind of integer constants that use different number systems, decimal, octal and hexadecimal constants.

void different_constants(void) {
    unsigned int ui = 71;
    int si;
    si = -13;

    // if a constant starts with a 0, optionally followed by digits 0 through 7, it is an "octal constant"
    int agent = 007;
    int permissions = 0777;
    // octal constants are convenient when dealing with 3-bit fields.

    // HexaDecimal constant:

    int burger = 0xDEADBEEF;    // hexadecimals are 0 through 9, A through F, prefexing with 0x or 0X


}

// you can append a suffix to your constant to specify its type. Without a suffix, a decimal constant is given the int type if it can be represented
// as a value in that type. If it cannot be represented as an int, it will be represented as a long int or long long int.
// The suffixes are U for unsigned, L for signed long, and LL for long long. These can be combined.
// For example ULL means unsigned long long. Here are some examples:

void constant_suffixes(void) {
    unsigned int ui = 71U;
    signed long int li = 34544336657866L;
    unsigned long long ull = 77877675988232323ULL;

    printf("%d\t%ld\t%llu\n", ui, li, ull);
}

// NOTE: If we do not use a suffix, and the integer constant is not of the required type, it will be implicitly converted.


int main(void) {
    different_constants();
    constant_suffixes();

    return EXIT_SUCCESS;
}

