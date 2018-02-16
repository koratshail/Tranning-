/*Chap_5/Ex_5
@Aim:	Write the function itob(n,s,b) that converts the integer n into
	a base b character representation in the string s.
	In particular, itob(n,s,16) formats n as a hexadecimal integer in s.
@Author:Gaurang
@Date:	27 Sept 2017
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void itob(int num, char *strng, int base);
void strev(char *s, int n);

int main(void)
{
	unsigned int num, bs;
	char t[20];
	char s[20];	/* to take number from user */
	char *c = NULL;
	printf("Enter decimal number:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Enter number isn't int type\n");
			return 1;
		}
	}
	num = atoi(s);
	printf("Enter base for the conversion:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Enter number isn't int type\n");
			return 1;
		}
	}
	bs = atoi(s);
	itob(num, t, bs);
	printf("integer number: %d\n", num);
	printf("Converted number with base %d is %s\n", bs, t);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	convert decimal number to equivalent number of given base
///@param :	num: integer number
		s: output buffer for the converted output
		b: base value
///@return:	void but stored converted number into  string s
/////////////////////////////////////////////////////////////////////////////*/
void itob(int num, char *s, int b)
{
	int r, i = 0;
	while (num) {
		r = num % b;
		num /= b;
		if (r < 10)
			s[i++] = r + '0';
		else
			s[i++] = r + 'a' - 10;
	}
	s[i] = '\0';
	strev(s, i);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	reverse the string
///@param :	s: input string
		n: size of string
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void strev(char *s, int n)	/* string reverse function*/
{
	int i, k = 0;
	char c;
	i = n / 2;
	while (i) {
		c = s[k];
		s[k] = s[n-1];
		s[n-1] = c;
		n--;
		i--;
		k++;
	}
}
/*Expected output
Enter decimal number:126
Enter base for the conversion:2
integer number: 126
Converted number with base 2 is 1111110
*/
