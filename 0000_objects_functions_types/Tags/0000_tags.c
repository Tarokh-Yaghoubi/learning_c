/*
*
*   Author: Tarokh Yaghoubi
*   Description:
*       - Tags in C
*       - What are tags | important notes on tags in C
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

// Tags are a special naming mechanism for structs, unions, and enumerations.
// For example, the identifer 's' appearing in the following structure is a tag.

struct s {
    int a;
    // --snip--
};

// By itself, a tag is not a type name and cannot be used to declare a variable, instead, you must declare variables of this type as follows:

struct s v;     // instance of struct s
struct s *p;    // pointer to struct s

// The names of unions and enumerations are also tags and not types, meaning that they cannot be used alone to declare a variable. For example:

enum day { sun, mon, tue, wed, thu, fri, sat };
// day today;  // error
enum day today; // correct

// The tags of structures, unions, and enumerations are defined in a separate namespace from ordinary identifiers. This allows a C program 
// to have both a tag and another identifier with the same spelling in the same scope

struct Properties {
    int user_id;
    char username[30];
    char password[40];
    _Bool isActive;
};


enum status { ok, fail };   // enumeration
enum status status(void);   // function, with the same name as the enumeration
struct Properties _properties(void);    // function, with the type of the structure

// because Properties is a tag and not a type, while declaring or defining a function, or variable, we must mention the name 'struct' before it.


// you can even declare an object 's' of type 'struct s'
struct s s;

// This may not be a good practice, but it is valid in C. You can think of struct tags as type names and define an alias for the tag by using a 'typedef'. Here is an example:

typedef struct st { int something; } als;

// This now allows you to declare variables of type 'als' instead of 'struct st'.
// NOTE: The tag name in struct, union, and enum is optional, for example:

typedef struct {
    int x;
    float y;
    _Bool isDead;
} life;

// now, life is an alias for the structure, which can be used to declare variables and functions and so on.
// NOTE: life is not a tag, life is a defined type, an alias. so we do not need to use the struct keyword for declaring functions and other objects.

life life_function(void);       // declaring a function with type life.


// example function
life life_function(void) {
    life newLife;
    newLife.x = 43;
    newLife.y = 13.4;
    newLife.isDead = false;

    return newLife;

}

// This works fine except in the case of self-referential structures that contain pointers to themselves.
// we can declare a typedef as well.
// EXAMPLE:

typedef struct tnode {
    int count;
    struct tnode *left;
    struct tnode *right;

} tnode;    // tnode is the alias, it has the same name with the tag.

// Most C programmers use a different name for the tag and the typedef, but the same name works just fine. You can also define this type before the structure so that
// you can use it to define the 'left' and 'right' members that refer to other objects of type tnode:

typedef struct tnode1 tnode1;
struct tnode1 {
    int count;
    tnode1 *left;
    tnode1 *right;

};

// NOTE: Type deinitions (typedef)'s, can improve code readability beyond their use with structures.





// function
enum status status(void) {
    int stat = 0;
    if (stat == 0)
        return ok;
    else
        return fail;

}


// function
struct Properties _properties(void) {
 
    struct Properties props;

    props.user_id = 23;
    strcpy(props.username, "tarokh");
    strcpy(props.password, "iambatman");
    props.isActive = true;

    return props;

}


int
main(void) {
    life life_result = life_function();
    enum status result = status();
    struct Properties res = _properties();

    if (result == ok)
        printf("%s\n", "Operation was successful");
    else
        printf("%s\n", "Operation Failed");


    printf("userId is [%d]\n", res.user_id);
    printf("username is [%s]\n", res.username);
    printf("password is [%s]\n", res.password);
    if (res.isActive == true) {
        printf("USER [%s] is active : [%d]\n", res.username, res.isActive);
    } else {
        printf("USER [%s] is not active : [%d]\n", res.username, res.isActive);
    }
    if (life_result.isDead == false) {
        printf("The user is still alive ! isDead id FALSE -->>  [%d]\n", life_result.isDead);
    }

    return EXIT_SUCCESS;

}


