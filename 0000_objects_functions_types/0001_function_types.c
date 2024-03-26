
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
*
*   Author: Tarokh Yaghoubi
*   Description: 
*       - Function Types in the C programming language
*       - How to declare and use functions in C
*/

// NOTES:
// - Function  types are derived types. in this case, type is "derived" from the return type and the number and types of its parameters.
// - The return type of a function cannot be an array type.
// - When you declare a function, you use the "function declarator" to specify the name of the function and the return type.
// - If the function declarator includes a parameter type list and a definition, the declaration of each parameter must include an "identifier"
// except parameter lists with only a single parameter of type "void", which needs no identifier.
// A few function type declarations:


int f(void);
int *fptr();
void vd1(int i, int k);
void vd2(int, char*);

// At first, we are declaring a function with the name f, that has no parameters (so it is void), and is returning an "integer".
// Next, we are declaring a function with the name "fptr", with no specified parameters, that is returning a "pointer to an int" (it will return an address).
// After, we declare a function with the name "vd1", which is not returning anything, and it is taking two integer as its parameters, (int i and int k)
// At last, the function "vd2" is not returning anything, and it is taking two integers as its parameters.
// NOTE THAT: In function declarations, specifying a name for the parameters is not necessary (only the type is vital to avoid errors), so, the declaration of "vd2" is completely "CORRECT".
// However, providing parameter names is good practice for self-documenting code, so omitting the identifers "as done with 'vd2' " is NOT recommended.
// NOTE THAT: you should NEVER declare functions with an empty parameter list in C.
/*
    void foo();  -> this is known as a old-style function declaration in C, it tells the compiler that 'foo' is a function that takes an unspecified number of arguments.
    This was a feature of the original C language, but it is considered outdated and error-prone for the reasons below:
        - lack of type checking: with an empty parameter list, the compiler won't check if the arguments passed to the function match the expected types. This can lead to subtle bugs.
        - potential for undefined behavior: calling a function with arguments of mismatched types or counts can result in undefined behavior, meaning the behavior of the program is
        unpredictable. This can lead to crashes, data corruption, or security vulnerabilities.

    so this is a better and safer way to declare a function that takes no parameters:
    
    void foo(void); 
 
*/

// A Function type with a parameter type list is known as a "Function Prototype". A Function Prototype informs the compiler about the number and types of parameters that a Function accepts.
// Examples:

int max(int a, int b);      // function declaration

int
main(void) {
    int first, second;
    first = 54;
    second = 94;

    int another_res = wrong_max(first, second); // this will cause problems
    printf("%d\n", another_res);

    int res = max(first, second);
    printf("%s %d\n", "The max number between first and second is", (int)res);
    return EXIT_SUCCESS;
}

int 
max(int a, int b)   // function definition
{

    // this is the function body

    return (a > b) ? a : b;
}


// The specification of a function type must not include any "type qualifiers" such as const or volatile,  _Atomic and ...

int
wrong_max(int a, int b) {
    return (a > b) ? a : b;
}

// Consider that, "wrong_max" will not work if we use older versions of C, and it will work with giving this warning in newer versions of C compilers:
// warning: implicit declaration of function ‘wrong_max’. This warning typically occurs when you call a function in C before declaring or defining it.
/*
    For example:
    
    int wrong_max(int ,int);
    int res = wrong_max(34, 54);
    int wrong_max(int a, int b)
    { return a > b ? a : b; }

    ! here, we are defining the function after calling it.

    if we use a function in this way, then we are going to face a lot of issues, like:

        - Undefined Behavior: When a function is called without being declared or defined, the behavior of the program is undefined according to the C standard. This means that the program may compile
        and run without errors, but it will exhibit unpredictable behavior, This could include crashes, incorrect results, or other runtime errors.

        - Portability: While some compilers might allow implicit function declarations as a feature, relying on this behavior makes your code less portable. Different compilers or compiler settings, might
        handle implicit declarations differently, leading to inconsistencies across platforms.

        - Security Risks: implicit function declarations can also introduce security vulnerabilities. For example: if a function is implicitly declared with a different signature that its actual definition,
        it can lead to stack corruption or other memory-related issues, which attackers could potentially exploit, like this CATASTROPHE:

        void process_data(int num);

        int main()
        {
            int secret_data = 43;
            process_data(secret_data);
            return 0;
        }

        void process_data(char* data) {
            printf("%s\n", data);       -> the definition is different !!
        }


*/


