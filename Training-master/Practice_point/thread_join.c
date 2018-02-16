/* pthread exit and pthread_join void pointer 
 *
 *  In pthread_exit : ret is an input parameter.
 *		      You are simply passing the address of a variable to the function.
 *
 *  In pthread_join : ret is an output parameter.
 *		      You get back a value from the function. Such value can, for example, be set to NULL.
 */

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<string.h>

void* thread_function(void *arg)
{
	char *a = malloc(10);
	strcpy(a,"hello world\n");
	pthread_exit((void*)a);
}

int main(void)
{
	pthread_t thread_id;
	char *b;

	pthread_create (&thread_id, NULL,&thread_function, NULL);

	/* reciving one pointer value so to use that we need double pointer */ 
	pthread_join(thread_id,(void**)&b);

	printf("b is %s",b); 
	free(b); 
}
