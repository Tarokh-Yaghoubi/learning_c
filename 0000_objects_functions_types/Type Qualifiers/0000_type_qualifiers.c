/**
*
*   Author: Tarokh-Yaghoubi
*   Description:
*       - Type Qualifiers in C
*       - What are type qualifiers, Examples, const | volatile and so on.
*/

// All the types examined so far have been unqualified types. Types can be qualified by using one or more of the following
// const, volatile, and restrict. Each of these qualifiers changes behaviors when accessing objects of the qualified type.
// The qualified and unqualified versions of types can be used interchangeably as arguments to functions, return values from functions, and member of unions.

// NOTE: _Atomic type qualifier, available since C11, supports concurrent programs.


// CONST

// Objects declared with the const qualifier (const-qualified types) are not modifiable. In particular, they're not assignable but can have constant initializers.
// This means that objects with const-qualified types can have constant initializers. This means objects with const-qualified types can be placed in read-only memory
// by the compiler, and any attemp to write to them will result in a runtime error:

void const_qualifier_err(void) {
    const int i = 1;    // const-qualified int
    i = 32;             // error: i is const-qualified
}

// It is possible to accidently convince your compiler to change a const-qualified object for you.
// In the following example, we take the address of a const-qualified object 'i' and tell the compiler
// that this is actually a pointer to an 'int':

void change_const_qualified(void) {
    const int i = 1;
    int *ip = (int *)&i;        // casting 'i' to a 'pointer to int'
    *ip = 3;                    // undefined behavior

}

// C does not allow you to cast away the 'const' if the original was declared as a const-qualified object.
// This code might appear to work, but it is defective and may fail later.
// For Example, the compiler might place the const-qualified object in read-only memory, causing a memory-fault
// when trying to store a value in the object at runtime.

// C allows you to modify an object that is pointed to by a const-qualified pointer by casting the const away, provided that the original object was not declared const:

void const_qualified_ptr(void) {
    int i = 12;
    const int j = 12;
    const int *ptr = &i;
    const int *jptr = &j;
    *(int*)ptr = 23;        // ok
    *(int *)jptr = 43;      // undefined bahavior

}



