
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// More on STRUCTS in C

// if you have a  substructure like the following, you can initialize members of that structure
// by the following:

struct cabin_info {
	int window_count;
	int o2level;
}

struct spaceship {
	char* manufacture;
	struct cabin_info c;
}

int main(void) {
	
	struct spaceship s {
		.manufacture = "General Products",
		.c.window_count = 8,
		.c.o2level = 21
	};

	printf("%s : %d seats, %d oxygen\n",
			s.manufacturer, s.c.window_count, s.c.o2level);

	return EXIT_SUCCESS;
}

