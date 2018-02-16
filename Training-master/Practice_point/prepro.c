/*
 *	To run: gcc ./a.out -E
 *	Check the output	
 */

#include<stdio.h>
#define IND PAK
#define PAK 10
//#define int 30
int main(void)
{
	printf("Value %d\n", IND);
//	printf("INT %d\n", char);
	printf("File %s\n", __FILE__);

   printf("Current Date :%s\n", __DATE__ );
   printf("Current Time :%s\n", __TIME__ );
   printf("Line Number :%d\n", __LINE__ );
	return 0;
}
