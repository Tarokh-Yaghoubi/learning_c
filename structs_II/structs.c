
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// More on STRUCTS in C

// if you have a  substructure like the following, you can initialize members of that structure
// by the following:

struct cabin_info {
	int window_count;
	int o2level;
};

struct spaceship {
	char* manufacture;
	struct cabin_info c;
};

// We can also have an array of structs, like this:

#define MAX_PASSENGERS 10

struct passenger {
	char *name;
	int covid_vaccinated;	// Condition (Boolean)
};

struct Travel {
	char *country;
	struct passenger passenger[MAX_PASSENGERS];
}


int main(void) {

	struct spaceship s {
		.manufacture = "General Products",
		.c.window_count = 8,
		.c.o2level = 21
	};

	// This is another approach, both ways work
	
	struct spaceship t {
		.manufacture = "SpaceX",
		.c = {
			.window_count = 23,
			.o2level = 25
		}
	};


	struct Travel travel {

		.country = "Denmark";
		.passenger {
			[0].name = "Jacob";
			[0].covid_vaccinated = 1;
			[8].name = "John";
			[8].covid_vaccinated = 0;
			// or all at once:
			[4] = { .name="Jack", .covid_vaccinated=1 },
		}

	};


	printf("%s : %d seats, %d oxygen\n",
			s.manufacturer, s.c.window_count, s.c.o2level);

	return EXIT_SUCCESS;
}

