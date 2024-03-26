/**
*
*   Author: Tarokh-Yaghoubi
*   Description:
*       - Unions in the C programming language
*       - What are Unions, How to define and use unions in C
*/

// Union types are similar to structures, except that the memory used by the member objects overlaps.
// This needs more explanation:
// In C programming, unions and structures are both used to define custom data types that can hold multiple members of different types. However, they differ in how they allocate memory for their members.

// this means, when you define a structure (struct), each member within the structure, occupies its own separate memory location. This means that the memory used by each member does not "overlap" with the
// memory used by other members. for example:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

struct example {
    int num;
    float fnum;
    char ch;
};

// In the above structure definition, 'num' 'fnum' and 'ch' are stored in distinct memory locations.

// On the other hand, when you define a union ('union'), all members within the union share the same memory location. As a result, the memory used by one member overlaps with the memory
// used by other members, for example:

union uni_example {
    int num;
    float fnum;
    char ch;
};

// In this union definition, 'num' 'fnum' and 'ch' share the same memory location. if you assign a value to one member, it will modify the memory occupied by all members.

// Here is an illustration of how memory is allocated for a union:
/*
        Memory layout for union example:
        +-----------------------------------+
        |               Memory              |
        +-----------------------------------+
        |             num / fnum / ch       |
        +-----------------------------------+
*/

// So, when it is mentioned that "the memory used by the member objects overlaps" in a union, it means that the memory allocated for one member can also be accessed through other members.
// This can be a useful feature in certain scenarios, but it also requires careful handling to ensure that the correct member is accessed at any given time, as changed to one member can effect
// the values of other members due to the shared memory location.

// NOTE: unions can contain an object of one type at one time, and an object of a different type at a different time, but never both objects at the same time.
// NOTE: unions are primarily used to save memory.

union {
    struct {
        int type;
    } n;
    struct {
        int type;
        int intnode;
    } ni;
    struct {
        int type;
        double doublenode;
    } nf;

} u;

int
main(void)
{
    u.nf.type = 1;
    u.nf.doublenode = 3.14;
    printf("%d %.2lf \n", u.nf.type, u.nf.doublenode);
    return EXIT_SUCCESS;

}

