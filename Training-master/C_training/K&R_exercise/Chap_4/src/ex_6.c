/*Chap_4/Ex_6
@Aim:	Write a function setbits(x,p,n,y) that returns x with the n bits that
	begin at position p set to the rightmost n bits of y, leaving the other
	bits unchanged.
@Author:Gaurang
@Date:	26 Sept 2017
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int setbits(int x, int p, int n, int y);
int val(char *s);
int xtoi(char *s);

int main(void)
{
	char *s1, *s2;
	s1 = (char *)malloc(9);
	s2 = (char *)malloc(9);
	char *c, s[10];
	unsigned int d;
	unsigned int x = 0x44332211;	/* input X */
	unsigned int y = 0x11223344;	/* input Y */
	int p = 12, n = 8;	/* p>n always */
	printf("Bit position P must be greater then number of bits n to \
replaced\n");
	printf("Enter data for x and y in hex, note that use lower case\n");
	printf("...........................................................\n");
	printf("For example:\n");
	printf("Input:\n");
	printf("Bit position p   : %d\n", p);
	printf("number of bits n : %d\n", n);
	printf("x in hex         : %x\n", x);
	printf("y in hex         : %x\n", y);
	d = setbits(x, p, n, y);
	printf("Output:\n");
	printf("d in hex         : %x\n", d);
	printf("...........................................................\n");
	printf("Enter x:");
	scanf("%s", s1);
	x = val(s1);
	if (x == 0xffffffff) {
		printf("Wrong input entered, note that use hex \
character in lower case\n");
		return 0;
	}
	printf("Enter y:");
	scanf("%s", s2);
	y = val(s2);
	if (y == 0xffffffff) {
		printf("Wrong input entered\n");
		return 0;
	}
	printf("Enter bit position P :");
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			return 1;
		}
	}
	p = atoi(s);
	if (p > 32 && p < 0) {
		printf("Enter wrong value of bit position\n");
		return 0;
	}
	printf("Enter number of bits to be replaced in %x from \
position %d :", x, p);
	scanf("%s", s);
	c = s;
	while (*c) {
		if (!isdigit(*c++)) {
			printf("Wrong input entered\n");
			return 1;
		}
	}
	n = atoi(s);
	if (n > p || n > 32 || n < 0) {
		printf("Wrong value of number of bits to replaced\n");
		return 0;
	}
	printf("Input:\n");
	printf("Bit position p   : %d\n", p);
	printf("number of bits n : %d\n", n);
	printf("x in hex         : %x\n", x);
	printf("y in hex         : %x\n", y);
	d = setbits(x, p, n, y);
	printf("Output:\n");
	printf("d in hex         : %x\n", d);
	free(s1);
	free(s2);
	return 0;
}


/*/////////////////////////////////////////////////////////////////////////////
///@brief :replace n bits of X from position p with last n bits of y.
///@param :	x:number from which n bits from position p to change
		p:bit position from where n bits of x to replace
		y:number whose last n bits are used to replace in X
		n:number of bits to replace
///@return : return number which have replace the n bits from postion p
/////////////////////////////////////////////////////////////////////////////*/
int setbits(int x, int p, int n, int y)
{
	int a, b, c, d;
	a = ~(~0<<n) & y;	/* extract last n bit from y */
	b = (~0<<p) | (~(~0<<(p-n)));	/* generate pattern like 0xfff0f */
	c = x & b;			/* clear n bits of x */
	d = c | (a << (p - n));
	return d;

}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:check whether input hex string is valid or not. Also
//		perform hex to integer conversion
///@param	:input string for x and y
///@return 	:return int value of x and y if input valid otherwise return -1
/////////////////////////////////////////////////////////////////////////////*/
int val(char *s)
{
	int flag = 0, ret = 0, n;
	char *c = s;
	n = strlen(s);
	if (n > 8) {
		printf("Input is too large\n");
		flag = 1;
	}
	while (*c) {
		if (!((('a' <= *c) && ('f' >= *c)) || (('0' <= *c) && \
('9' >= *c)))) {
			flag = 1;
			break;
		}
		c++;
	}
	if (flag)
		return -1;
	ret = xtoi(s);
	return ret;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:convert hex string to integer number
///@param	:s:input hex string
///@return	:return int value
/////////////////////////////////////////////////////////////////////////////*/
int xtoi(char *s)
{
	int n, a;
	int m = 1, sum = 0;
	char *c;
	n = strlen(s);
	while (n) {
		c = s + n - 1;
		n--;
		if (*c >= 'a')
			a = *c - 'a' + 10;
		else
			a = *c - '0';
		sum = sum + a * m;
		m = m * 16;
	}
	return sum;
}
