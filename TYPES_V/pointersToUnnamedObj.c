
#include "../requirements.h"

struct coord {
	int x, y;
};

int * get3490(void);

void print_coord(struct coord* c) {

	printf("%d\t%d\n", c->x, c->y);
}

int main() {

	// Turns out that we can take the address of an unnamed object with & like always.
	// This is because in general if an operator would have worked on a variable of that type,
	// you can use that operator on an unnamed object of that type.	
	print_coord(&(struct coord){.x=23, .y=65});
	printf("%d\n", *get3490());
	return EXIT_SUCCESS;
}

int * get3490(void) {
	return &(int){3490};	// Don't do this ! 
}

