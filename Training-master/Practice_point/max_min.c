#include<stdio.h>
int main(void)
{
	int a = 10, b = 12, m;
	m = max(a,b);
	printf("max= %d\n", m);
	return 0;
}
int max(int a, int b)
{
	int z;
	z = a>b ? a:b;
//	(a>b) ? z = a : z = b;
	return z;
}
