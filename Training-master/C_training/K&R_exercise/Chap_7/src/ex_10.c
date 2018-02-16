/*Chap_7/Ex_10
@Aim:	Write the program expr, which evaluates a reverse Polish expression
	from the command line, where each operator or operand is a separate
	argument.
	For example:	expr 2 3 4 + *
			evaluates 2 x (3+4).
@Author:gaurang
@Date:	04 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define STACK_SIZE 100

double stack[STACK_SIZE];
int sp = 0;

void push(double data);
double pop(void);
void clr_stck(void);
void dis(void);

int main(int argc, char *argv[])
{
	double op2;
	int i = 1;
	if (argc < 2) {
		printf("This is a command line argument program\n");
		printf("Kindly enter the postfix expression to get result\n");
		printf("For example: 2 3 + 10 x 5 /\n");
		printf("Also note that for multiplication use 'x' not '*'\n");
		return 0;
	} else {
		while (i != argc) {
			switch (*argv[i]) {
			case '\0':
				printf("Null occur\n");
				break;
			case '*':
				printf("Kindly renter the expression \
using 'x' instead of '*' for multiplication\n");
				return 0;
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				push(atof(argv[i]));
				break;
			case '+':
				push(pop() + pop());
				break;
			case 'x':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			default:
				printf("Error: unknown command %s\n", argv[i]);
				return 0;
				break;
			}
			i++;
		}
	}
	if (sp != 1) {
		printf("invalid postfix expression you have \
entered\n");
		printf("Also note that for multiplication use 'x' not '*'\n");
	} else {
		i = 1;
		printf("Calculated value for the postfix expression\n");
		while (i != argc) {
			printf("%s ", argv[i]);
			i++;
		}
		printf("= %f\n", pop());
	}
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	store data at top position in stack
///@param :	double data: data to store
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void push(double data)
{
	if (sp < STACK_SIZE) {
		stack[sp++] = data;
	} else
		printf("Stack is overflow and %f data is not stored onstack\n",
data);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	get data from top position of stack
///@param :	void
///@return:	return data from top position
/////////////////////////////////////////////////////////////////////////////*/
double pop(void)
{
	if (sp)
		return stack[--sp];
	else
		printf("Stack is under flow\n");
	return -1;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	clear stack
///@param :	void
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void clr_stck(void)
{
	sp = 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	display stack data from top to bottom
///@param :	void
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void dis(void)
{
	if (sp) {
		int s;
		s = sp;
		while (s--)
			printf("Data at %d position is %f\n", s, stack[s]);
	} else
		printf("stack is empty\n");
	return;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	duplicate top position data and pit again at top of stack
///@param :	void
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void dup(void)
{
	if (sp && sp < STACK_SIZE) {
		int data = pop();
		push(data);
		push(data);
	} else
		printf("Stack is either empty or overflow\n");
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	swap two position in stach
///@param :	void
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void swap(void)
{
	if (sp > 1) {
		double data1 = pop();
		double data2 = pop();
		push(data1);
		push(data2);
	} else
		printf("Stack have in less data\n");
}
/*Expeted Output
	./ex_10.out 5 10 + 2 x
	Calculated value for the postfix expression
	5 10 + 2 x = 30.000000
*/
