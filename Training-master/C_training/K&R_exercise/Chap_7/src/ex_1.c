/*Chap_7/Ex_1
@Aim:	As written, getint treats a + or - not followed by a digit as a valid
	representation of zero. Fix it to push such a character back on the
	input.
@Author:gaurang
@Date:	29 Sep 2017
*/

#include <ctype.h>
#include <stdio.h>

int getint(int *pn);
int getch(void);
void ungetch(int c);

int main(void)
{
	int a;
	a = -1;
	printf("Enter a number\n");
	if (getint(&a))
		printf("Number is %d\n", a);
	else
		printf("There is't a number in enter string\n");
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	get data from user and check whether it number enter or not
///@param :	&pn:addr of integer number where number will be store
///@return:	return 1 if enter string is a number
///		return 0 if enter string is not a number
/////////////////////////////////////////////////////////////////////////////*/
int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))   /* skip white space */
	;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		printf("Not a number\n");
		ungetch(c);    /* it's not a number */
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
		c = getch();
		if (!isdigit(c)) { /* + or - not followed by a digit */
			ungetch(c);    /* ungetch non-digit */
			ungetch(sign == 1 ? '+' : '-');  /* ungetch + or - */
			printf("Not a number\n");
			return 0;
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return 1;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	get char from stdin or buffer
///@param :	void
///@return:	return char from stdin or buffer
/////////////////////////////////////////////////////////////////////////////*/
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	put char into buffer
///@param :	ASCII value of char
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/*Expected output
enter string or number, output will be number if it is number otherwise tells to
enter number

example:1
Enter a number
-254
Number is -254

example:2
Enter a number
wccw
Not a number
There is't a number in enter string
*/
