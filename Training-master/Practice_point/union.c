#include<stdio.h>
int main(void)
{
	union ex {
		int a;
		char b;
		float c;
	} un;
	un.a = 49;
	printf("%c\n", un.b);
	return 0;
}
