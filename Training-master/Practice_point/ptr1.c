#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void fun(char *ptr)
{
	strcpy(ptr, "INDIA");
}

int main(void)
{
	char *ptr = (char *) malloc(20);

	strcpy(ptr, "Bharat");
	printf("%s\n", ptr);

	fun(ptr);

	printf("%s\n", ptr);
	free(ptr);
	return 0;
}
