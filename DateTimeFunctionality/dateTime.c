


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

	// Converting time_t to struct tm
	// localtime(), this function converts a time_t to a struct tm in local time.
	// gmtime(), this function converts a time_t to struct tm in UTC. 

	printf("LOCAL -> %s\n", asctime(localtime(&now)));
	printf("	UTC: %s\n", asctime(gmtime(&now)));

	// here we have a struct which we can print each part of it. 
	
	// CONVERTING struct tm TO time_t
	
	// you can use mktime() to go the other way.
	// mktime() just sets the values of tm_wday and tm_yday for you.
	// so do not bother filling them out because they'll just be overwritten.
	// Also you can set tm_isdst to -1, to have it make the determination for you.
	// Or you can manually set it to true or false.
	
	struct tm some_time = {

		.tm_year = 82,
		.tm_mon = 3,
		.tm_mday = 12,
 		.tm_hour=12,
		.tm_min=0,
		.tm_sec=4,
		.tm_isdst=-1,

	};

	time_t some_time_epoch;

	some_time_epoch = mktime(&some_time);
	printf(" %s", ctime(&some_time_epoch));
	printf("\n is DST: %d\n", some_time.tm_isdst);

	return EXIT_SUCCESS;

}

