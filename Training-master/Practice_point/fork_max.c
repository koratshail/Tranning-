#include<stdio.h>
#include<unistd.h>
int main(void)
{
	int i;
	for (i = 0; i < 10000; i++) {
		fork();
	}
	printf("I = %d\n", i);
	sleep(5);
	return 0;
}
