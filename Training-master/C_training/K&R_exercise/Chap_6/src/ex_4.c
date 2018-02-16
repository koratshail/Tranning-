/*Chap_6/Ex_4
@Aim:	Add commands to print the top element of the stack without popping, to
	duplicate it, and to swap the top two elements. Add command to clear the
	stack.
@Author:gaurang
@Date:	28 Sept 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define STACK_SIZE 50

void push(int data);
int pop(void);
void clr_stck(void);
void dis(void);
void dup(void);
void swap(void);

int stack[STACK_SIZE];
int sp = 0;

int main(void)
{
	int data, selection, flag = 0;
	char s[10], *c = NULL;
	while (1) {
		printf("Permitted operations:\n");
		printf("1. PUSH\n");
		printf("2. POP\n");
		printf("3. Clear the stack\n");
		printf("4. Print the stack elements from bottom to top\n");
		printf("5. Duplicate top element of the stack\n");
		printf("6. Swap the top two element of the stack\n");
		printf("0. Exit\n");
		printf("................................................\n");
		printf("Enter your choice of operation: ");
		scanf("%s", s);
		c = s;
		while (*c) {
			if (!isdigit(*c++)) {
				printf("Wrong input entered\n");
				printf("Only int type input is valid\n");
				flag = 1;
			}
		}
		if (flag) {
			flag = 0;
			continue;
		}
		selection = atoi(s);
		if (!selection)
			break;
		switch (selection) {
		case 1:
			printf("Enter data to push:\n");
			scanf("%d", &data);
			push(data);
			printf("%d data is pushed on stack\n", data);
			break;
		case 2:
			data = pop();
			if (data >= 0)
				printf("POP data is %d\n", data);
			break;
		case 3:
			clr_stck();
			printf("Stack is cleared\n");
			break;
		case 4:
			dis();
			break;
		case 5:
			dup();
			printf("Top element is duplicated\n");
			break;
		case 6:
			swap();
			printf("Top two elements are swapped\n");
			break;
		}
		printf("................................................\n");
	}
	return 0;
}
void push(int data)
{
	if (sp < STACK_SIZE) {
		stack[sp++] = data;
	} else
		printf("Stack is overflow and %d data is not stored on stack\n",
			data);
}
int pop(void)
{
	if (sp)
		return stack[--sp];
	else
		printf("Stack is under flow\n");
	return -1;
}
void clr_stck(void)
{
	sp = 0;
}
void dis(void)
{
	if (sp) {
		int s;
		s = 0;
		while (s != sp) {
			printf("Data at %d position is %d\n", s, stack[s]);
			s++;
		}
	} else
		printf("stack is empty\n");
}
void dup(void)
{
	if (sp && sp < STACK_SIZE) {
		int data = pop();
		push(data);
		push(data);
	} else
		printf("Stack is either empty or overflow\n");
}
void swap(void)
{
	if (sp > 1) {
		int data1 = pop();
		int data2 = pop();
		push(data1);
		push(data2);
	} else
		printf("Stack have insufficient data to swap\n");
}

/*Expected Output:
Permitted operations:
1 for PUSH op
2 for POP op
3 for clearing the whole stack
4 for printing stack elements from top to bottom
5 for duplicationg top element
6 for swapping top two element

0 for exit
............................................
Enter your choice of operation: 1
PUSH operation:
enter data:
11
................................................
Enter your choice of operation: 1
PUSH operation:
enter data:
22
................................................
Enter your choice of operation: 1
PUSH operation:
enter data:
33
................................................
Enter your choice of operation: 4
Display operation:
Enter 0 for ascending order & 9 for descending order:0
Data at 0 position is 11
Data at 1 position is 22
Data at 2 position is 33
................................................
Enter your choice of operation: 6
Swapping top two element operation
................................................
Enter your choice of operation: 4
Display operation:
Enter 0 for ascending order & 9 for descending order:0
Data at 0 position is 11
Data at 1 position is 33
Data at 2 position is 22
................................................
Enter your choice of operation: 0
*/
