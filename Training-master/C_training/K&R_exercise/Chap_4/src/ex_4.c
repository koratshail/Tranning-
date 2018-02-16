/*Chap_4/Ex_4
@Aim:	Write an alternate version of squeeze(s1,s2) that deletes each
	character in the string s1 that matches any character in the string s2.
@Author:Gaurang
@date:	26 Sept 2017
*/

#include<stdio.h>

void sqzee(char *s1, char *s2, char *s3);

int main(void)
{
	char s1[20], s2[20];
	char s3[sizeof(s1)];
	printf("Enter first string : ");
	fgets(s1, sizeof(s1), stdin);
	printf("Enter second string: ");
	fgets(s2, sizeof(s2), stdin);
	sqzee(s1, s2, s3);
	printf("........................\n");
	printf("First string : %s", s1);
	printf("Second string: %s", s2);
	printf("Output	     : %s\n", s3);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	Remov common chars from str1 and stor result in strn3
///@param :	char s1[]: input string 1, char s2[]:input string 2,
///		char s3[]: output squeezed string
///@return :	return void but stores squeezed string in s3[]
/////////////////////////////////////////////////////////////////////////////*/
void sqzee(char *s1, char *s2, char *s3)
{
	int i, j, k = 0, flag;
	for (i = 0; s1[i] != '\0'; i++) {
		flag = 0;
		for (j = 0; s2[j] != '\0'; j++) {
			if (s1[i] == s2[j]) {
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			s3[k++] = s1[i];
	}
	s3[k] = '\0';
}

/*
@Expected Output
Enter String s1: Gujarat
Enter string s2: Gandhinagar
Output string s3: ujt
*/
