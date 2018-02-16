#include<stdio.h>
int main(void)
{
	int a = 10;
	printf("a = %d\n", a);
	{
//		int a;
		a = 12;
		printf("a = %d\n", a);
	}
	printf("a = %d\n", a);
	return 0;
}
	
