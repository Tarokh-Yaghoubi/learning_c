/**
 *
 *	@author: Tarokh Yaghoubi
 *	@description:
 *		- Dynamic Memory Allocation in C
 *		- Memory management functions and concepts
 *
 */

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
