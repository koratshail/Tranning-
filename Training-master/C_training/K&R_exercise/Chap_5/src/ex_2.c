/*Chap_5/Ex_2
@Aim	:Write a function escape(s,t) that converts characters like newline and
	tab into visible escape sequences like \n and \t as it copies the string
	t to s. Use a switch . Write a function for the other direction as well,
	converting escape sequences into the real characters.
@Author	: Gaurang
@Date	: 27 Sept 2017
*/

#include<stdio.h>
#include<string.h>

#define TRUE 1
#define FALSE 0

void escape(char s[], char t[]);
void unescape(char *, char *);

int main(void)
{
	char t[100]; /* input string for escape() conversion */
	char c = 'a';
	char s[100];	/* output buffer for escape() */
	char p[100];	/* output buffer for unescape() */
	int i = 0;
	printf("Enter string with escape charaters like tab, new line, etc\n");
	printf("To exit press CNTR+D\n");
	while (c != EOF) {
		c = getchar();
		t[i++] = c;
	}
	i--;
	t[i] = '\0';
	escape(s, t);
	printf("Output string with escape character is: %s\n", s);
	unescape(p, s);
	printf("Output string with unescape character is:\n%s\n", p);
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	search any escape code for new line, tab, etc and replace it
		with character
///@param :	t: input string with escape sequence
		s: string into which escape character stored
///@return:	void but stored string with escape char into s
/////////////////////////////////////////////////////////////////////////////*/
void escape(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (t[i] != '\0') {
		switch (t[i]) {
		case '\t':
				s[j] = '\\';
				++j;
				s[j] = 't';
				break;
		case '\n':
				s[j] = '\\';
				++j;
				s[j] = 'n';
				break;
		default:
				s[j] = t[i];
				break;
		}
		++i;
		++j;
	}
	s[j] = '\0';
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	converting escape sequences into the real characters
///@param :	t: input string which contain escape seq as a characters
		s: string into which escape seqence store
///@return:	void but stored string with escape char into s
/////////////////////////////////////////////////////////////////////////////*/
void unescape(char s[], char t[])
{
	int i, j;
	int slash;
	slash = FALSE;
	for (i = j = 0; t[i] != '\0'; ++i) {
		switch (t[i]) {
		case '\\':
			slash = TRUE;
			break;
		case 'n':
			if (slash) {
				s[j++] = '\n';
				slash = FALSE;
				break;
			}
		case 't':
			if (slash) {
				s[j++] = '\t';
				slash = FALSE;
				break;
			}
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';
}
/*Expected Output
Enter string with escape charaters like tab, new line, etc
abc
xyz	123
pqr
Output string with escape character is: abc\nxyz\t123\npqr\n

Output string with unescape character is: abc
xyz	123
pqr

*/
