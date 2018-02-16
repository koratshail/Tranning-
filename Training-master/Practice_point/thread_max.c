#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
void *thread(void *);
int main(void)
{
	pthread_t thrd[40000];
	int i;
	int err;
    for (i = 0; i < 20000; i++) {
		err=pthread_create(&thrd[i], NULL, thread, NULL);
		if(err!=0) {
			printf("thread creation failed: %d\nError code %d\n", i, err);
			break;
	}
	}
	sleep(3);
	printf("thread creation failed: %d\nError code %d\n", i, err);
	return 0;
}

void *thread(void *k)
{
	sleep(100);//make the thread still alive
	return 0;
}
