
#include "../requirements.h"

#define TYPESTR(x) _Generic((x), \
int: "int", \
long: "long", \
float: "float", \
double: "double", \
default: "something else")

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
	printf("i is type -> %s\n", TYPESTR(i));
	printf("f is type -> %s\n", TYPESTR(f));
	return EXIT_SUCCESS;
}
