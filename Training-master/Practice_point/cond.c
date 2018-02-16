#include<stdio.h>
int main(void)
{
	int a = 10, b = 12, i;
	/* BELOW LINE NOT WORK AS COND OPERATOR IS FOR EXPRESSION AND IT MUST NOT CONTAIN STATEMENTS */
//	a < b ? (i = 2, i++, printf("India\n"), return 0) : printf("Delhi\n");
	/* BELOW LINE WILL WORK */
	a < b ? (i = 2, i++, printf("India\n")) : printf("Delhi\n");
	printf("i = %d\n", i);
	return 0;
}
