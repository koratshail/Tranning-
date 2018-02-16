/*Chap_4/Ex_5
@AIM	:Write the function any(s1,s2), which returns the first location in the
	string s1 where any character from the string s2 occurs, or -1 if s1
	contains no characters from s2. (The standard library function strpbrk
	does the same job but returns a pointer to the location).
@Author:Gaurang
@Date:	26 Sept 2017
*/

#include<stdio.h>
#include<string.h>

char *strbrk(char *s1, char *s2);

int main(void)
{
	char s1[20], s2[20], *ret = s1;
	printf("Enter first string  : ");
	fgets(s1, sizeof(s1), stdin);
	printf("Enter second string : ");
	fgets(s2, sizeof(s2), stdin);
	ret = strbrk(s1, s2);
	if (ret == NULL) {
		printf("No character common in both strings\n");
		return 0;
	}
	printf("output string: %s", ret);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :print sting s1 from the first common char of string s2
///@param :char s1[]: input string 1, char s2[]:input string 2
///@return : return addr of first char mach in string s1
/////////////////////////////////////////////////////////////////////////////*/
char *strbrk(char *s1, char *s2)
{
	int i, j, flag;
	char *ret = s1;
	for (i = 0; s1[i] != '\0'; ++i) {
		flag = 0;
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s1[i] == s2[j]) {
				flag = 1;
				ret = s1 + i;
				break;
			}
		}
		if (flag)
			break;
	}
	if (!flag)
		return ret;
	return NULL;
}

/*
@Expected Output
Enter String s1: gujarat
Enter string s2: ahmedabad
Output string s3: arat
*/
