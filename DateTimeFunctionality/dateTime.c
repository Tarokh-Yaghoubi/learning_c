


#include "../requirements.h"


int main() {

	// As a general rule, if you are describing an event that happens one time, like a log
	// entry, or a rocker launch, use UTC.
	
	// On the other hand, if it is something that happens the same time in every time zone,
	// like New Years Eve or dinner time, use local time.
	
	// They're two types for representing time in C:
	// 1- time_t
	// 2- struct tm
	
	// time_t represents the number of seconds since Epoch, Epoch is in some ways 
	// the start of time from the computers perspective (UNIX time).
	// which is 1 JANUARY 1970
	// time_t can go negative to represent times before Epoch.
	
	time_t now;
	now = time(NULL);	// you can take it like this 
	time(&now);	// or like this
	printf("%s\n", ctime(&now));

	return EXIT_SUCCESS;
}
