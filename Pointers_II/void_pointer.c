#include <stdio.h>
#include <string.h>

struct Man {
	char* name;
	int height;
	float fat;
};


void copy_some_ints() {
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int b[10] = {0};

	memcpy(b, a, 7 * sizeof(a[0]));

	for (int i = 0; i < sizeof(b)/sizeof(b[0]); ++i)
		printf("%d\n", b[i]);

}


int main() {

	struct Man man = { .name="Tarokh", .height = 190, .fat=0 };
	struct Man man2;

	// we can also use memcpy for structs in C

	memcpy(&man2, &man, sizeof(man));

	char* first = "First sentence in the var";
	char second[100] = { '0' };
	int len = strlen(first);
	memcpy(&second[0], &first[0], len);
	void* voidPtr = &second[0];

	// printf("%c\n", (char)*(voidPtr));
	char c = *(char*)(voidPtr);
	printf("%c\n", c);

	printf("%s\n", second);

	copy_some_ints();

	return 0;
}

