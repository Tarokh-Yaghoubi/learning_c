
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Connection {

	char* ip;
	struct Connection* next;
};

int main(int argc, char **argv) {


	struct Connection *connect = malloc(sizeof(struct Connection));
	connect->ip = "123";
	connect->next = malloc(sizeof(struct Connection));
	connect->next->ip = "345";
	connect->next->next = malloc(sizeof(struct Connection));
	connect->next->next->ip = "456";
	connect->next->next->next = NULL;

	for (struct Connection *curr  = connect; curr != NULL; curr = curr->next)
		printf("%s\n", curr->ip);

	return EXIT_SUCCESS;
}
