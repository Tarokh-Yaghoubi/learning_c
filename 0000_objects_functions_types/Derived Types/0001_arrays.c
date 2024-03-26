/**
*
*   Author: Tarokh-Yaghoubi
*   Description:
*       - Derived Types in the C programming language 
*       - Arrays in C | What are Arrays and how should we use them in C
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int create_char_arr(void);

// An array is a contiguously allocated sequence of objects that all have the same element type.
// Array types are characterized by their element types and the number of elements in the array.

// array declaration is like -> DATA_TYPE ARRAY_NAME[ARRAY_SIZE];

// we use square barackets to identify an element of an array.
// for example, the following code creates the string "0123456789" to demonstrate how to assign values to the elements of an array:


int
main(void) {
    create_char_arr();
}


// The first line declares an array of char with a bound of 11.
// This allocates sufficient storage to create a string with 10 characters plus a null character '\0'
// The for loop iterates 10 times, with the values of 'i' ranging from 0 to 9. Each iteration assigns the result
// of the expression '0' + i to str[i]. Following the end of the loop, the null character is copied to the final element of the array str[10].

// NOTE: In the expression [ str[i] = '0' + i; ], str is automatically converted to a pointer to the first member of the array (an object of type char), and 'i' has an unsigned integer type.
// NOTE: str[i] == *(str + i) Because : C arrays are essentially pointers to the first element of the array, when you use the subscript operator on an array,
// It is equivalent to adding the index to the base address of the array and then dereferencing that resulting pointer.


// NOTE: ARRAYS are indexed starting at 0. so the array char arr[11], is indexed from 0 to 10, with 10 being the last element, which would be '\0' in our example.

// NOTE: taking the address of the i'th element of the array using the unary '&' is equivalent to adding the intended index of the array using + to the base address of the array, which means:
// &arr[10] == (arr + 10) because, &arr[0] is equivalent to arr itself, because an array is a pointer to the first index of itself. so when we add 10 to the base, it will give us the address of
// the tenth index of the array.

int
create_char_arr(void) {
    char str[11];
    for (unsigned int i = 0; i < 10; ++i) {
        str[i] = '0' + i;
    }
    str[10] = '\0';

    printf("%s [%s]\n", "The str array value is -> ", str);

    return EXIT_SUCCESS;

}

