

#define ANTELOPE 1
#define OCTOPUS 2

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// These two structures begin with a common initial sequence.

struct a {
	int x;
	float y;
	char *p;
};

struct b {
	int x;
	float y;

	double *p;
	short z;
};

// Creating a union of these two

union foo {
	struct a sa;
	struct b sb;
};

// What this rule tells us is that we're guaranteed that the members of the common
// initial sequences are interchangeable in code. That is:

// f.sa.x == f.sb.x
// f.sa.y == f.sb.y

// NOTE: The names of the members in the common initial sequence does not matter
// all that matters is that the types are the same.

struct common {
	int type;	// common initial sequence
};

struct antelope {
	int type;	// common initial sequence
	int loudness;
};

struct octopus {
	int type;	// common initial sequence
	int sea_creature;
	float intelligence;
};

union animal {
	struct common common;
	struct antelope antelope;
	struct octopus octopus;
};
// ANTELOPE and OCTOPUS are #define'd to get used here.

// We're going to write a function that prints a union animal. it has to somehow 
// be able to tell if  its looking at a "struct antelope" or a "struct octopus"

void print_animal(union animal *x) {

	switch (x->common.type) {
		case ANTELOPE:
			printf("Antelope: loudness:%d\n", x->antelope.loudness);
			break;
		case OCTOPUS:
			printf("Octopus: sea_creature:%d\n", x->octopus.sea_creature);
			printf("	 intelligence:%f\n", x->octopus.intelligence);
			break;

		default:
			printf("Unknown Animal Type\n");
	}

}


int main() {

	union animal a = { .antelope.type=ANTELOPE, .antelope.loudness=12 };
	union animal b = { .octopus.type=OCTOPUS, .octopus.sea_creature=1,  .octopus.intelligence=12.4 };


	print_animal(&a);
	print_animal(&b);


	return EXIT_SUCCESS;
}
