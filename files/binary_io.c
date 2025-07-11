
#include <stdio.h>

void read_binary() {

	FILE* file;
	unsigned char c;

	file = fopen("output.bin", "rb");

	while (fread(&c, sizeof(char), 1, file) > 0)
		printf("%d \n", c);

}


int main() {

	FILE* file;
	unsigned char bytes[6] = {5, 37, 0, 22, 145, 30};
	file = fopen("output.bin", "wb");

	// For the second/third arguments of fwrite we can say:
	// We have items that are this big, and we want to write that many of them.
	// Here; each record is the size of a char, and we have 6 of them.
	
	fwrite(bytes, sizeof(char), (sizeof(bytes)/sizeof(bytes[0])), file);
	fclose(file);

	read_binary();

	return 0;

}

