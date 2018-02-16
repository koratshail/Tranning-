#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

pthread_attr_t attr;
pthread_t t1;

void *fun(void *arg)
{
	printf("thread_start\n");
	sleep(5);
	printf("thread_exit\n");
	pthread_exit(NULL);
}

int main(void)
{
//	pthread_attr_init(&attr);
//	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
//	pthread_t t1;
	pthread_create(&t1, &attr, fun, NULL);
//	sleep(2);
	pthread_exit(NULL);
}
	
