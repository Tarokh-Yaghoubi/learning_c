

// Use of realloc()  to grow a buffer as we read more data. 

// Use of realloc()  to shrink the buffer down to the perfect size after we've completed// the read.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline(FILE* fp)
{
	int offset = 0;
	int buffsize = 4;
	char* buf;
	int c;

	buf = malloc(buffsize);	// Allocate initial buffer
	
	if (buf == NULL)
		return NULL;

	while (c = fgetc(fp), c != '\n' && c != EOF) {
		if (offset == bufsize - 1) {
			bufsize *= 2;
			char* new_buf = realloc(buf, buffsize);
			if (new_buf == NULL) {
				free(buf);
				return NULL;
			}
			
			buf = new_buf;
		}

		buf[offset++] = c;	// Add the byte onto the buffer

	}

	if (c == EOF && offset == 0) {
		free(buf);
		return NULL;
	}

	// shrink to fit
	
	if (offset < bufsize - 1) {
		char* new_buf = realloc(buf, offset + 1);

		if (new_buf != NULL)
			buf = new_buf;

	}

	buf[offset] = '\0';

	return buf;

}

int main(void)
{
	FILE* fp = fopen("foo.txt", "r");
	char* line;

	// Because readline() is returning a pointer to a malloc()ed buffer,
	// you must call free();
	
	while ((line = readline(fp)) != NULL) {
		printf("%s\n", line);
		free(line);
	}

	fclose(fp);
}

