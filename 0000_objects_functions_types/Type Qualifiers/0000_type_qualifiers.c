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


// VOLATILE

// Objects of volatile-qualified types serve a special purpose. Static volatile-qualified objects are used to model memory-mapped input/output (I/O) ports,
// and static constant volatile-qualified objects model memory-mapped input ports such as a real-time clock.

// The values stored in these objects may change without the knowledge of the compiler. For example, every time the value of a real-time clock is read, it may change,
// even if the value has not been written to by the C program. Using a volatile-qualified type lets the compiler know that the value may change, and ensures that
// every access to the real-time clock occurs (otherwise, an access to the real-time clock may be optimized away or replaced by a previously read and cached value).

// In the following code:

void volatile_qualified(void) {
    volatile int port;
    port = port;

}

// The keyword 'volatile' is used to inform the compiler that the variable 'port' may be changed at any time by "external sources that are not visible to the compiler".
// This prevents the compiler from optimizing aways reads/writes to the variable, ensuring that the variable's value is always fetched from memory rather than relying on
// cached value the compiler might have.

// NOTE: volatile-qualified types are used for communications with signal handlers and with setjmp/longjmp.
// NOTE: Usage of volatile is important in scenarios where variables can be modified by external factors (e.g, hardware interrupts, memory-mapped I/O), and the compiler needs to
// ensure that the most up-to-date value is used.

// RESTRICT

// In C, the restrict keyword is a type qualifier that can be used as a hint to the compiler to optimize pointer-based code. 
// It indicates to the compiler that a pointer is the only means to access the data it points to within a particular scope. 
// The purpose of restrict is to assist the compiler in performing more aggressive optimizations, 
// particularly with loop optimizations and pointer aliasing.

// Consider the following scenario:

void func(int *a, int *b, int *c) {
    for (int i = 0; i < 100; ++i) {
        a[i] = b[i] + c[i];
    }
}


// In this function, the pointers a, b, and c are passed as arguments. 
// The compiler has no knowledge that these pointers do not overlap (i.e., they do not point to the same memory locations).
// As a result, it may generate less efficient code due to concerns about pointer aliasing.

// By using restrict, you can inform the compiler that the pointers do not alias each other, 
// allowing it to perform more aggressive optimizations:

void restrict_func(int *restrict a, int *restrict b, int *restrict c) {
    for (int i = 0; i < 100; ++i) {
        a[i] = b[i] + c[i];
    }
}

// Here, the restrict keyword indicates that a, b, and c are not aliases, 
// and each pointer is the only means to access the data it points to within the scope of the function. 
// This enables the compiler to generate more optimized code, potentially by performing loop unrolling, 
// reordering instructions, or other optimizations that rely on the absence of pointer aliasing.

// restrict is typically used in performance-critical code where optimizing memory access patterns and 
// reducing pointer aliasing can lead to significant performance improvements. 
// It is commonly found in functions that operate on arrays or other large data structures, 
// especially in numerical or computational code where performance is crucial.

