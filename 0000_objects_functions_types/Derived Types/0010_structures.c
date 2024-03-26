/**
*
*   Author: Tarokh Yaghoubi
*   Description:
*       - Structures in the C programming language
*       - How to define and use structures in the C programming language
*
*/

// A Structure type (also known as a struct) contains sequentially allocated member objects. Each object has its own name and may have a distinct type unlike arrays,
// which must all be of the same type. Structures are similar to record types found in other programming languages.
// This is an example of a structure in the C programming language:

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


struct sigrecord {

    int signum;
    char signame[20];
    char sigdesc[100];

};

void change_struct_ptr(struct sigrecord*);

// This structure has three member objects: signum of type int, signame is an array of type char, consisting of 20 elements,
// and sigdesc is an array of type char consisting of 100 elements.

// Structures are useful for declaring collections of related objects and may be used to represent things such as date, customer or personnel record.
// They are especially useful for grouping objects that are frequently passed together as arguments to a function, so you are not going to need to pass
// individual objects separately all the time.

// Once you have defined a structure, then you are going to need to have access to its members, reading and writing to the members and so on.
// for this, you are going to use the (.) operator (structure member operator). If you have a pointer to a structure, you can reference its members by using the 
// structure pointer (->) operator.
// EXAMPLE:

void
change_struct_ptr(struct sigrecord *sigline_ptr) {

    // here, the function has taken an object of the structure sigrecord, and it is changing the values of the structure members
    sigline_ptr->signum = 5;
    strcpy(sigline_ptr->signame, "SIGINT");
    strcpy(sigline_ptr->sigdesc, "Interrupt from keyboard");

    // here, we are trying to access the structure members using the structure pointer (->) operator, and print them out
    printf("%s\n", "change_struct_ptr:");
    printf("%s [%d]\n", "signal number is", sigline_ptr->signum);
    printf("%s [%s]\n", "signal name is", sigline_ptr->signame);

}

int
main(void) {

    struct sigrecord sigline;
    
    // here we pass the address of sigline to the function, the function is taking a pointer to the structure sigrecord
    change_struct_ptr(&sigline);

    // here, we change the values of signum and signame, using the structure member (.) operator
    sigline.signum = 23;
    strcpy(sigline.signame, "SIGKILL");

    printf("[%s] %s [%d]\n", sigline.signame, "has the signal number of", sigline.signum);

    return EXIT_SUCCESS;

}


