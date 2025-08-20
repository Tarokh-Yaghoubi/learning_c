
#include "../requirements.h"


int main() {


	int i;
	float f;
	char c;

	char*s = _Generic(i,
			int: "that var is an int",
			float: "that var is a float",
			default: "that var is something else"
			);

	printf("%s\n", s);

	return EXIT_SUCCESS;
}
