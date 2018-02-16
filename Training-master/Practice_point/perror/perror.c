#include<stdio.h> /* in out header*/
#include<stdlib.h>
int main(void)
{
	int *ptr;
	ptr = (int *) malloc(-1);
	if (ptr == NULL) {
		error_handle(ptr, "Error in malloc");
	}
}
