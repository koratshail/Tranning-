/*
@file:	semaphore.c
@Aim:	Write a programme to remove the race condition between threads using
	posix semaphore
@Author:Gaurang
@Date:	24 Oct 2017
*/

#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<semaphore.h> /* sem_t */

unsigned long int count;
sem_t sem;

void *countIncrement(void *arg);

int main(void)
{
	pthread_t t[2];
	/* semaphore: initial value = 1, semaphore for the threads */
	if (sem_init(&sem, 0, 1)) {
		printf("Error: semaphore not initialize\n");
		return -1;
	}
	/* first thread create */
	if (pthread_create(&t[0], NULL, countIncrement, (void *) &t[0])) {
		printf("Error: thread not created\n");
		return -1;
	}
	printf("First thread is created\n");
	printf("Thread id for the first thread: %ld\n", t[0]);
	/* second thread create */
	if (pthread_create(&t[1], NULL, countIncrement, (void *) &t[1])) {
		printf("Error: thread not created\n");
		return -1;
	}
	printf("Second thread is created\n");
	printf("Thread id for the second thread: %ld\n", t[0]);
	/* thread join */
	if (pthread_join(t[0], NULL)) {
		printf("Error: pthread join not successful\n");
		return -1;
	}
	if (pthread_join(t[1], NULL)) {
			printf("Error: pthread join not successful\n");
			return -1;
	}
	/* global count calculation */
	printf("\nTheorically count value should be %ld\n", 2000000ul);
	printf("After implementation of semaphore, ");
	printf("count = %ld\n", count);
	sem_destroy(&sem);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	Count increment function
///		increment count variable by 3000 for one time function execution
///@param :	void *: pointer to the argument data
///@return:	void *: pointer to return status
/////////////////////////////////////////////////////////////////////////////*/
void *countIncrement(void *arg)
{
	unsigned long i;
	/* semaphore accquired */
	if (sem_wait(&sem)) { /* wait */
		printf("Error: sem wait fail\n");
		pthread_exit(NULL);
	}
	printf("Thread %ld strat updating, global count = %ld\n",
		*(pthread_t *) arg, count);
	/* increment the global variable */
	for (i = 0; i < 1000000; i++)
		count += 1;
	printf("Thread %ld stop updating, global count = %ld\n",
		*(pthread_t *) arg, count);
	/* release the semaphore */
	if (sem_post(&sem)) { /* post */
		printf("Error: sem wait fail\n");
		pthread_exit(NULL);
	}
	/*thread exit */
	pthread_exit(NULL);
}

/* Output:
First thread is created
Thread id for the first thread: 140402096887552
Thread 140402096887552 strat updating, global count = 0
Second thread is created
Thread id for the second thread: 140402096887552
Thread 140402096887552 stop updating, global count = 1000000
Thread 140402088494848 strat updating, global count = 1000000
Thread 140402088494848 stop updating, global count = 2000000

Theorically count value should be 2000000
After implementation of semaphore, count = 2000000
*/
