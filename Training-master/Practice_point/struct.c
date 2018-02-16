#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	struct st { int data1; int data2; float data3; };
	struct st *ptr;
	int *pt;
//	printf("Size of *ptr: %d\n", sizeof(ptr));
	pt = malloc(sizeof(12));
	ptr = pt;
	ptr->data1 = 112;
	printf(" data1 %d\n", ptr->data1);
	return 0;
}
