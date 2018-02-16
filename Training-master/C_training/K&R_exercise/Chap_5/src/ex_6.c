/*Chap_5/Ex_6
@Aim:	Write a version of itoa that accepts three arguments instead of two.
	The third argument is a minimum field width; the converted numbermust be
	padded with blanks on the left if necessary to make it wide enough.
@Author:gaurang
@Date:	27 Sep 2017
*/

#include<stdio.h>
#include<string.h>

int inttoasc(int num, char *s, int size);

int main(void)
{
	int w, num, p;
	printf("Enter decimal number:");
	if (!scanf("%d", &num)) {
		printf("Int type number is not enter\n");
		return 0;
	}
	printf("Enter buffer width to store ASCII string:");
	if (!(scanf("%d", &w))) {
		printf("Enter input width isnot valid\n");
		return 0;
	}
	char s[w];
	printf("Decimal number is %d and allocated width is %d\n", num, w);
	p = inttoasc(num, s, w+1);	/* integer to ascii converter function*/
	if (!p) {
		printf("Buffer width is small to store the enter number\n");
		return 0;
	}
	printf("Converted ASCII value with * padded with left side is:%s\n",
		s);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	convert integer to ASCII number with padded space
///@param :	num: integer number
		s: output buffer for the converted output
		size: size of buffer
///@return:	void but stored converted number into  string s
/////////////////////////////////////////////////////////////////////////////*/
int inttoasc(int num, char *s, int size)
{
	int n, k;
	sprintf(s, "%d", num);
	n = strlen(s);
	if (size <= n)
		return 0;
	k = n;
	num = size;
	s[num - 1] = '\0';
	while (n) {
		s[num - 2] = s[n - 1];
		num--;
		n--;
	}
	n = size - k - 1;
	num = 0;
	while (n--)
		s[num++] = '*';/* instead of '*' use space*/
	return 1;
}

/*
Enter decimal number:128
Enter buffer width to store ASCII string:5
Decimal number is 128 and allocated width is 5
Converted ASCII value with space padded with left side is:**128
*/
