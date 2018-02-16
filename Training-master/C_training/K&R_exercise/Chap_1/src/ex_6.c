/*Chap_6/Ex_6
@Aim:	 Verify that the expresion getchar() != EOF is 0 or 1.
@Author: Gaurang
@Date:	 25 Sep 2017
*/

#include<stdio.h>

int main(void)
{
	printf("Value of EOF is %d\n", EOF);
	printf("Enter a character\n");
	printf("getchar() function return ASCII value of enter character: %d\n",
			getchar());
	printf("Return value of expresion getchar()!=EOF is %d\n",
			getchar() != EOF);
	return 0;
}
/*Expected Output:
Value of EOF is -1
Enter a character: a
return value of getchar() : 65
return value of expression getchar() != EOF is 1

if enter char is 'cntrl+D' then its ASCII value is -1 and
expression result will be 0.
*/
