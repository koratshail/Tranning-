#include<stdio.h>
#include<unistd.h>
//#include<pthread.h>
char string[] = "India\n";
int main(void)
{
	printf("page size %ld\n", sysconf(_SC_PAGESIZE));
	printf("Softnautics\n");
	printf("%s", string);
	return 0;
}
