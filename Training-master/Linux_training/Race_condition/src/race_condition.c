/*
@file:	race_condition.c
@Aim:	Write a program to demonstrate race condition using two posix thread
@Author:Gaurang
@Date:	18 Oct 2017
*/

#include<stdio.h>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>

unsigned long count; /* count value */

void *countIncrement(void *arg); /* count increment function */

int main(void)
{
	pthread_t t[2];
	/* first thread create: */
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
	printf("Thread id for the second thread: %ld\n", t[1]);
	/* thread join: wait for thread to complete it task */
	pthread_join(t[0], NULL);
	pthread_join(t[1], NULL);
	/* check count */
	if (count != 2000000) { /* count = 2000000 then race cond not occur */
		printf("\nTheorically count value = 2000000\n");
		printf("Due to race condition, ");
		printf("count value = %ld\n", count);
		return 0;
	}
	printf("Run the program again\n");
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief:	Count increment function
///		increment count variable by 300 for one time function execution
///@param :	void *: pointer to the argument data
///@return:	void *: pointer to return status
/////////////////////////////////////////////////////////////////////////////*/
void *countIncrement(void *arg)
{
	pthread_t t = *(pthread_t *) arg;
	unsigned long i;
	printf("Thread %ld started updating, global count = %ld\n", t, count);
	for (i = 0; i < 1000000; i++)
		count += 1;
	printf("Thread %ld stopped updating, global count = %ld\n", t, count);
	pthread_exit(NULL);
}

/* Output:
First thread is created
Thread id for the first thread: 140092542453504
Thread 140092542453504 started updating, global count = 0
Second thread is created
Thread id for the second thread: 140092534060800
Thread 140092534060800 started updating, global count = 33092
Thread 140092534060800 stopped updating, global count = 1024322
Thread 140092542453504 stopped updating, global count = 1048659

Theorically count value = 2000000
Due to race condition, count value = 1048659
*/
