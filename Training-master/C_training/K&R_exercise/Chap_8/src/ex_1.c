/*Chap_8/Ex_1
@Aim	:Our version of getword does not properly handle underscores, string
	constants, comments, or preprocessor control lines. Write a better
	version.

@Author	: gaurang
@Date	: 05 Oct 2017
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

struct key {        /* struct key for keyword to count */
	char *word;
	int count;
};

/* c keywords */
struct key keytab[] = {
			"auto", 0,
			"break", 0,
			"case", 0,
			"char", 0,
			"const", 0,
			"continue", 0,
			"default", 0,
			"do", 0,
			"double", 0,
			"else", 0,
			"enum", 0,
			"extern", 0,
			"float", 0,
			"for", 0,
			"goto", 0,
			"if", 0,
			"int", 0,
			"long", 0,
			"register", 0,
			"return", 0,
			"short", 0,
			"signed", 0,
			"sizeof", 0,
			"static", 0,
			"struct", 0,
			"switch", 0,
			"typedef", 0,
			"union", 0,
			"unsigned", 0,
			"void", 0,
			"volatile", 0,
			"while", 0
		};


#define NKEYS (sizeof(keytab) / sizeof(keytab[0])) /* number of c keywords */

int getword(char *, int);
int binsearch(char *, struct key *, int);
int getword(char *word, int lim);

/*count C keywords */
int main(void)
{
	int n, flag = 0;
	char word[MAXWORD];
	printf("This is a code to count how many times c keywords used");
	printf(" in C-code enter below by you\n");
	printf("To exit press CNTR+D in new line\n");
	while (getword(word, MAXWORD) != EOF)
		if (isalpha(word[0])) {
			n = binsearch(word, keytab, NKEYS);
			if (n >= 0)
				keytab[n].count++;
		}
	for (n = 0; n < NKEYS; n++)
		if (keytab[n].count > 0) {
			printf("Keyword  \"%s\" is used %d times\n",
				keytab[n].word, keytab[n].count);
			flag = 1;
		}
	if (!flag)
		printf("No C-Keyword used\n");
	return 0;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:search c keywords from tab array for a word
///@param	:char *word: word to search
///		struct key tab[]: array contain c key words
///		int n : size of tab array
///@return	:if keyword found then return its index of tab array else -1
/////////////////////////////////////////////////////////////////////////////*/
int binsearch(char *word, struct key tab[], int n)
{
	int cond;
	int low, high, mid;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low+high) / 2;
		cond = strcmp(word, tab[mid].word);
		if (cond < 0)
			high = mid - 1;
		else if (cond > 0)
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

/* getch */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;
/*/////////////////////////////////////////////////////////////////////////////
///@brief	:get char from user
///@param	:void
///@return	:return char read from user
/////////////////////////////////////////////////////////////////////////////*/
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief	:store char into buffer to reuse
///@param	:int c: char to store
///@return	:void
/////////////////////////////////////////////////////////////////////////////*/
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	get next word or character from input
///		also handle string constant, comments, preprocessor lines
///@param :	char word: buffer to store word or char from user
///		int lim: buffer size
///@return :	return first character of word
/////////////////////////////////////////////////////////////////////////////*/
int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	int flag = 0;
	char *w = word;
	while (isspace(c = getch()))	/* c get char */
		;
	if (c == EOF)
		return c;
	*w++ = c;
	/* preprocessor handle */
	if (c == '#')
		while (getch() != '\n')
			;
	/* underscore handle */
	if (c == '_') {
		for ( ; --lim > 0; w++) {
			c = getch();
			*w++ = c;
			if (c == ' ' || c == '\n') {
				ungetch(*w);
				break;
			}
		}
		*w = '\0';
		return word[0];
	}
	/* string constant handle */
	if (c == '"') {
		c = getch();
		while (c != '"')
			c = getch();
	}
	/* comment handle */
	if (c == '/') {
		c = getch();
		if (c == '/') {
			flag = 1;
			while (c != '\n')
				c = getch();
		} else
			ungetch(c);
		c = getch();
		if (c == '*') {
			flag = 1;
			c = getch();
			while (c != '*' || getch() != '/')
				c = getch();
		} else
			ungetch(c);
		if (!flag)
			c = w[0];
	}
	/* comment handle end */
	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for ( ; --lim > 0; w++) {
		*w = getch();
		if (*w == '_') {
		} else if (!isalnum(*w)) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

/* Output: */
/* char keyword count program */ /*
#include<stdio.h>
int main(void)
{
	char i_char, char_1;
	printf(" this char will not be counted\n");
	int i; // char not count
	i = (char) char_1;
	return 0;
}
Keyword  "char" is used 2 times
Keyword  "int" is used 2 times
Keyword  "return" is used 1 times
Keyword  "void" is used 1 times
*/
