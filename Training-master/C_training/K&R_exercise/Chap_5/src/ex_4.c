/*Chap_4/Ex_4
@Aim:	In a two's complement number representation, our version of itoa does
	not handle the largest negative number, that is, the value of n equal to
	-(2 to the power (wordsize - 1)). Explain why not. Modify it to print
	that value correctly regardless of the machine on which it runs.
@Author:Gaurang
@Date:	27 Sept 2017
*/

#include<stdio.h>


void inttoasc(int num, char *t, int size);

int main(void)
{
	int num;
	char t[20];
	num = -2147483648;/* 2^32-1 number which is not handle by itoa fun*/
	inttoasc(num, t, sizeof(t));
	printf("Maximum negative decimal number is %d\n", num);
	printf("Converted ASCII string for the maximum negative number is %s\n",
		t);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	convert interger to ASCII
///@param :	num: integer number
		t: output ASCII string
		size: string size
///@return:	void but stored string with ASCII conversion into t
/////////////////////////////////////////////////////////////////////////////*/
void inttoasc(int num, char *t, int size)
{
	snprintf(t, size, "%d", num);
}

/*Expected Output
Maximum negative decimal number is -2147483648
Converted ASCII string for the maximum negative number is -2147483648
*/
