
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Animal {
	char* name;
	int leg_count, speed;
};

// This is another struct that does not have a name 
// so we call it anonymous

struct {
	char* name;
	int leg_count, speed;
}; // here we have a struct that has not name, so how can we use it

// next is a pointer to struct
struct node {
	int data;
	struct node *next;
};

struct len_string {
	int length;
	char data[8];
};

int main(void) {
	
	struct node *head;
	head = malloc(sizeof(struct node));
	head->data = 11;
	head->next = malloc(sizeof(struct node));
	head->next->data = 22;
	head->next->next = malloc(sizeof(struct node));
	head->next->next->data = 33;
	head->next->next->next = NULL;

	for (struct node *cur = head; cur != NULL; cur = cur->next)
		printf("%d\n", cur->data);

	struct len_string *s = malloc(sizeof (*s) + 40);
	strcpy(s->data, "This is the first sentence");
	
	// This might not crash cause we have allocated
	// extra memory

	return EXIT_SUCCESS;
}

