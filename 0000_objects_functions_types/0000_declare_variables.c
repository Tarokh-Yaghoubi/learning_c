
#include <stdio.h>
#include <stdlib.h>

/**
*
*       Author: Tarokh
*       Description:
*           − learn how to declare a variable
*           − learn how to use the pre-declared variable
*
*/          

// DECLARING VARIABLES

// When you declare a variable, you give it a 'type' and a 'name', or identifier, by which to reference the variable.
// DATA_TYPE    VARIABLE_NAME = VALUE;      // definition
// DATA_TYPE    VARIABLE_NAME;              // declaration

// EXAMPLE

int variable_declaration_definition_example(void) {
    
    int number = 23;    // defining a variable
    int age;            // declaring a variable (you must give it a value later)

    printf("%d\t%d\n", number, age);    // wrong: now age can have any value randomly !‌ (Undefined Behavior)

    // if the true value of a variable is going to appear later, you must give the variable the value of zero '0'.
    // for example, if user is going to give age a value, you must:
    age = 0;
    // and then change the value of age by the users input. (in this way , you are avoiding {Undefined Behavior} )

    // also, it is good to know, that sometimes it is unnecessary to initialize a variable by zero '0',
    // for example, when the variables value is computed from other variables ! like this:

    int first = 34;
    int second = 6;
    int third = first + second;     // third, didn't need to get initialized with zero.

    // but imagine it was like this:

    int wrong;
    int another_var = 34;
    int wrong_result = wrong + another_var;     // variable "wrong" is not zero !!‌ the result will be un-expected.
    printf("value of wrong_result is ----->>>> %d\n", wrong_result);

}

// NOTE : you can declare multiple variables in any single declaration.
// but they must all have the same data type !!‌
// EXAMPLE 

int multiple_variable_declaration(void) {
    
    int first, second, third = 4;       // here, first, second and third are all correctly declared, they all have the type int.
    float fl1, fl2, fl4;                // fl1, fl2, fl4, all have the type float.
    char *ptr, chr;                     // ptr is a pointer to character, chr is a simple variable  (they both have the type "char")

    int mp[12], n[23], r[34][34];       // here, mp and n are arrays, r is a multi-dimensional array (they all have the type "int")

}


// It is recommended to declare each variable in its own line.
// note that: Readable and Understandable code is less likely to have defects.


int main(void) { 

    variable_declaration_definition_example();
    return EXIT_SUCCESS;
}


