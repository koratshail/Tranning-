/*Chap_6/Ex_11
@Aim	:Modify getop so that it doesn't need to use ungetch. Hint: use an
	internal static variable.
@Author	: gaurang
@Date	: 29 Sep 2017
*/

#include<stdio.h>
#include<stdlib.h> /* for atof() */
#include<ctype.h> /* for isgigit() */

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */
#define MAXVAL 100 /* maximum depth of val stack */

int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

double pop(void);
void push(double f);

int getop(char *s);
int getch(void);

/* reverse polish calculator */
int main(void)
{
	int type;
	double op2, op1;
	char s[MAXOP];
	printf("Enter post script expession\n");
	printf("For example: 2 3 + 5 *\n");
	while ((type = getop(s)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			op1 = pop();
			op1 = op1-op2;
			push(op1);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
				break;
		case '\n':
			if (sp == 1)
				printf("Calculated value: %f\n", pop());
			else
				printf("Wrong expression entered\n");
			return 0;
		default:
			printf("Error: unknown command: %s\n", s);
			printf("Enter valid input\n");
			return 0;
			break;
		}
	}
	return 0;
}

/* getop */
#define NUMBER '0'
/*/////////////////////////////////////////////////////////////////////////////
///@brief :	get char from postfix expression entered by user;
		check each char and return accordingly
///@param :	s: buffer to store number or char
///@return:	return 0 if number is found and number is stored in string s
		otherwise return character
/////////////////////////////////////////////////////////////////////////////*/
int getop(char *s)
{
	int c;
	static int buf = EOF;
	if (buf != EOF && buf != ' ' && buf != '\t'
&& !isdigit(buf) && buf != '.') {
		c = buf;
		buf = EOF;
		return c;
	}
/*	remove space and get a char from screen */
	if (buf == EOF || buf == ' ' || buf == '\t')
		while ((*s = c = getch()) == ' ' || c == '\t')
			;
	else
		*s = c = buf;
	buf = EOF;
	*(s + 1) = '\0';	/*	after char put null char */
/*aftergetting char check whether it is a number or not and return accordingly*/
	if (!isdigit(c) && c != '.')
		return c;       /* not a number */
	if (isdigit(c))     /* collect integer part */
		while (isdigit(*++s = c = getch()))
			;
	if (c == '.')       /* collect fraction part */
		while (isdigit(*++s = c = getch()))
			;
	*++s = '\0';
	buf = c;
	return NUMBER;
}

/* getch */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp;
/*/////////////////////////////////////////////////////////////////////////////
///@brief :	get char from user
///@param :	void
///@return:	return character read from screen
/////////////////////////////////////////////////////////////////////////////*/
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/* stack */
/*/////////////////////////////////////////////////////////////////////////////
///@brief :	push value onto value stack
///@param :	double f : data to be put onto the stack
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	return top value from stack
///@param :	void
///@return:	double: data to return from stack
/////////////////////////////////////////////////////////////////////////////*/
double pop(void)
{
	if (sp > 0) {
		sp--;
		return val[sp];
	} else
		return 0.0;
}

/*
Enter post script expession
For example: 2 3 + 5 *
6 6 * 10 -
Calculated value: 26.000000
*/
