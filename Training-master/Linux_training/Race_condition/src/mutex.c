/*
@file:	mutex.c
@Aim:	Write a program to remove the race condition between threads
	using posix mutex
@Author:Gaurang
@Date:	24 Oct 2017
*/

#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

unsigned long int count;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *countIncrement(void *arg);

int main(void)
{
	pthread_t t[2];
	if (pthread_create(&t[0], NULL, countIncrement, (void *) &t[0])) {
		printf("Error: pthread create fail\n");
		return -1;
	}
	printf("First thread is created\n");
	printf("Thread id for the first thread: %ld\n", t[0]);
	if (pthread_create(&t[1], NULL, countIncrement, (void *) &t[1])) {
		printf("Error: pthread create fail\n");
		return -1;
	}
	printf("Second thread is created\n");
	printf("Thread id for the second thread: %ld\n", t[0]);
	if (pthread_join(t[0], NULL)) {
		printf("Error: pthread join fail\n");
		return -1;
	}
	if (pthread_join(t[1], NULL)) {
		printf("Error: pthread join fail\n");
		return -1;
	}
	printf("\nTheorically count value = %ld\n", 2000000ul);
	printf("Count value after implementation of mutex = %ld\n", count);
	if (pthread_mutex_destroy(&mutex)) {
		printf("Error: mutex destroy fail\n");
		return -1;
	}
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	Count increment function
///		increment count by 1000000 for one time thread execution
///@param :	void *: pointer to the argument data here thread id
///@return:	void *: pointer to return status
/////////////////////////////////////////////////////////////////////////////*/
void *countIncrement(void *arg)
{
	unsigned long int i;
	if (pthread_mutex_lock(&mutex)) { /* lock */
		printf("Error: mutex lock fail\n");
		pthread_exit(NULL);
	}
	printf("Thread %ld is start updating, global count = %ld\n",
		*(pthread_t *) arg, count);
	for (i = 0; i < 1000000; i++) /* increment */
		count += 1;
	if (pthread_mutex_unlock(&mutex)) { /* unlock */
		printf("Error: mutex unlock fail\n");
		pthread_exit(NULL);
	}
	printf("Thread %ld is stop updating, global count = %ld\n",
		*(pthread_t *) arg, count);
	pthread_exit(NULL);
}

/* Output:
First thread is created
Thread id for the first thread: 140055837841152
Thread 140055837841152 is start updating, global count = 0
Second thread is created
Thread id for the second thread: 140055837841152
Thread 140055837841152 is stop updating, global count = 1000000
Thread 140055829448448 is start updating, global count = 1000000
Thread 140055829448448 is stop updating, global count = 2000000

Theorically count value = 2000000
Count value after implementation of mutex = 2000000
*/
