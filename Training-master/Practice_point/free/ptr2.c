#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int i;
	char *ptr1 = NULL, *ptr2;

	ptr1 = (char *) malloc(5);
	printf("ptr1: %x", ptr1);

	ptr2 = malloc(20);
	printf("ptr2: %x", ptr2);

	for (i = 0; i < 10; i++) {
		ptr1[i] = i;
	}

	*ptr2 = 99;

	for (i = 0; i < 10; i++) {
		printf(" %d\n", ptr1[i]);
	}

	return 0;
}
