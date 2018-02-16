/*Chap_7/Ex_4
@Aim:	Write the function strend(s,t) , which returns 1 if the string t
	occurs at the end of the string s , and zero otherwise.
@Author:gaurang
@Date:	03 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strend(char *, char *);

int main(void)
{
	char *s, *t;
	s = (char *) malloc(40);
	t = (char *) malloc(40);
	printf("Enter first string :");
	fgets(s, 40, stdin);
	printf("Enter second string:");
	fflush(stdin);
	fgets(t, 40, stdin);
	if (strend(s, t))
		printf("String found at the end\n");
	else
		printf("String is neither found nor located at end of \
first string\n");
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	Find the string t occurs at the end of the string s or not.
///@param :	s: string1
		t: string2 which is to be find at end of string1 s
///@return:	return 1 if string found at end
		return 0 if string not found
/////////////////////////////////////////////////////////////////////////////*/
int strend(char *s, char *t)
{
	int n, k, i;
	n = strlen(s) - 2;
	i = k = strlen(t) - 2;
	i++;
	while (i--) {
		if (!(*(s+n) == *(t+k)))
			return 0;
		n--;
		k--;
	}
	return 1;
}

/*EXPECTED OUTPUT
Exmp 1.	Enter first string :C is a programming language
	Enter second string: language
	String found at the end
Exmp 2.	Enter first string :C is a programming language
	Enter second string:1language
	String is neither found nor located at end of first string
*/
