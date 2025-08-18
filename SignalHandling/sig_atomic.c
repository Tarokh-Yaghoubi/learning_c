

/*
 This is one of the hidden sharp edges in POSIX and C programming.
 
 1- Atomic -> An operation that cannot be interrupted halfway.
 
 2- Why is it important in Signals ? -> Because a signal can interrupt your program anywhere.
 if you're in the middle of updating a variable and a signal handler interrupts, the variable could be
 left in a broken/inconsistent way.

 3- Lock-free atomic / sig_atomic_t -> The C standard guarantees that sig_atomic_t assignments are atomic and safe inside
 signal handlers. that is why people use a volatile sig_atomic_t flag to communicate between the handler and the rest of the program.

 4- In signal handlers you cannot safely call most library functions, (printf, malloc, ...). or touch most variables.
 You're only allowed to safely assign to volatile sig_atomic_t or lock-free atomic objects.

*/

// This is guaranteed to be atomic for reads and writes.
// volatiles tells the compiler: do not optimize away accesses, because this may change asynchronously (like from a signal)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

#include <stdatomic.h>

volatile sig_atomic_t flag = 0;
atomic_int counter = 0;

void handler(int sig) {

	flag = 1; // safe / atomic 
}

// Lock-Free Atomics
// C11 introduced <stdatomics.h> with atomic types like atomic_int, atomic_float, etc.
// "Lock_free" means the CPU can do the atomic operation without using heavy synchronization like MUTEXES.

void handler2(int signal) {

	(void)signal;
	atomic_fetch_add(&counter, 1);	// safe in signal handler if lock free
}

int main() {
	signal(SIGINT, handler);
	while (!flag) {
	// printf("WORK \n"); -> Here's the problem
		write(STDOUT_FILENO, "WORK\n", 5);
	}

	printf("Got SIGINT\n");
	
}

//  because printf() internally uses global buffers, locks, memory allocation, etc.
//  If a signal handler interrupts while printf is running in the main program, calling printf again could corrupt
//  its state. 
//  so it is not async-signal-safe.
//  The POSIX spec has a list of async-signal-safe functions (like write(), _exit(), signal() itself). Outside of those 
//  you are in danger.

