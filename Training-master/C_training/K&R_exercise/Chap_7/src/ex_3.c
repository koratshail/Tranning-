/*Chap_7/Ex_3
@Aim:	Write a pointer version of the function strcat that we showed in
	Chapter 2: strcat(s,t) copies the string t to the end of s.
@Author:gaurang
@Date:	03 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h>

void strn_cat(char *, char *);

int main(void)
{
	char *s, *t;
	s = (char *) malloc(50);
	t = (char *) malloc(20);
	printf("Enter first string :");
	fflush(stdin);
	fgets(s, 50, stdin);
	printf("Enter second string:");
	fflush(stdin);
	fgets(t, 20, stdin);
	strn_cat(s, t);
	printf("Concated output String: %s", s);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	copy strint t to the end of string s
///@param :	s: string1
		t: string2 which is to be copied to end f string1
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void strn_cat(char *s, char *t)
{
	while (*s++)
		;
	s--;
	s--;
	while (*t)
		*s++ = *t++;
	*s = '\0';
	return;
}

/*Expected Output:
	Enter first string :C is the widely used
	Enter second string: in linux kernel
	Concated output String: C is the widely used in linux kernel
*/
