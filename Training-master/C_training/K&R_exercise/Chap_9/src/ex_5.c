/*Chap_9/Ex_5

@Aim	:Rewrite the postfix calculator of Chapter 4 to use scanf and/or sscanf
	to do the input and number conversion.
@Author	: gaurang
@Date	: 09 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h> /* for atof() */

#define MAXOP 100 /* max size of operand or operator */
#define MAXVAL 100 /* maximum depth of value stack */

int sp = 0; /* stack pointer */
double val[MAXVAL]; /* value stack */

void push(double f);
double pop(void);

/* reverse Polish calculator */
int main(void)
{
	char *c;
	char s[MAXOP], buf[MAXOP];
	double a = 0, op2;
	char e = '\0';
	printf("Enter postfix expression\n");
	printf("For example: 2 5 +\n");
	while (scanf("%s%c", s, &e) == 2) {
		if (sscanf(s, " %lf", &a) == 1) /* is it a number */
			push(a);
		else if (sscanf(s, "%s", buf) == 1) {
			for (c = buf ; *c; c++) {
				switch (*c) {
				case '+':
					push(pop() + pop());
					break;
				case '-':
					op2 = pop();
					push(pop() - op2);
					break;
				case '*':
					push(pop() * pop());
					break;
				case '/':
					op2 = pop();
					if (op2 != 0.0)
						push(pop() / op2);
					else
						printf("error: zero divisor\n");
					break;
				case '\n':
					printf("break\n");
					break;
				default:
					printf("Unknown command\n");
					printf("Kindly enter right command\n");
					return 0;
				}
			}
		}
		if (e == '\n') {	/* print result */
			if (sp == 1) {
				printf("Calculated postfix value: %f\n", pop());
				return 0;
			} else {
				sp = 0;
				printf("Wrong expression entered\n");
			}
		}
	}
	return 0;
}


/*/////////////////////////////////////////////////////////////////////////////
///@brief :	store value on the stack
///@param :	double d: number to be store on the stack
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
///@brief :	take value from the stack
///@param :	void
///@return:	double: number
/////////////////////////////////////////////////////////////////////////////*/
double pop(void)
{
	if (sp > 0) {
		sp--;
		return val[sp];
	} else
		return 0.0;
}

/* Output example
Enter post fix expression:
	5 20 20 + -
	Calculated postfix value: -35.000000
*/
