#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<unistd.h>

void *thread(void *arg)
{
	char array1[1024*4];
	strcpy(array1, "Softnautics");
	printf("%s\n", array1);

	char array2[1024];
	strcpy(array2, "Softnautics");
	printf("%s\n", array2);

	printf("Thread stack\n");
	printf("Size of arrays\n");
	printf("Array1 : %lu\n", sizeof(array1));
	printf("Array2 : %lu\n", sizeof(array2));
	sleep(2);
	pthread_exit(NULL);
}
int main(void)
{
	char array1[1024*4];
	strcpy(array1, "Softnautics");
	printf("%s\n", array1);
	pthread_t t1;
	pthread_create(&t1, NULL, thread, NULL);

	char array2[1024*9];
	strcpy(array2, "Softnautics");
	printf("%s\n", array2);
	printf("Size of arrays\n");
	printf("Array1 : %lu\n", sizeof(array1));
	printf("Array2 : %lu\n", sizeof(array2));
	sleep(2);
	pthread_join(t1, NULL);
	return 0;
}
