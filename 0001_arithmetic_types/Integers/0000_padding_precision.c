/**
*
*   Author: Tarokh Yaghoubi
*   Description:
*       - Integer Types and Integer Constants in the C programming language
*       - Padding and Precision, unsigned, signed int, How to declare and use them, and so on
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <limit.h>

// Each Integer type represents a finite range of integers.

// signed integer, represents negative, zero and positive numbers.
// unsigned integer, represents only zero and positive numbers.
// the range that each type of integer can represent depends on your implementation.

// PADDING AND PRECISION

// All integer types except char, signed char and unsigned char may contain unused bits, called 'padding', that allow implementations to accomodate hardware quirks.
// The number of bits used to represent a value of a given type, excluding padding but including the sign, is called the 'width' and is often denoted by N.
// The 'precision' is the number of bits used to represent values, excluding sing and padding bits.

// THE <limit.h> HEADER FILE
// The <limit.h> header file provides the minimum and maximum representable values for the various integer types.
// A "representable value" is one that can be represented in the Number of bits available to an object of a particular type.
// NOTE: Values that cannot be represented will be diagnosed by the compiler or converted to a representable but different (incorrect) value.

// NOTE: Each integer type must support the minimum ranges, allowing you to depend on a portable range of values across any implementation.
// NOTE: Smaller types cannot be wider than larger types. So, for example, USHRT_MAX cannot be greater than UINT_MAX, but they can be the same width.


// DECLARING INTEGERS

void declare_integers(void) {
    unsigned int ui;    // unsigned is required
    unsigned u;         // int can be omitted
    unsigned long long ull; // int can be omitted
    unsigned char uc;       // unsigned is required

}

// When declaring signed integer types, you can omit the signed keyword.

// For example, instead of declaring a variable to be of type signed long long int, it is common practice to just declare it as long long.

void valid_signed_ints(void) {
    int i;  // signed can be omitted
    long long int sll;  // signed can be omitted
    long long sll2;     // signed and int can be omitted
    signed char sc;     // signed is REQUIRED here

}

// UNSIGNED INTEGERS

// Unsigned Integers have ranges that start at 0, and their upper bound is greater than that of the corresponding signed integer type.
// Unsigned Integers are frequently used for counting items that may have large, nonnegative quantities.

// Unsigned Integers do not require the sign to be represented and so generally provide 1 bit greater precision than the corresponding signed integer types.

// Unsigned Integer values range from 0 to a maximum value that depends on the width of the type.
// This maximum value is 2 ^ N where N is the width. For example; most x86 architectures use 32-bit integers with no padding bits, so an object of type unsigned int has a range 0 to 2 ^ 32 - 1
// which is (4,294,967,295). The CONSTANT expression UINT_MAX from <limits.h> specifies the implementation-defined upper range for this type.

// WRAP AROUND
// WRAPAROUND occurs when you perform arithmetic operations that result in values too small (less than 0) or too large (greater than 2 ^ N - 1) to be represented as a particular unsigned integer type.
// In this case, the value is reduced modulo the number that is one greater than the largest value that can be represented in the resulting type.
// wraparound is a well-defined behavior in C.

// NOTE: WHETHER IT IS A DEFECT IN YOUR CODE OR NOT, DEPENDS ON THE CONTEXT. IF YOU ARE COUNTING SOMETHING AND THE VALUE WRAPS, IT IS LIKELY TO BE AN ERROR
// HOWEVER, THE USE OF WRAPAROUND IN CERTAIN ENCRYPTION ALGORITHMS IS INTENTIONAL.

void wraparound_example(void) {
    unsigned int ui = UINT_MAX; // 4,294,967,295 in x86
    ui++;
    printf("%u\n", ui);     // ui is 0
    ui--;
    printf("%u\n", ui);     // ui is now one less than the max UINT_MAX
}

// because of wraparound, and unsigned int can never be less than 0. It is easy to lose track of this and implement comparisons that are always true or always false.
// for example, the 'i' in the following loop can never take on a negative value, so this loop will never terminate:

void infinit_loop(int n) {
    for (unsigned int i = n; i >= 0; --i) {
        printf("%s\n", "WELCOME TO INFINITY!");
    }
}


