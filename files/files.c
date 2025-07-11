#include <stdio.h>

void fputx_test() {

	FILE* file;
	int x = 32;
	// since stdout is a file, you can replace the file below with stdout, like file = stdout
	file = fopen("hello.txt", "w+");

	fputc('a', file);
	fputc('\n', file);
	fprintf(file, "x = %d\n", x);
	fputs("Hello World\n", file);

	fclose(file);
}


void fscanf_test() {

	char name[100];
	int mass;
	float length;
	FILE* file;

	file = fopen("whales", "r");

	while (fscanf(file, "%s %f %d", &name[0], length, mass) != EOF) {
		printf("%s whale is %d kilograms, and %.1f meters\n", name, mass, length);
	}

	fclose(file);

}

int main() {

	FILE* file;
	int linecount = 0;
	char s[1024];

	file = fopen("hello.txt", "r");

	while (fgets(s, sizeof(s), file) != NULL) {
		printf("%d: - [[0] -> %c] - %s", ++linecount, s[0], s);
	}

	fclose(file);

	return 0;
	
}
