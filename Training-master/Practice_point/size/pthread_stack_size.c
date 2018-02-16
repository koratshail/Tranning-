#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

//#define handle_error(

pthread_attr_t attr;

void *fun1(void *arg)
{
	long unsigned int *ptr = (long unsigned int *) malloc(sizeof(int));
	
	pthread_attr_getstacksize(&attr, ptr);
	
	pthread_exit(ptr);
}

void *fun2(void *arg)
{
	long unsigned int *ptr = (long unsigned int *) malloc(sizeof(int));
	
	pthread_attr_getstacksize(&attr, ptr);
	
	pthread_exit(ptr);
}

int main(void)
{
	void *ret;
	long unsigned int size;
	pthread_t t1, t2;
	pthread_attr_init(&attr);
	pthread_attr_getstacksize(&attr, &size);
	printf("Ret1: %lu\n", *(long unsigned int *) &size);
	pthread_create(&t1, &attr, fun1, NULL);
	pthread_create(&t2, &attr, fun2, NULL);
	pthread_join(t2, &ret);
	printf("Ret2: %lu\n", *(long unsigned int *) ret);
	free(ret);
	pthread_join(t1, &ret);
	printf("Ret3: %lu\n", *(long unsigned int *) ret);
	free(ret);
	return 0;
}
