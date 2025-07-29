
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(void) {

	// C offers is another way to have constant integer values by name: enum.
	
	enum {
		ONE=1,
		TWO=2
	};

	// Enums are automatically numbered unless you override them...
	
	enum {
		NET,
		FIRST,
		SECOND,
		THIRD,i
		FOURTH,
		FIFTH=100

	};

	enum resource {
		SHEEP,
		WHEAT,
		WOOD,
		BRICK,
		ORE
	};



	printf("%d %d\n", ONE, TWO);

	return EXIT_SUCCESS;
}
