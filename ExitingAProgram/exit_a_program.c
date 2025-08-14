
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T 9.3

void onExit1() {
	printf("exit-handler 1 called -> \n");
}

void onExit2() {
	printf("exit-handler 2 called -> \n");
}

void onQuickExit1() {
	printf("quick-exit-handler 1 called -> \n");
}

void onQuickExit2() {
	printf("quick-exit-handler 2 called -> \n");
}

int main() {
	int* ptr;
	*ptr = 224234;
	while (1) {
		ptr++;
		*ptr = 24234234;
	}
	// Turns out there are a lot of ways to set up "hooks" so that a function gets called when the program exits.
	// All the functions in this section are in <stdlib.h>
	
	// main() has a implicit return 0, itself. (no other function is like this)
	// but it is a better idea to "return 0" yourself.
	
	// we also do have the exit() function/syscall. the code you pass to exit is the exit-status of the program.
	// where ever you call this function you will exit the program.
	
	// SETTING UP EXIT-HANDLERS using atexit()

	at_quick_exit(onQuickExit1);
	at_quick_exit(onQuickExit2);
	atexit(onExit1);	// This won't be called

	printf("About to exit -> \n");
	// sleep(2);

	// quicker exit with quick_exit; this is similar to a normal exit, 
	// except:
	//  - Open files might not be flushed
	//  - Temporary files might not be removed
	//  - atexit() handlers won't be called
	
	// but you can also call at_quick_exit() to trigger exit handlers as well.

	// If you wish to immidiately quit without flushing open files, and removing temp files
	// , and even not having the ability to call exit handlers, you can call _Exit();

	// _EXIT(0);
	

	// ASSERT:
	// This statement is used to insist that something be true, or else the program will exit.
	// Devs often use assert() to catch should-never happen type errors.

	// Also abort() is used, to exit quickly. 

	assert(T > 9);	// this will just carry on 
	int s = -12;
	// assert(s >= 0);	// this wil fail and exit 
	quick_exit(0);
}
