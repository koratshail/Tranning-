/*Chap_7/Ex_13
@Aim:	Write the program tail, which prints the last n lines of its input.
	By default, n is 10, say, but it can be changed by an optional argument,
	so that  tail -n prints the last n lines.
	The program should behave rationally no matter how unreasonable input or
	the value of n.
	Write the program so it makes the best use of available storage; lines
	should be stored as in the sorting program of Section 5.6, not in a two-
	dimensional array of fixed size.
@Author:gaurang
@Date:	04 Oct 2017
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAXLINES 5000 /* max lines to be sorted */
#define MAXLEN 500 /* max length of any input line */

char *lineptr[MAXLINES]; /* pointers to text lines */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines, int ln);
int in_val(int argc, char *s1, int max); /* validation of command line argmnt */
int getline_(char *, int);

int main(int argc, char *argv[])
{
	int nlines; /* number of input lines read */
	int ln = 10;
	ln = in_val(argc, argv[1], MAXLINES);
	printf("Enter data into lines to store:\n");
	printf("Press cntr+D in new line to stop the storing operation\n");
	nlines = readlines(lineptr, MAXLINES);
	if (nlines >= 0) {
		if (nlines < ln)
			ln = nlines;
		printf("\nlast %d lines as below:\n", ln);
		writelines(lineptr, nlines, ln);
		return 0;
	}
	printf("error: input too big to sort\n");
	return 1;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	Check and validate argument given by string s1
///@param :	argc: number of argumets passed from command line
		s1: string which has second command line argument
		max: maximum lines in a page
///@return:	if the command line argument is valid then return number n given
		by agument in string s1
		if command line argument not valid then return default number 10
/////////////////////////////////////////////////////////////////////////////*/
int in_val(int argc, char *s1, int max)
{
	int flag = 0, ln;
	char *s;
	s = s1;
	if (argc == 2) {
		if (*s++ == '-') {
			while (*s) {
				if (!isdigit(*s++)) {
					flag = 1;
					break;
				}
			}
		} else
			flag = 1;
	} else
		flag = 1;
	if (flag) {
		printf("Either no command line argument or wrong format\n");
		printf("Kindly enter command to print last n lines \
as:\n./ex_13.out -n\nDefault last 10 lines print option selected\n");
		printf(".............................\n");
		return 10;
	} else {
		ln = atoi((++s1));
		if (ln > max) {
			printf("Exceed the maximum line (5000)\n");
			printf("Default last 10 line will be printed\n");
			printf(".............................\n");
			ln = 10;
		}
		return ln;
	}
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	read input lines from stdin
///@param :	char *lineptr[] : array to store line pointer
///		int maxlines: maximum number of lines that allow to read
///@return:	int: number of lines that readed
/////////////////////////////////////////////////////////////////////////////*/
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines = 0;
	while ((len = getline_(line, MAXLEN)) > 0) {
		p = (char *) malloc(len);
		if (nlines >= maxlines || (p == NULL))
			return -1;
		else {
			line[len-1] = '\0'; /* delete newline */
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	write lines to stdout
///@param :	char *lineptr[] : array of store line pointer
///		int nlines: number of lines to write
///@return:	void
/////////////////////////////////////////////////////////////////////////////*/
void writelines(char *lineptr[], int nlines, int ln)
{
	int i;
	for (i = nlines - ln; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

/*/////////////////////////////////////////////////////////////////////////////
///@brief :	read a line into s, return length
///@param :	char s[]: store line string
///		int lim: maximum length of line
///@return:	int: legth of line readed
/////////////////////////////////////////////////////////////////////////////*/
int getline_(char s[], int lim)
{
	int c, i;
	c = getchar();
	for (i = 0; i < lim && (c != EOF) && c != '\n'; ++i) {
		s[i] = c;
		c = getchar();
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

/*Expected output:
	./ex_13.out -3
	Enter data into lines to store:
	Gandhinagar is a capital of Gujarat
	Banglore is a capital of Karnataka
	Jaipur is a capital of Rajasthan
	Mumbai is a capital of Maharastra

	last 3 lines as below:
	Banglore is a capital of Karnataka
	Jaipur is a capital of Rajasthan
	Mumbai is a capital of Maharastra
*/
