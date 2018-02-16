/*Chap_6/Ex_12
@Aim	: Convert an integer into a string by calling a recursive routine.
@Author	: gaurang
@Date	: 29 Sep 2017
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

void itob(int num, char *strng, int base);
void strev(char *s, int n);

int main(void)
{
	int num, bs;
	char t[20];
	char *c = NULL, s[50];
	printf("Enter decimal number:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	num = atoi(s);
	printf("Enter base for the conversion:");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			printf("Only positive int type input is valid\n");
			return 0;
		}
	}
	bs = atoi(s);
	itob(num, t, bs);
	printf("integer number: %d\n", num);
	printf("Converted number with base %d is %s\n", bs, t);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	convert interger to equvalent number according to given base
///@param :	num: integer number
		s: output ASCII string
		b:base value
///@return:	void but stored string into s
/////////////////////////////////////////////////////////////////////////////*/
void itob(int num, char *s, int b)
{
	static int r, i;
	if (!num) {
		s[i] = '\0';
		strev(s, i);
		return;
	} else {
		r = num % b;
		num /= b;
		if (r < 10) {
			s[i] = r + '0';
			i++;
		} else {
			s[i++] = r + 'a' - 10;
		}
	}
	itob(num, s, b);	/* calling itself*/
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	string reverce
///@param :	s: string to be reverse
		n string size
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void strev(char *s, int n)       /* string reverse function*/
{
	int i, k = 0;
	char c;
	n = strlen(s);
	i = (n + 1) / 2;
	while (i) {
		c = s[k];
		s[k] = s[n - 1];
		s[n - 1] = c;
		n--;
		i--;
		k++;
	}
}

/*Expected Output:
Enter decimal number:123
Enter base for the conversion:2
integer number: 123
Converted number with base 2 is 1111011
*/
