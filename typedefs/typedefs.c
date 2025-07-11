#include <stdio.h>

struct Animal {
	char* name;
	int leg_counts, speed;
}

typedef struct Animal Animal;

// This is also possible

typedef struct Address {
	char* ip, *type;
	int port;
} Address;	// So this is the new name, this is exactly like the one above, but it is all-in-one.

// We can also have Anonymous Structures, which has no name, but we create alias from it directly using typedef.

typedef struct {
	char* firstname;
	char* lastname;
	int age;
} Person;	// This the new ALIAS name.

typedef float app_float;
// Now if someday I wanna change float to double in my app I can simply change the typedef, and  I don't need to change every float to
// for example; double.

// typedef long double app_float;

// this is possible but it is not recommended
/*
	typedef int* intPtr;
	int a = 10;
	intPtr x = &a;
*/


// this is possible but it is not recommended 
/*
	typedef int Array[5];
	Array arr = {1, 2, 3, 4, 5};
*/


int main() {

	struct Address address;	// This works
	Address address1;	// This also works
	app_float first, second, third;
}
