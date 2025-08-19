

#include <stdio.h>

struct coord {
	int x;
	int y;
};

void print_struct(struct coord stc) {
	printf("%d\t%d\n", stc.x, stc.y);
}

int main() {
	print_struct((struct coord){.x=23, .y=56}); // this is how it works in structs instead of creating one
	return 0;
}
