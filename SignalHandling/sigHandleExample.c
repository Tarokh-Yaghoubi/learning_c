

#include <stdio.h>

#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void hello(int x) {
	printf("Hello x = %d\n", x);
}

void goodbye(int x) {
	printf("good bye x = %d\n", x);
}

static void(*oldhandler)(int) = NULL;

int main() {

	oldhandler = hello;
	oldhandler(23);

	oldhandler = goodbye;
	oldhandler(76);

	return 0;
}

