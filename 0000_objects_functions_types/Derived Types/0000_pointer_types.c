/**
*
*   Author: Tarokh-Yaghoubi
*   Description:
*       - Derived Types in the C programming language
*       - Pointer Types | How to define them, and use them 
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Pointer Type: A pointer type is derived from the function or object type that it points to, called the referenced type. A pointer provides a reference to an entity of the referenced type.
// The following three declarations declare a pointer to int, a pointer to character and a pointer to void.

// This (&) is the address-of operator
// This (*) is the indirection operator
// We use (&) to take the address of an object or function

int
main(void) {

    int *iptr;
    int *iptr2;
    char *cptr;
    void *vptr;

    int i = 45;
    iptr = &i;  // we are assigning the address of "i" to "iptr", because "iptr" is a pointer to an integer, and "i" is an integer itself.
    
    printf("%s [%p]\n", "This is the address of variable (i)", (int*)&i);
    printf("%s [%p]\n", "This is the address that variable (iptr) is holding", iptr); 
    printf("%s [%p]\n", "This is the address of iptr itself", (int*)&iptr);
  
   
    // here we can always check and see that "iptr" is holding the address of "i"

    if (iptr == &i)
        printf("%s\n", "iptr is holding the address of i");
    else
        printf("%s\n", "iptr is NOT holding the address of i");


    // we can also use the '&' operator on the result of the '*' operator:
    iptr2 = &*iptr;
    // This line of code takes the pointer 'iptr', dereferences it using the '*' operator, and then takes the address of the result using the '&' operator, assiging the final address to "iptr2".
    // now iptr2 is pointing to the address where the value pointed to by iptr is stored

    if (iptr2 == iptr && iptr2 == &i && iptr == &i) {
    
        printf("%s [address iptr2 is holding ->  %p] [address iptr is holding %p]\n", "iptr2 and iptr are the same thing", (int*)iptr2, (int*)iptr);
        printf("%s [(address of i) -> (%p)]\n", "The address of 'i' is equivalent to the addresses that iptr and iptr2 are holding", (int*)&i);
    }
   
    return EXIT_SUCCESS;
    
}


// NOTE : If a pointer is not pointing to a valid function or object, bad things may happen.


