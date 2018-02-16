#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char *ptr = malloc(10*sizeof(char));
	int i;

	for (i = 0; i < 10; i++) {
		ptr[i] = i + 20;
	}
//	++ptr;
/*	++ptr;
	++ptr;
	++ptr;
*/	free(ptr);
	return 0;
}
