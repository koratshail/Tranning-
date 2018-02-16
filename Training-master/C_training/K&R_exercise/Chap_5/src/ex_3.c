/*Chap_5/Ex_3
@Aim:	Write function expand(s1,s2) that expands shorthand notations like a-z
	in the string s1 into the equivalent complete list abc...xyz in s2.Allow
	for letters of either case and digits, and be prepared to handle cases
	like a-b-c and a-z0-9 and -a-z. Arrange that a leading or trailing - is
	taken literally.
@Author:Gaurang
@Date:	27 Sept 2017
*/

#include<stdio.h>
#include<stdlib.h>

void expnd(char *, char *);

int main(void)
{
	char *c, s[150] = {'\0'}; /* array = null */
	char t[150] = {'\0'};	/* array = null */
	printf("Enter string which contain short form\n");
	printf("For example\n");
	printf("short C-F form\n");
	printf(".................................\n");
	c = s;
	*c = ' ';
	c++;
	*c = getchar();
	while (*c != '\n') {
		++c;
		*c = getchar();
	}
	*c = ' ';
	expnd(s, t);
	printf("Output string:%s\n", t);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	check the input, find the short form and expand it
///@param :	s: input string with short form
		t: output string with expand short form
///@return:	void but stored string with full form in t
/////////////////////////////////////////////////////////////////////////////*/
void expnd(char *s, char *t)
{
	int i, j, k, n;
	i = j = k = 0;
	while (s[i]) {
		t[j] = s[i];
/* serch sort form using if condition and if found then expand it */
		if ((s[i] == ' ' && s[i+2] == '-' && s[i+4] == ' ') &&
(s[i+1] != s[i+3]) && ((('0' <= s[i+1] && '9' >= s[i+1]) && ('0' <= s[i+3]
&& '9' >= s[i+3])) || (('a' <= s[i+1] && 'z' >= s[i+1]) && ('a' <= s[i+3] &&
'z' >= s[i+3])) || ('A' <= s[i+1] && 'Z' >= s[i+1] && 'A' <= s[i+3] && 'Z' >=
s[i+3]))) {
			if (s[i+1] < s[i+3]) {
				n = s[i+3] - s[i+1];
				if (n > 1) {
					t[j++] = s[i];
					k = 0;
					while (n) {
						t[j] = s[i+1] + k;
						k++;
						n--;
						j++;
					}
					i = i + 2;
					j--;
				}
			} else {
				n = s[i+1] - s[i+3];
				if (n > 1) {
					t[j++] = s[i];
					k = 0;
					while (n) {
						t[j] = s[i+1] - k;
						k++;
						n--;
						j++;
					}
					i += 2;
					j--;
				}
			}
		}
		i++;
		j++;
	}
	t[j] = '\0';
	return;
}

/*Expected Output:
Source string: wsdf 0-9 fd
Output string: wsdf 0123456789 fd
*/
