/**
 *
 *	@author: Tarokh Yaghoubi
 *	@description:
 *		- Dynamic Memory Allocation in C
 *		- Memory management functions and concepts
 *
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


// C defines four storage durations: static, thread, automatic, and allocated.
// Dynamically allocated memory, is allocated from the heap at runtime.

// Note: Dynamically Allocated Memory is useful when the exact storage requirements for a program
// are unknown before runtime.

// "STORAGE (MEMORY) DURATION"

// Objects occupy "STORAGE" ("MEMORY"). which might be random access memory ("RAM"),
// read-only memory ("ROM"), or registers. Storage of allocated duration has significantly
// different properties than storage of either automatic or static storage duration.

// Objects of "AUTOMATIC STORAGE DURATION" are declared within a block or as a function
// parameter. The lifetime of these objects begins when their block exectution begins, and
// ends when the block execution comes to end.


// Objects declared in the "FILE SCOPE" have "STATIC STORAGE DURATION".
// The lifetime of these objects is the entire execution of the program, and their stored
// value is initialized prior to program startup. You can also declare a variable in the 
// "BLOCK SCOPE" to have "STATIC STORAGE DURATION" by using the storage-class specifier
// "STATIC".


// "THE HEAP AND MEMORY MANAGERS"
// Dynamically Allocated Memory has "ALLOCATED STORAGE DURATION". The lifetime of an allocated
// object extends from the allocation until the deallocation.
// Dynamically Allocated Memory is allocated from the heap, Which is simply one or more large,
// subdividable blocks of memory that are managed by the memory manager.
// The memory manager will request one or more blocks of memory from the operating system 
// and then allocate this memory to the client process when it invokes a memory allocation function.

// Note: "It is the callers responsiblity to ensure that the memory is deallocated".


// WHEN TO USE DYNAMICALLY ALLOCATED MEMORY ?
/*
 * 	- When exact storage requirements for a program are "Unknown"
 *	
 *	For Example: you might use dynamically allocated memory to read a table from a file at
 *	runtime, especially if you do not know the number of rows in the table at compile time.
 *	Similarly you might use dynamically allocated memory to create "linked lists", "hash tables",
 *	"binary trees", or other data structures for which the number of data elements is "Unknown" at
 *	compile time.
 *
 * 	note that "MEMORY LEAKS" happen when allocated memory isn't returned to the memory manager
 *	If these "MEMORY LEAKS" are severe, the memory manager will eventually be unable to satisfy
 *	new requests for storage.
 */


// "MEMORY MANAGEMENT FUNCTIONS IN C"

// The "C Standard Library" defines memory management functions for allocating and deallocating dynamic
// memory. These functions include "malloc", "aligned_alloc", "calloc", "realloc".
// You can call the "free" function to deallocate memory.


/* 
 NOTE: "The OpenBSD reallocarray function is not defined by the C Standard Library but can be useful
 for memory allocate"
*/

// MALLOC

typedef struct {
	char c[10];
	int i;
	double d;
} widget;

void allocate_mem_malloc(void) {
	widget* p = malloc(sizeof(widget));
	if (p == NULL) {
		printf("%s\n", "UnExpected Error Occured while mem allocation");
	}
	// Continue the process...
	
}

/*
 *  NOTE: "All memory allocation functions accept an argument of type size_t that specifies the number
 *  of bytes of memory to be allocated. For portability we use the sizeof() operator when calculating
 *  the size of objects, as the size of objects of various types, such as int and long, may differ 
 *  among implementations."
 *
*/

// Malloc function returns either NULL to indicate an error, or a pointer to the allocated space.
// Therefor, we check whether malloc returns a NULL pointer or not, and handle the error.

// After the function successfully returns the allocated space, we can store to members of the widget
// structure through the pointer 'p'. for example, p->i will access i which is an integer.

// NOTE: "you can store the return value from malloc as a void pointer to avoid declaring a type for the referenced object: "

// void* p = malloc(size);
// you can use a char pointer, which was the convention before the void type was introduced in C.
// char* p = malloc(size);


